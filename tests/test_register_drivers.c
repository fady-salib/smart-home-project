#include <assert.h>
#include <stdio.h>
#include "../master/MCAL/DIO/DIO_Program.c"
#include "../master/HAL/Step_Motor/SM_Prog.c"
#include "../master/MCAL/ADC/ADC_Private.h"
static u8 control, mux, low, high;
static volatile u8 *adc_control(void) { control &= (u8)~(1u << 6); return &control; }
#undef ADC_ADCSRA_REG
#undef ADC_ADMUX_REG
#undef ADC_ADCL_REG
#undef ADC_ADCH_REG
#define ADC_ADCSRA_REG (*adc_control())
#define ADC_ADMUX_REG mux
#define ADC_ADCL_REG low
#define ADC_ADCH_REG high
#include "../master/MCAL/ADC/ADC_Prog.c"
#include "../master/MCAL/TWI/TWI_Private.h"
static u8 twcr, twsr, twbr, twar, twdr;
#undef TWI_TWCR_REG
#undef TWI_TWSR_REG
#undef TWI_TWBR_REG
#undef TWI_TWAR_REG
#undef TWI_TWDR_REG
#define TWI_TWCR_REG twcr
#define TWI_TWSR_REG twsr
#define TWI_TWBR_REG twbr
#define TWI_TWAR_REG twar
#define TWI_TWDR_REG twdr
#include "../master/MCAL/TWI/TWI_Prog.c"
#include "../master/MCAL/USART/USART_Private.h"
static u8 udr, ucsra, ucsrb, ucsrc, ubrrl, ubrrh;
#undef USART_UDR_REG
#undef USART_UCSRA_REG
#undef USART_UCSRB_REG
#undef USART_UCSRC_REG
#undef USART_UBRRL_REG
#undef USART_UBRRH_REG
#define USART_UDR_REG udr
#define USART_UCSRA_REG ucsra
#define USART_UCSRB_REG ucsrb
#define USART_UCSRC_REG ucsrc
#define USART_UBRRL_REG ubrrl
#define USART_UBRRH_REG ubrrh
#include "../master/MCAL/USART/USART_Prog.c"

int main(void)
{
    u8 ddr[4]={0}, port[4]={0}, pin[4]={0};
    for (u8 i=0; i<4; ++i) {
        DIO_ArrpVu8_DDR[i]=&ddr[i]; DIO_ArrpVu8_PORT[i]=&port[i]; DIO_ArrpVu8_PIN[i]=&pin[i];
    }
    DIO_VoidSetPortValue(0, 0xA5); assert(port[0] == 0xA5 && ddr[0] == 0);
    DIO_VoidGetPinValue(0, 0, NULL); /* must ignore null output */
    ddr[3] = 0x02; port[3] = 0x01;
    SM_st motor = {.SM_Port=3, .Blue_Pin=4, .Pink_Pin=5, .Yellow_Pin=6, .Orange_Pin=7,
                   .Step_Type=Full_Step, .SM_Direction=Clock_Wise, .SM_No_of_Steps=256};
    Init_SM(&motor);
    assert(ddr[3] == 0xF2 && port[3] == 0x01); /* UART pins preserved; loop terminates >255 */
    u16 value=0;
    low=0xAA; high=2; mux=0xC0;
    ADC_StartConv(7, &value); assert(value == 0x2AA && (mux & 31) == 7);
    ADC_StartConv(0, &value); assert((mux & 31) == 0); /* old OR retained channel 7 */
    ADC_StartConv(9, &value); assert((mux & 31) == 0);
    TWI_voidMaterInit(1);
    twsr=0x08; TWI_voidStartCond(); assert(TWI_u8LastTransferOK());
    twsr=0x18; TWI_voidSendSlaveAddressWithWrite(0x50);
    assert(twdr == 0xA0 && !(twcr & (1u << TWI_TWCR_TWSTA_BIT)));
    twsr=0x28; TWI_voidMasterWriteData(0x34); assert(twdr == 0x34);
    twsr=0x58; twdr=0x5A; u8 byte=0;
    TWI_voidMasterReadData(&byte); assert(byte == 0x5A);
    assert(!(twcr & (1u << TWI_TWCR_TWEA_BIT))); /* final byte NACK */
    twsr=0x20; TWI_voidStartCond(); assert(!TWI_u8LastTransferOK());
    byte=0; TWI_voidMasterReadData(&byte); assert(byte == 0xFF);
    u8 text[301];
    for (unsigned i=0; i<299; ++i) text[i]='A';
    text[299]='B'; text[300]=0; ucsra=1u << USART_UCSRA_UDRE_BIT;
    USART_voidSendString(text); assert(udr=='B');
    USART_voidSendString(NULL);
    puts("PASS register models: PORT/DDR, isolated stepper pins, wide count, ADC mux, TWI commands/error defaults");
}

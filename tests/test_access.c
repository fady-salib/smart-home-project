#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include "../master/LIB/STD_TYPES.h"
#include "../master/HAL/Key_Pad/KP_Interface.h"
#include "../master/HAL/Step_Motor/SM_Interface.h"
static u8 keys[24], memory[256], broken_storage, outputs[8];
static unsigned position, count, motor_calls, tx_calls;
static jmp_buf unlocked;
void LCD_Init(void) { }
void LCD_ClearDisplay(void) { }
void LCD_WriteString(const char *s) { (void)s; }
u8 LCD_GoToWriteString(u8 row,u8 col,const char *s) { (void)row; (void)col; (void)s; return 1; }
void Init_KP(KP_stConfiguration *config) { (void)config; }
u8 Read_KP(KP_stConfiguration *config) { (void)config; assert(position<count); return keys[position++]; }
void TWI_voidMaterInit(u8 address) { (void)address; }
void EEPROM_voidSendData(u16 address,u8 value) { assert(address<256); memory[address]=value; }
void EEPROM_voidRecieveData(u16 address,u8 *value) { assert(address<256 && value); *value=broken_storage ? 0xFF : memory[address]; }
void DIO_VoidSetPinDirection(u8 port,u8 pin,u8 value) { (void)port; (void)pin; (void)value; }
void DIO_VoidSetPinValue(u8 port,u8 pin,u8 value) { (void)port; outputs[pin]=value; }
void Init_SM(SM_st *motor) { (void)motor; ++motor_calls; }
void USART_voidInit(void) { }
void USART_voidTransmit(u8 value) { assert(value==1); ++tx_calls; }
void Void_LDR(void) { longjmp(unlocked, 1); }
#include "../master/SERVICE/Security_Prog.c"
int main(void)
{
    count=8; for (unsigned i=0; i<count; ++i) keys[i]=(u8)(i%4+1);
    if (!setjmp(unlocked)) Pass();
    assert(motor_calls==2 && tx_calls==1 && position==8);
    motor_calls=tx_calls=position=0; broken_storage=1;
    Pass(); assert(motor_calls==0 && tx_calls==0 && position==4);
    broken_storage=0; position=0; count=16;
    for (unsigned i=4; i<count; ++i) keys[i]=9;
    Pass(); assert(position==16 && motor_calls==0 && tx_calls==0);
    assert(outputs[3]==1 && outputs[4]==1);
    puts("PASS access flow: valid PIN unlock path, storage error blocks motion and UART, three failed attempts lock out");
}

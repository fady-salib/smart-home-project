#include <assert.h>
#include <stdio.h>
#include "../slave2/LIB/STD_TYPES.h"
#include "../slave2/HAL/Key_Pad/KP_Interface.h"
static u8 sensor_temp, button=1, next_key=0xFF, output[8];
void LM35_voidReadValue(u8 pin,u8 *value) { (void)pin; *value=sensor_temp; }
void Init_KP(KP_stConfiguration *config) { (void)config; }
u8 Read_KP(KP_stConfiguration *config) { (void)config; u8 key=next_key; next_key=0xFF; return key; }
void DIO_VoidSetPinDirection(u8 port,u8 pin,u8 mode) { (void)port; (void)pin; (void)mode; }
void DIO_VoidSetPinValue(u8 port,u8 pin,u8 value) { (void)port; output[pin]=value; }
void DIO_VoidGetPinValue(u8 port,u8 pin,u8 *value) { (void)port; (void)pin; *value=button; }
void LCD_ClearDisplay(void) { }
void LCD_WriteString(const char *s) { (void)s; }
u8 LCD_GoToWriteNumber(u8 row,u8 col,u8 number) { (void)row; (void)col; (void)number; return 1; }
u8 LCD_WriteChar(u8 value) { (void)value; return 1; }
#include "../slave2/SERVICE/Services_Prog.c"
int main(void)
{
    sensor_temp=44; SystemState_Setter(); assert(output[1]==1 && output[2]==0);
    sensor_temp=45; SystemState_Setter(); assert(output[1]==0 && output[2]==1);
    sensor_temp=70; SystemState_Setter(); assert(output[3]==1 && output[4]==1);
    HOUR=23; MIN=59; SEC=59; TIMER(); assert(HOUR==0 && MIN==0 && SEC==0);
    button=0; Clock_Input(); button=1; Clock_Input();
    const u8 invalid[6]={2,9,0,0,0,0};
    for (u8 i=0; i<6; ++i) { next_key=invalid[i]; Clock_Input(); }
    assert(clock_editing && HOUR==0);
    const u8 valid[6]={1,2,3,4,5,6};
    for (u8 i=0; i<6; ++i) { next_key=valid[i]; Clock_Input(); }
    assert(!clock_editing && HOUR==12 && MIN==34 && SEC==56);
    puts("PASS real alarm/clock services: exact thresholds, midnight rollover, bounded entry and invalid time rejection");
}

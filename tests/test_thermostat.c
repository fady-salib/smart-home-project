#include <assert.h>
#include <stdio.h>
#include "../slave1/LIB/STD_TYPES.h"
#include "../slave1/HAL/Key_Pad/KP_Interface.h"
static u8 sensor, outputs[4][8], key_position;
void LM35_voidReadValue(u8 pin,u8 *value) { (void)pin; *value=sensor; }
void Init_KP(KP_stConfiguration *config) { (void)config; }
u8 Read_KP(KP_stConfiguration *config) { (void)config; return key_position++ ? 5 : 2; }
void DIO_VoidSetPinDirection(u8 port,u8 pin,u8 mode) { (void)port; (void)pin; (void)mode; }
void DIO_VoidSetPinValue(u8 port,u8 pin,u8 value) { outputs[port][pin]=value; }
void LCD_ClearDisplay(void) { }
void LCD_WriteString(const char *s) { (void)s; }
u8 LCD_GoToWriteString(u8 row,u8 col,const char *s) { (void)row; (void)col; (void)s; return 1; }
u8 LCD_GoToWriteNumber(u8 row,u8 col,u8 value) { (void)row; (void)col; (void)value; return 1; }
u8 LCD_GoToWriteChar(u8 row,u8 col,u8 value) { (void)row; (void)col; (void)value; return 1; }
#include "../slave1/SERVICE/Services_Prog.c"
int main(void)
{
    sensor=25; Temp_Monitoring(); assert(outputs[2][3]==0 && outputs[2][4]==0);
    Set_Temp(&Act_temp); assert(Act_temp==25);
    sensor=26; Temp_Monitoring(); assert(outputs[2][3]==1 && outputs[2][4]==0);
    sensor=24; Temp_Monitoring(); assert(outputs[2][3]==0 && outputs[2][4]==1);
    sensor=25; Temp_Monitoring(); assert(outputs[2][3]==0 && outputs[2][4]==0);
    puts("PASS real thermostat: startup outputs off, explicit setpoint and exclusive heat/cool decisions");
}

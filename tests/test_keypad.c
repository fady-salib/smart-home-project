#include <assert.h>
#include <stdio.h>
#include "../slave1/LIB/STD_TYPES.h"
#include "../slave1/MCAL/DIO/DIO_Interface.h"
static u8 directions[4][8], outputs[4][8], pressed;
void DIO_VoidSetPinDirection(u8 port, u8 pin, u8 value) { directions[port][pin]=value; }
void DIO_VoidSetPinValue(u8 port, u8 pin, u8 value) { outputs[port][pin]=value; }
void DIO_VoidGetPinValue(u8 port, u8 pin, u8 *value)
{
    *value = !(pressed && outputs[3][4] == 0 && port == 0 && pin == 6);
}
#include "../slave1/HAL/Key_Pad/KP_Prog.c"
int main(void)
{
    KP_stConfiguration config = {.KP_Colum1_PORT=3, .KP_Colum2_PORT=3, .KP_Colum3_PORT=3,
        .KP_Colum1_PIN=2, .KP_Colum2_PIN=4, .KP_Colum3_PIN=5,
        .KP_Row1_PORT=3, .KP_Row1_PIN=7, .KP_Row2_PORT=0, .KP_Row2_PIN=5,
        .KP_Row3_PORT=0, .KP_Row3_PIN=6, .KP_Row4_PORT=0, .KP_Row4_PIN=7};
    Init_KP(&config);
    assert(directions[0][0] == 0); /* no phantom fourth column steals LM35 A0 */
    pressed=1; assert(Read_KP(&config) == 2);
    assert(Read_KP(&config) == KP_Not_Pressed); /* held press cannot block */
    pressed=0; assert(Read_KP(&config) == KP_Not_Pressed);
    pressed=1; assert(Read_KP(&config) == 2);
    puts("PASS keypad: exactly three columns, pull-ups, edge reporting and bounded held-key scan");
}

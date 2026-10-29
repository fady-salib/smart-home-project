/*
 * KP_Prog.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Hanos_000
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KP_Config.h"
#include "KP_Interface.h"

void Init_KP(KP_stConfiguration *config)
{
    if (!config) return;
    u8 ports[3] = {config->KP_Colum1_PORT, config->KP_Colum2_PORT, config->KP_Colum3_PORT};
    u8 pins[3] = {config->KP_Colum1_PIN, config->KP_Colum2_PIN, config->KP_Colum3_PIN};
    u8 row_ports[4] = {config->KP_Row1_PORT, config->KP_Row2_PORT, config->KP_Row3_PORT, config->KP_Row4_PORT};
    u8 rows[4] = {config->KP_Row1_PIN, config->KP_Row2_PIN, config->KP_Row3_PIN, config->KP_Row4_PIN};
    for (u8 i = 0; i < 3; ++i) {
        DIO_VoidSetPinValue(ports[i], pins[i], DIO_u8PIN_HIGH);
        DIO_VoidSetPinDirection(ports[i], pins[i], DIO_u8PIN_OUTPUT);
    }
    for (u8 i = 0; i < 4; ++i) {
        DIO_VoidSetPinDirection(row_ports[i], rows[i], DIO_u8PIN_INPUT);
        DIO_VoidSetPinValue(row_ports[i], rows[i], DIO_u8PIN_HIGH);
    }
}

u8 Read_KP(KP_stConfiguration *config)
{
    static u8 held = 0;
    static const u8 keys[4][3] = KP_Arr;
    if (!config) return KP_Not_Pressed;
    u8 ports[3] = {config->KP_Colum1_PORT, config->KP_Colum2_PORT, config->KP_Colum3_PORT};
    u8 pins[3] = {config->KP_Colum1_PIN, config->KP_Colum2_PIN, config->KP_Colum3_PIN};
    u8 row_ports[4] = {config->KP_Row1_PORT, config->KP_Row2_PORT, config->KP_Row3_PORT, config->KP_Row4_PORT};
    u8 rows[4] = {config->KP_Row1_PIN, config->KP_Row2_PIN, config->KP_Row3_PIN, config->KP_Row4_PIN};
    u8 pressed = KP_Not_Pressed;
    for (u8 col = 0; col < 3; ++col) {
        DIO_VoidSetPinValue(ports[col], pins[col], DIO_u8PIN_LOW);
        for (u8 row = 0; row < 4; ++row) {
            u8 state = DIO_u8PIN_HIGH;
            DIO_VoidGetPinValue(row_ports[row], rows[row], &state);
            if (state == DIO_u8PIN_LOW && pressed == KP_Not_Pressed) pressed = keys[row][col];
        }
        DIO_VoidSetPinValue(ports[col], pins[col], DIO_u8PIN_HIGH);
    }
    if (pressed == KP_Not_Pressed) { held = 0; return KP_Not_Pressed; }
    if (held) return KP_Not_Pressed;
    held = 1;
    return pressed; /* one event per press; no wait-until-release loop */
}

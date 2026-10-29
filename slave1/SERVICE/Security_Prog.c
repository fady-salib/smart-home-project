/*
 * Security_Prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Hanos_000
 */
#include"../LIB/STD_TYPES.h"
#include "../../common/HomeLogic.h"
#include"../LIB/BIT_MATH.h"
#include "../HAL/Key_Pad/KP_Interface.h"
#include "../HAL/Key_Pad/KP_Private.h"
#include"../HAL/EEPROM/EEPROM_Interface.h"
#include "../MCAL/TWI/TWI_Interface.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include <util/delay.h>

static KP_stConfiguration KP1 =
	{ .KP_Colum1_PORT = DIO_u8PORTD, .KP_Colum2_PORT =
	DIO_u8PORTD, .KP_Colum3_PORT = DIO_u8PORTD,.KP_Row1_PORT = DIO_u8PORTD, .KP_Row2_PORT = DIO_u8PORTA,
			.KP_Row3_PORT = DIO_u8PORTA, .KP_Row4_PORT = DIO_u8PORTA,
			.KP_Colum1_PIN = DIO_u8PIN2, .KP_Colum2_PIN = DIO_u8PIN4,
			.KP_Colum3_PIN = DIO_u8PIN5,
			.KP_Row1_PIN =
			DIO_u8PIN7, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
			.KP_Row4_PIN = DIO_u8PIN7 };

u16 arrayToNum(u8 *arr, u16 length)
{
    uint16_t value = 0;
    if (length > 4 || !home_digits_to_u16(arr, (uint8_t)length, &value)) return 0;
    return value;
}

static void read_digits(u8 count, u8 *output)
{
    Init_KP(&KP1);
    for (u8 i = 0; i < count; ++i) {
        u8 key;
        do { key = Read_KP(&KP1); } while (key > 9);
        if (output) {
            output[i] = key;
            LCD_GoToWriteChar(2, i, '*');
        } else {
            LCD_GoToWriteNumber(2, i + 1, key);
        }
    }
}

void Change_Pass(void)
{
    u8 digits[4];
    LCD_ClearDisplay();
    LCD_GoToWriteString(1, 0, "Change Password:");
    read_digits(4, digits);
    u16 number = arrayToNum(digits, 4);
    u8 high = number / 100, low = number % 100, saved_high = 0xFF, saved_low = 0xFF;
    TWI_voidMaterInit(0x01);
    EEPROM_voidSendData(HOME_PIN_HIGH_ADDRESS, high);
    EEPROM_voidSendData(HOME_PIN_LOW_ADDRESS, low);
    EEPROM_voidRecieveData(HOME_PIN_HIGH_ADDRESS, &saved_high);
    EEPROM_voidRecieveData(HOME_PIN_LOW_ADDRESS, &saved_low);
    LCD_ClearDisplay();
    LCD_WriteString(saved_high == high && saved_low == low ? "Password Saved!" : "EEPROM ERROR");
}

/* Original phone menus only collect/display digits: no storage, modem or dialing. */
void Add_Emergn_NUM(void)
{
    LCD_ClearDisplay();
    LCD_WriteString("EMERGENCY DIGITS:");
    read_digits(3, NULL);
}
void Add_Phone_NUM(void)
{
    LCD_ClearDisplay();
    LCD_WriteString("PHONE DIGITS:");
    read_digits(11, NULL); /* no undersized array or overflowing integer conversion */
}

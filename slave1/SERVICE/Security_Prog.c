/*
 * Security_Prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Hanos_000
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include "../HAL/Key_Pad/KP_Interface.h"
#include "../HAL/Key_Pad/KP_Private.h"
#include"../HAL/EEPROM/EEPROM_Interface.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include <util/delay.h>

u16 arrayToNum(u16* arr, u16 length)
{
	u8 num = 0; //u16
	for (u8 i = 0; i < length; i++)
	{
		num = num * 10 + arr[i];
	}
	return num;
}

void Change_Pass()
{
	u16 Pass;
	LCD_Init();
	KP_stConfiguration KP1 =
	{ .KP_Colum1_PORT = DIO_u8PORTD, .KP_Colum2_PORT =
	DIO_u8PORTD, .KP_Colum3_PORT = DIO_u8PORTD,.KP_Row1_PORT = DIO_u8PORTD, .KP_Row2_PORT = DIO_u8PORTA,
			.KP_Row3_PORT = DIO_u8PORTA, .KP_Row4_PORT = DIO_u8PORTA,
			.KP_Colum1_PIN = DIO_u8PIN2, .KP_Colum2_PIN = DIO_u8PIN4,
			.KP_Colum3_PIN = DIO_u8PIN5,
			.KP_Row1_PIN =
			DIO_u8PIN7, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
			.KP_Row4_PIN = DIO_u8PIN7 };
	u16 num;
	u8 Flag = 0, i;
	u8 MultiArr[4] = //u16
			{ 1000, 100, 10, 1 };
	Init_KP(&KP1);
	LCD_GoToWriteString(1, 0, "Change Password:");

	while (Flag < 4) //loop till the user finish inserting the pass
	{
		u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == 0xFF) //repeat till the user press any key
		{

			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

		}
		MultiArr[Flag] = key_pressed;
		num = arrayToNum(MultiArr, 4);

		Flag++;

	} //
	LCD_ClearDisplay();
	Pass = num;
	LCD_GoToWriteString(0, 1, "Password Saved!");

	u8 first4digits = Pass / 100;
	u8 last4digits = Pass % 100;

	TWI_voidMaterInit(0x01);
	EEPROM_voidSendData(0x1234, first4digits);
	EEPROM_voidRecieveData(0x1234, &first4digits);
	EEPROM_voidSendData(0x1245, last4digits);
	EEPROM_voidRecieveData(0x1245, last4digits);
}

void Add_Emergn_NUM(void)
{
	KP_stConfiguration KP1 =
	{ .KP_Colum1_PORT = DIO_u8PORTD, .KP_Colum2_PORT =
	DIO_u8PORTD, .KP_Colum3_PORT = DIO_u8PORTD,.KP_Row1_PORT = DIO_u8PORTD, .KP_Row2_PORT = DIO_u8PORTA,
			.KP_Row3_PORT = DIO_u8PORTA, .KP_Row4_PORT = DIO_u8PORTA,
			.KP_Colum1_PIN = DIO_u8PIN2, .KP_Colum2_PIN = DIO_u8PIN4,
			.KP_Colum3_PIN = DIO_u8PIN5,
			.KP_Row1_PIN =
			DIO_u8PIN7, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
			.KP_Row4_PIN = DIO_u8PIN7 };
	LCD_ClearDisplay();
	u8 Flag1 = 0;
	u8 num;
	u8 MultiArr[3] =
	{ 10, 2, 10 };
	Init_KP(&KP1);
	LCD_GoToWriteString(0, 0, "ADD EMERGENCY NUMBER:");
	while (Flag1 < 1) //loop till the user finish inserting the pass
	{
		u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == 0xFF) //repeat till the user press any key
		{

			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

		}
		MultiArr[Flag1] = key_pressed;
LCD_GoToWriteNumber(2,1,key_pressed);
		Flag1++;

	}
	while (Flag1 < 2) //loop till the user finish inserting the pass
	{
		u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == 0xFF) //repeat till the user press any key
		{

			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

		}
		MultiArr[Flag1] = key_pressed;
		LCD_GoToWriteNumber(2,2,key_pressed);
		Flag1++;

	}
	while (Flag1 < 3) //loop till the user finish inserting the pass
	{
		u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == 0xFF) //repeat till the user press any key
		{

			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

		}
		MultiArr[Flag1] = key_pressed;
		LCD_GoToWriteNumber(2,3,key_pressed);
		Flag1++;
_delay_ms(100);
	}
	
	
}

void Add_Phone_NUM(void)
{
	KP_stConfiguration KP1 =
	{ .KP_Colum1_PORT = DIO_u8PORTD, .KP_Colum2_PORT =
	DIO_u8PORTD, .KP_Colum3_PORT = DIO_u8PORTD,.KP_Row1_PORT = DIO_u8PORTD, .KP_Row2_PORT = DIO_u8PORTA,
			.KP_Row3_PORT = DIO_u8PORTA, .KP_Row4_PORT = DIO_u8PORTA,
			.KP_Colum1_PIN = DIO_u8PIN2, .KP_Colum2_PIN = DIO_u8PIN4,
			.KP_Colum3_PIN = DIO_u8PIN5,
			.KP_Row1_PIN =
			DIO_u8PIN7, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
			.KP_Row4_PIN = DIO_u8PIN7 };
	LCD_ClearDisplay();
	u8 Flag2 = 0;
	u8 num;
	u8 MultiArr[10] =
	{ 2, 3, 5, 7 ,1,2,3,4,5,6};
	Init_KP(&KP1);
	LCD_GoToWriteString(0, 0, "ADD PHONE NUMBER:");
	while (Flag2 < 1) //loop till the user finish inserting the pass
	{
		u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == 0xFF) //repeat till the user press any key
		{

			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

		}
		MultiArr[Flag2] = key_pressed;
		LCD_GoToWriteNumber(2,1,key_pressed);
		Flag2++;

	}
	while (Flag2 < 2) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,2,key_pressed);
			Flag2++;

		}
	while (Flag2 < 3) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,3,key_pressed);
			Flag2++;

		}
	while (Flag2 < 4) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,4,key_pressed);
			Flag2++;

		}
	while (Flag2 < 5) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,5,key_pressed);
			Flag2++;

		}
	while (Flag2 < 6) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,6,key_pressed);
			Flag2++;

		}
	while (Flag2 < 7) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,7,key_pressed);
			Flag2++;

		}
	while (Flag2 < 8) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,8,key_pressed);
			Flag2++;

		}
	while (Flag2 < 9) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,9,key_pressed);
			Flag2++;

		}
	while (Flag2 < 10) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,10,key_pressed);
			Flag2++;
		}
	while (Flag2 < 11) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr[Flag2] = key_pressed;
			LCD_GoToWriteNumber(2,11,key_pressed);
			Flag2++;
			_delay_ms(100);
		}


	u16 PHONE_Num = arrayToNum(MultiArr, 11);


}


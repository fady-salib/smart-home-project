/*
 * Services_Prog.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Hanos_000
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include "../HAL/Key_Pad/KP_Interface.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/LM35/LM35_Interface.h"

u8 Temp; //GLOBAL LM35 TEMPERATURE VALUE
extern u8 Act_temp = 0; //TEMPERATURE ENTERED BY USER

void Set_Temp(u8 *Ptr_Temp)
{
	KP_stConfiguration KP1 =
	{ .KP_Colum1_PORT = DIO_u8PORTC, .KP_Colum2_PORT =
	DIO_u8PORTC, .KP_Colum3_PORT = DIO_u8PORTC, .KP_Row1_PORT = DIO_u8PORTC, .KP_Row2_PORT = DIO_u8PORTC,
			.KP_Row3_PORT = DIO_u8PORTC, .KP_Row4_PORT = DIO_u8PORTC,
			.KP_Colum1_PIN = DIO_u8PIN0, .KP_Colum2_PIN = DIO_u8PIN1,
			.KP_Colum3_PIN = DIO_u8PIN2, .KP_Colum4_PIN = DIO_u8PIN3, .KP_Row1_PIN =
			DIO_u8PIN4, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
			.KP_Row4_PIN = DIO_u8PIN7 };
	
	Init_KP(&KP1); //INTI KEYPAD TO SET TEMPERATURE
	u8 counter = 0; // COUNTER LOOPS TO SAVE TWO NUMBERS IN ARRAY
	u8 key_pressed;
	u8 arr[2] =
	{ 0, 0 }; // ARRAY TO SAVE TEMPERATURE VALUE
	u8 LM35_VAL = 0;
	LCD_WriteString("Set Temp:");
	LCD_GoToWriteChar(0, 11, 'C');
	while (counter < 2)
	{
		key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == 0xFF) //repeat till the user press any key
		{
			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed
		}

		arr[counter] = key_pressed;

		LCD_GoToWriteNumber(0, 9 + counter, key_pressed);

		counter++;

	}
	*Ptr_Temp = arr[0] * 10 + arr[1]; //MERGE THE TWO NUMBERS OF ARRAY

}

void Temp_Monitoring() //MONITOR THE TEMPERATURE BY CONTROL AC / HEATER
{

	DIO_VoidSetPinDirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_OUTPUT);
	
	LM35_voidReadValue(DIO_u8PIN0,&Temp);
	
	if ( Temp == Act_temp )
	{
		DIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_LOW);
	}
	else if(Temp < Act_temp)
		{
		DIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_HIGH);
		}
	else if(Temp > Act_temp)
			{
		DIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);
			}
	
	
	
}
void Void_LDR() //MONITOR LED ACCORDING TO LIGHT
{
	LCD_Init();
	u16 Read_LDR = 0;
	ADC_voidInit();
	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
		ADC_StartConv(ADC_CHANNEL3, &Read_LDR);
		if ((Read_LDR / 204.8) <= 5 && (Read_LDR / 204.8) > 3) {	

			DIO_VoidSetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_HIGH);
		}

		else if ((Read_LDR / 204.8) <= 3 && (Read_LDR / 204.8) > 0) {
		
			DIO_VoidSetPinValue(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_LOW);

		}

}

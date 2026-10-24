///*
// * Services_Prog.c
// *
// *  Created on: Sep 5, 2023
// *      Author: Hanos_000
// */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include "../HAL/Key_Pad/KP_Interface.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../HAL/LM35/LM35_Interface.h"


u8 SEC = 0,MIN = 0 , HOUR = 0;
u8 Clock_Num[6] =
{ 0, 0, 0, 0, 0, 0 };

u8 TempRead = 0;
u8 SmokeRead = 0;



void SystemState_Setter(void)  //CHECK THE TEMPERATURE AND ACT ACCORDING TO THE STATE -> (FIRE ALARM)
{
    LM35_voidReadValue(DIO_u8PIN1, &TempRead);
	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_OUTPUT);
	
	if (TempRead < 45 ) //WHITE LED AND FINE STATE
			{
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_LOW);
	}

	else if ( TempRead < 70 && TempRead > 45) //YELLOW LED AND HEAT ZONE
			{
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_LOW);
	}

	else if (TempRead >= 70 ) //RED LED, BUZZER AND DANGER ZONE 
			{
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_HIGH);
		
	}

}


void TIMER() //SET AND DISPLAY CLOCK
{

		u8 x = 1;
		DIO_VoidGetPinValue(DIO_u8PORTC,DIO_u8PIN0,&x);
		
		if(x == 0)	{
			
		
			
			KP_stConfiguration KP1 =
			{
		
			.KP_Colum1_PORT = DIO_u8PORTD, .KP_Colum2_PORT =
					DIO_u8PORTD, .KP_Colum3_PORT = DIO_u8PORTD, .KP_Row1_PORT = DIO_u8PORTD,
					.KP_Row2_PORT = DIO_u8PORTD, .KP_Row3_PORT = DIO_u8PORTD,
					.KP_Row4_PORT = DIO_u8PORTD, .KP_Colum1_PIN = DIO_u8PIN0,
					.KP_Colum2_PIN = DIO_u8PIN1, .KP_Colum3_PIN = DIO_u8PIN2,
					.KP_Row1_PIN =
					DIO_u8PIN4, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
					.KP_Row4_PIN = DIO_u8PIN7 };
		
			u8 Flag = 0;
			Init_KP(&KP1);
			LCD_GoToWriteString(1, 0, "ENTER HH:MM:SS");
		//USER ENTER CLOCK VALUES
			while (Flag < 6)
			{
				u8 key_pressed = 0xFF;
				while (key_pressed == 0xFF)
				{
					key_pressed = Read_KP(&KP1);
				}
		
				Clock_Num[Flag] = key_pressed;
				LCD_GoToClear(2, Flag, 1);
				LCD_GoToWriteNumber(2, Flag, key_pressed);
				Flag++;
				 SEC = Clock_Num[4] * 10 + Clock_Num[5];
				 MIN = Clock_Num[2] * 10 + Clock_Num[3];
				 HOUR = Clock_Num[0] * 10 + Clock_Num[1];
			}}
	
	SEC++;

	LCD_ClearDisplay();
	if (SEC >= 60)
	{
		SEC = 0;
		MIN++;
		LCD_ClearDisplay();

		if (MIN >= 60)
		{
			MIN = 0;
			HOUR++;
			LCD_ClearDisplay();

			if (HOUR >= 24)
			{
				HOUR = 0;
				LCD_ClearDisplay();

			}

		}

	}
	//DISPLAY CLOCK
	LCD_GoToWriteNumber(0,0,HOUR);
	LCD_WriteChar(':');
	LCD_GoToWriteNumber(0,3,MIN);
	LCD_WriteChar(':');
	LCD_GoToWriteNumber(0,6,SEC);

}




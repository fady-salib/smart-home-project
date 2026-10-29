///*
// * Services_Prog.c
// *
// *  Created on: Sep 5, 2023
// *      Author: Hanos_000
// */
#include"../LIB/STD_TYPES.h"
#include "../../common/HomeLogic.h"
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
	
	if (home_temperature_zone(TempRead) == 0) //WHITE LED AND FINE STATE
			{
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_LOW);
	}

	else if (home_temperature_zone(TempRead) == 1) //YELLOW LED AND HEAT ZONE
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


static u8 clock_editing = 0;

void Clock_Input(void)
{
    static u8 previous_button = 1, digit_count = 0;
    static KP_stConfiguration keypad = {
        .KP_Colum1_PORT=DIO_u8PORTD, .KP_Colum2_PORT=DIO_u8PORTD, .KP_Colum3_PORT=DIO_u8PORTD,
        .KP_Colum1_PIN=0, .KP_Colum2_PIN=1, .KP_Colum3_PIN=2,
        .KP_Row1_PORT=DIO_u8PORTD, .KP_Row2_PORT=DIO_u8PORTD,
        .KP_Row3_PORT=DIO_u8PORTD, .KP_Row4_PORT=DIO_u8PORTD,
        .KP_Row1_PIN=4, .KP_Row2_PIN=5, .KP_Row3_PIN=6, .KP_Row4_PIN=7
    };
    u8 button = 1;
    DIO_VoidGetPinValue(DIO_u8PORTC, DIO_u8PIN0, &button);
    if (!button && previous_button) {
        clock_editing = 1;
        digit_count = 0;
        Init_KP(&keypad);
        LCD_ClearDisplay();
        LCD_WriteString("ENTER HH:MM:SS");
    }
    previous_button = button;
    if (!clock_editing) return;
    u8 key = Read_KP(&keypad);
    if (key > 9) return;
    Clock_Num[digit_count] = key;
    LCD_GoToWriteNumber(2, digit_count, key);
    if (++digit_count == 6) {
        u8 hour = Clock_Num[0] * 10 + Clock_Num[1];
        u8 minute = Clock_Num[2] * 10 + Clock_Num[3];
        u8 second = Clock_Num[4] * 10 + Clock_Num[5];
        if (hour < 24 && minute < 60 && second < 60) {
            HOUR = hour; MIN = minute; SEC = second;
            clock_editing = 0;
        } else {
            LCD_ClearDisplay();
            LCD_WriteString("INVALID HH:MM:SS");
        }
        digit_count = 0;
    }
}

void TIMER(void)
{
    if (++SEC >= 60) {
        SEC = 0;
        if (++MIN >= 60) {
            MIN = 0;
            if (++HOUR >= 24) HOUR = 0;
        }
    }
    if (!clock_editing) {
        LCD_GoToWriteNumber(0, 0, HOUR);
        LCD_WriteChar(':');
        LCD_GoToWriteNumber(0, 3, MIN);
        LCD_WriteChar(':');
        LCD_GoToWriteNumber(0, 6, SEC);
    }
}

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
//#include<util/delay.h>
u8 Temp;

extern u8 Act_temp = 0; //USER TEMP

void Set_Temp(u8 *Ptr_Temp)
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

	Init_KP(&KP1);
	u8 counter = 0;
	u8 key_pressed;
	u8 arr[2] =
	{ 0, 0 }; // Buffer size adjusted to hold the LM35 value
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
	*Ptr_Temp = arr[0] * 10 + arr[1];

}

void Temp_Monitoring() //MENTOR TEMPERATURE WITH AC/HEATER
{

	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTA, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_OUTPUT);

	LM35_voidReadValue(DIO_u8PIN0, &Temp);

	if (Temp == Act_temp)
	{
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN3, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_LOW);
	}
	else if (Temp < Act_temp)
	{
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN3, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_HIGH);
	}
	else if (Temp > Act_temp)
	{
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_LOW);
		DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN3, DIO_u8PIN_HIGH);
		DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN4, DIO_u8PIN_LOW);
	}

}

void SET_DEVICE(void) //FUNCTION TO CONTROL DEVICES
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
	
	Init_KP(&KP1);
	u8 key_pressed;
	LCD_ClearDisplay();
	LCD_GoToWriteString(0, 0, "1-LIVING ROOM");
	LCD_GoToWriteString(1, 0, "2-ROOM 1");
	LCD_GoToWriteString(2, 0, "3-ROOM 2");
	LCD_GoToWriteString(3, 0, "4-GARDEN");
	while (1)
	{
		key_pressed = 0xFF;
		while (key_pressed == 0xFF)
		{
			key_pressed = Read_KP(&KP1);
		}
		if (key_pressed == 1) //LIVING ROOM
		{
			LCD_ClearDisplay();
			LCD_GoToWriteString(0, 0, "1-LED");
			LCD_GoToWriteString(1, 0, "2-AC");
			LCD_GoToWriteString(2, 0, "3-HEATER");
			while (1)
			{
				key_pressed = 0xFF;
				while (key_pressed == 0xFF)
				{
					key_pressed = Read_KP(&KP1);
				}
				if (key_pressed == 1) //1-LED
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN2,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN LED ON");
					LCD_GoToWriteString(1, 0, "2-TURN LED OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN LED ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN LED OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2,
							DIO_u8PIN_LOW);

						}
						break;
					}
				}
				else if (key_pressed == 2) //2-AC
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN3,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN AC ON");
					LCD_GoToWriteString(1, 0, "2-TURN AC OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN AC ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN AC OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3,
							DIO_u8PIN_LOW);

						}
						break;
					}
				}

				else if (key_pressed == 3) //3-HEATER
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN4,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN HEATER ON");
					LCD_GoToWriteString(1, 0, "2-TURN HEATER OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN HEATER ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN HEATER OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4,
							DIO_u8PIN_LOW);

						}
						break;
					}

				}
				break;
			}
		}
		else if (key_pressed == 2) //ROOM 1
		{
			LCD_ClearDisplay();
			LCD_GoToWriteString(0, 0, "1-LED");
			LCD_GoToWriteString(1, 0, "2-AC");
			LCD_GoToWriteString(2, 0, "3-HEATER");
			while (1)
			{
				key_pressed = 0xFF;
				while (key_pressed == 0xFF)
				{
					key_pressed = Read_KP(&KP1);
				}
				if (key_pressed == 1) //1-LED
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN5,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN LED ON");
					LCD_GoToWriteString(1, 0, "2-TURN LED OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN LED ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN5,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN LED OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN5,
							DIO_u8PIN_LOW);

						}
						break;
					}
				}
				else if (key_pressed == 2) //2-AC
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN6,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN AC ON");
					LCD_GoToWriteString(1, 0, "2-TURN AC OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN AC ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN6,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN AC OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN6,
							DIO_u8PIN_LOW);

						}
						break;
					}
				}

				else if (key_pressed == 3) //3-HEATER
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN7,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN HEATER ON");
					LCD_GoToWriteString(1, 0, "2-TURN HEATER OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN HEATER ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN7,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN HEATER OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN7,
							DIO_u8PIN_LOW);

						}
						break;
					}

				}
				break;
			}

		}
		else if (key_pressed == 3) //ROOM 2
		{
			LCD_ClearDisplay();
			LCD_GoToWriteString(0, 0, "1-LED");
			LCD_GoToWriteString(1, 0, "2-AC");
			LCD_GoToWriteString(2, 0, "3-HEATER");
			while (1)
			{
				key_pressed = 0xFF;
				while (key_pressed == 0xFF)
				{
					key_pressed = Read_KP(&KP1);
				}
				if (key_pressed == 1) //1-LED
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTA, DIO_u8PIN2,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN LED ON");
					LCD_GoToWriteString(1, 0, "2-TURN LED OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN LED ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN2,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN LED OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN2,
							DIO_u8PIN_LOW);

						}
						break;
					}
				}
				else if (key_pressed == 2) //2-AC
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTA, DIO_u8PIN3,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN AC ON");
					LCD_GoToWriteString(1, 0, "2-TURN AC OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN AC ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN3,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN AC OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN3,
							DIO_u8PIN_LOW);

						}
						break;
					}
				}

				else if (key_pressed == 3) //3-HEATER
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTA, DIO_u8PIN4,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN HEATER ON");
					LCD_GoToWriteString(1, 0, "2-TURN HEATER OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN HEATER ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN4,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN HEATER OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTA, DIO_u8PIN4,
							DIO_u8PIN_LOW);

						}
						break;
					}

				}
				break;
			}

		}
		else if (key_pressed == 4) //GARDEN
		{
			LCD_ClearDisplay();

			LCD_GoToWriteString(0, 0, "1-OPEN/CLOSE GATE ");
			LCD_GoToWriteString(1, 0, "2-TURN LED ON/OFF");
			while (1)
			{

				key_pressed = 0xFF;
				while (key_pressed == 0xFF)
				{
					key_pressed = Read_KP(&KP1);
				}
				if (key_pressed == 1)
				{

					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTD, DIO_u8PIN3,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-OPEN GATE");
					LCD_GoToWriteString(1, 0, "2-CLOSE GATE");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //OPEN GATE
						{

							DIO_VoidSetPinValue(DIO_u8PORTD, DIO_u8PIN3,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //CLOSE GATE
						{
							DIO_VoidSetPinValue(DIO_u8PORTD, DIO_u8PIN3,
							DIO_u8PIN_LOW);

						}
						break;
					}

				}
				else if (key_pressed == 2)
				{
					LCD_ClearDisplay();
					DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN3,
					DIO_u8PIN_OUTPUT);
					LCD_GoToWriteString(0, 0, "1-TURN LED ON");
					LCD_GoToWriteString(1, 0, "2-TURN LED OFF");
					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) //TURN LED ON
						{

							DIO_VoidSetPinValue(DIO_u8PORTB, DIO_u8PIN3,
							DIO_u8PIN_HIGH);

						}
						else if (key_pressed == 2) //2-TURN LED OFF
						{
							DIO_VoidSetPinValue(DIO_u8PORTB, DIO_u8PIN3,
							DIO_u8PIN_LOW);

						}
						break;
					}

				}
				break;
			}

		}

		break;
	}
}

/*
 * InteractiveLCD_Prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Hanos_000
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include<util/delay.h>
#include "../HAL/Key_Pad/KP_Interface.h"
#include "../HAL/Key_Pad/KP_Private.h"
#include"../MCAL/TWI/TWI_Interface.h"
#include"../HAL/EEPROM/EEPROM_Interface.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../TMU/TMU_Interface.h"
#include"../HAL/LM35/LM35_Interface.h"

u8 Act_temp;
u8 Temp;
void InteractiveLCD()
{
	u8 temp;
	u8 PIN_Start = 1;  //BUTTON TO INIT LCD

	KP_stConfiguration KP1 =
	{ .KP_Colum1_PORT = DIO_u8PORTD, .KP_Colum2_PORT =
	DIO_u8PORTD, .KP_Colum3_PORT = DIO_u8PORTD, .KP_Row1_PORT = DIO_u8PORTD,
			.KP_Row2_PORT = DIO_u8PORTA, .KP_Row3_PORT = DIO_u8PORTA,
			.KP_Row4_PORT = DIO_u8PORTA, .KP_Colum1_PIN = DIO_u8PIN2,
			.KP_Colum2_PIN = DIO_u8PIN4, .KP_Colum3_PIN = DIO_u8PIN5,
			.KP_Row1_PIN =
			DIO_u8PIN7, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
			.KP_Row4_PIN = DIO_u8PIN7 };

	//KEYPAD TO INTERATC WITH THE LCD

	Init_KP(&KP1);
	DIO_VoidGetPinValue(DIO_u8PORTD, DIO_u8PIN6, &PIN_Start);

	if (PIN_Start == 0) // PRESS THE BUTTON INITIALIZE THE LCD
	{
		//INTERACTIVE LCD

		LCD_GoToWriteString(0, 6, "WELCOME!"); //GOTO -> (CHANGE POSITION ON LCD)
		LCD_GoToWriteString(2, 0, "FOR SETTING ENTER'#'");
		LCD_GoToWriteString(3, 0, "TEMPERATURE IS:");
		LM35_voidReadValue(DIO_u8PIN0, &Temp);                 //READ LM35 VALUE

		LCD_GoToWriteNumber(3, 15, Temp); //SHOW ACTUAL TEMPERATUREE FROM LM35
		LCD_GoToWriteString(3, 17, "C");

		u8 key_pressed = 0xFF;
		while (key_pressed == 0xFF)
		{
			key_pressed = Read_KP(&KP1);
		}

		if (key_pressed == '#')
		{
			LCD_ClearDisplay();

			LCD_GoToWriteString(0, 0, "SETTING:");
			LCD_GoToWriteString(1, 0, "1-SECURITY");
			LCD_GoToWriteString(2, 0, "2-SERVICES");
			LCD_GoToWriteString(3, 0, "3-CLOSE LCD");
			while (1)
			{
				key_pressed = 0xFF;
				while (key_pressed == 0xFF)
				{
					key_pressed = Read_KP(&KP1);
				}
				if (key_pressed == 1) //SECURITY
				{
					LCD_GoToWriteString(0, 0, "SECURITY");
					LCD_GoToWriteString(1, 0, "1-CHANGE PASSWORD");
					LCD_GoToWriteString(2, 0, "2-ADD EMERGENCY NUM");
					LCD_GoToWriteString(3, 0, "3-ADD PHONE NUM");

					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1) // Change Password
						{
							LCD_ClearDisplay();
							Change_Pass();

						}
						else if (key_pressed == 2) //ADD EMERGENCY NUMBER
						{
							LCD_ClearDisplay();
							Add_Emergn_NUM();

						}
						else if (key_pressed == 3) //ADD PHONE NUMBER
						{
							LCD_ClearDisplay();
							Add_Phone_NUM();

						}

						break;
					}

				}
				else if (key_pressed == 2) //  
				{
					LCD_GoToWriteString(0, 0, "SERVICES");
					LCD_GoToWriteString(1, 0, "1-SET TEMPERATURE"); //1-4
					LCD_GoToWriteString(2, 0, "2-TURN DEVICE ON/OFF"); //2-6
					LCD_GoToWriteString(3, 0,
							"3-MORE..                        ");

					while (1)
					{
						key_pressed = 0xFF;
						while (key_pressed == 0xFF)
						{
							key_pressed = Read_KP(&KP1);
						}
						if (key_pressed == 1)  //SET TEMP
						{

							LCD_ClearDisplay();
							Set_Temp(&Act_temp);
						}
						else if (key_pressed == 2)  //TURN DEVICE ON/OFF
						{

							SET_DEVICE();

						}
						else if (key_pressed == 3) //MORE..
						{

							LCD_GoToWriteString(1, 0, "4-RATE US 0 TO 5 :)    ");
							LCD_GoToWriteString(2, 0, "5-ELECTRICITY MANAGE");
							LCD_GoToWriteString(3, 0, "6-SET TIME");

							while (1)
							{
								key_pressed = 0xFF;
								while (key_pressed == 0xFF)
								{
									key_pressed = Read_KP(&KP1);
								}
								if (key_pressed == 4) //RATE
								{
									LCD_ClearDisplay();
									LCD_WriteString("RATE:");
									key_pressed = 0xFF;
									while (key_pressed == 0xFF)
									{
										key_pressed = Read_KP(&KP1);
									}
									LCD_GoToWriteNumber(1,0,key_pressed);
									_delay_ms(100);

								}
								else if (key_pressed == 5) //ELECTRICITY MANAGING
								{
									LCD_ClearDisplay();
									LCD_WriteString("SHA5LEL 3SHAN T3ADY :)");
									_delay_ms(100);
								}
								else if (key_pressed == 6) //SET CLOCK
								{
									LCD_ClearDisplay();
									LCD_WriteString("SET TIME ON CLOCK");
									_delay_ms(100);
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
	}

}


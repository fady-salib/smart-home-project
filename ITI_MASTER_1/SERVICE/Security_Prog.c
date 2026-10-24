/*
 * Security_Prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Hanos_000
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include<util/delay.h>
#include "../HAL/Key_Pad/KP_Interface.h"
#include "../HAL/Key_Pad/KP_Private.h"
#include"../HAL/Step_Motor/SM_Interface.h"
#include"../HAL/EEPROM/EEPROM_Interface.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD_interface.h"
#include"../MCAL/USART/USART_Interface.h"


/* KEYPAD TO ENTER PASSWORD */
KP_stConfiguration KP1 =
{ .KP_Colum1_PORT = DIO_u8PORTA, .KP_Colum2_PORT =
DIO_u8PORTA, .KP_Colum3_PORT = DIO_u8PORTA,.KP_Row1_PORT = DIO_u8PORTA, .KP_Row2_PORT = DIO_u8PORTA,
		.KP_Row3_PORT = DIO_u8PORTA, .KP_Row4_PORT = DIO_u8PORTA,
		.KP_Colum1_PIN = DIO_u8PIN0, .KP_Colum2_PIN = DIO_u8PIN1,
		.KP_Colum3_PIN = DIO_u8PIN2,.KP_Row1_PIN =
		DIO_u8PIN4, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
		.KP_Row4_PIN = DIO_u8PIN7 }; 


/* FUNCTION TO CONVERT ARRAY TO NUM */
u16 arrayToNum(u16* arr, u16 length)
{
	u8 num = 0; //u16
	for (u8 i = 0; i < length; i++)
	{
		num = num * 10 + arr[i];
	}
	return num;
}
/* FUNCTION TO SET AND COMPARE PASSWORD */

void Pass(void)
{
	u16 Pass;
	LCD_Init();

	u16 num;
	u8 Flag, i;
	u16 MultiArr[4] =
	{ 1000, 100, 10, 1 };  //ARRAY TO STORE USER PASSWORD
	Flag = 0;
	Init_KP(&KP1);
//USER SET PASSWORD
	LCD_GoToWriteString(0, 4, "WELCOME");
	LCD_GoToWriteString(1, 0, "Set Password:");
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

	}
	LCD_ClearDisplay();
	Pass = num;
	LCD_GoToWriteString(0, 1, "Password Saved!");
//SPLIT PASSWORD INTO TWO PARTS BECAUSE EEPROM CAN ONLY STORE 8 BITS PER ADDRESS
	u8 first4digits = Pass / 100; 
	u8 last4digits = Pass % 100;

	TWI_voidMaterInit(0x01);
	EEPROM_voidSendData(0x1234, first4digits);
	EEPROM_voidRecieveData(0x1234, &first4digits);
	EEPROM_voidSendData(0x1245, last4digits);
	EEPROM_voidRecieveData(0x1245, last4digits);
//User Compare Password

	LCD_GoToWriteString(0, 0, " Enter Password");
	Flag = 0;
	u16 com_num;
	u16 MultiArr2[4] =
	{ 1000, 100, 10, 1 };
	u8 Num_of_tries = 0;
	u8 Pass_Correct = 0;
	while (Flag < 4) //loop till the user finish inserting the pass
	{
		u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
		while (key_pressed == 0xFF) //repeat till the user press any key
		{

			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

		}
		MultiArr2[Flag] = key_pressed;
		com_num = arrayToNum(MultiArr2, 4);

		Flag++;

	}
	LCD_ClearDisplay();

	for (i = 0; i < 3; i++) //USER HAVE 3 TRIES ONLY TO ENTER THE CORRECT PASSWORD
	{

		while (Flag < 4) //loop till the user finish inserting the pass
		{
			u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
			while (key_pressed == 0xFF) //repeat till the user press any key
			{

				key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed

			}
			MultiArr2[Flag] = key_pressed;
			com_num = arrayToNum(MultiArr2, 4);

			Flag++;

		}
		Flag = 0;
		LCD_ClearDisplay();
		u8 z, y;
		u16 TotPass;

		EEPROM_voidRecieveData(0x1234, &z);
		EEPROM_voidRecieveData(0x1245, &y);
		TotPass = z * 100 + y;  //MERGE LAST TWO AND  FIRST TWO DIGITS OF PASSWORD 

		if (com_num == TotPass) //COMPARE BETWEEN SAVED AND USER PASSWORD
		{
			LCD_WriteString("PASSWORD CORRECT");

			DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_OUTPUT); 
			DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_HIGH); //CORRECT PASSWORD GREEN LED ON
			SM_st St_Motor =
			{ .SM_Port = DIO_u8PORTD, .Blue_Pin = DIO_u8PIN4, .Pink_Pin =
					DIO_u8PIN5, .Yellow_Pin = DIO_u8PIN6, .Orange_Pin =
					DIO_u8PIN7, .Step_Type = Full_Step, .SM_Direction =
					Clock_Wise, .SM_delay = 0, .SM_No_of_Steps = 60

					};

			Init_SM(&St_Motor); //DOOR WORKING WITH A STEPPER MOTOR 1-DOOR OPEN 
			_delay_ms(3000);
			SM_st CL_Motor =
						{ .SM_Port = DIO_u8PORTD, .Blue_Pin = DIO_u8PIN4, .Pink_Pin =
								DIO_u8PIN5, .Yellow_Pin = DIO_u8PIN6, .Orange_Pin =
								DIO_u8PIN7, .Step_Type = Full_Step, .SM_Direction =
								Counter_Clock_Wise, .SM_delay = 0, .SM_No_of_Steps = 73

								};
			Init_SM(&CL_Motor); //2-DOOR CLOSE
			
		
			u8 Start_U2 = 1; //USART FLAG
			
			//INIT USART TO TRANSMIT A FLAG TO INIT MICROCONTROLLER 2
			
				DIO_VoidSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
				DIO_VoidSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
				DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN_LOW);  
				USART_voidInit();
				USART_voidTransmit(Start_U2);

				while(1)
				{
					Void_LDR(); //LDR TO DETECT LIGHT OUTSIDE (LED ON IF DARK)
				}
			
			LCD_ClearDisplay();

		}
		else
		{
			LCD_WriteString("PLEASE TRY AGAIN"); //USER ENTER THE PASSWORD 
			Num_of_tries++;
			//RED LED TOGGLES WHEN USER ENTER THE PASSWORD WRONG
			DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_OUTPUT);	//RED LED
			DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_HIGH);
			_delay_ms(50);
			DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_LOW);
		}

	}
	if (Num_of_tries == 3) //USER ENTERD THE PASSWORD WRONG FOR 3 TIMES (ACCESS DENIED)
	{
		LCD_ClearDisplay();
		LCD_GoToWriteString(0, 0, "NO MORE TRIES");
		LCD_GoToWriteString(1, 0, "ACCESS DENIED ");

		DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_OUTPUT);	
		DIO_VoidSetPinDirection(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_OUTPUT); 
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN3, DIO_u8PIN_HIGH); //RED LED REMAINS
		DIO_VoidSetPinValue(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PIN_HIGH); //BUZZER START
	}
}





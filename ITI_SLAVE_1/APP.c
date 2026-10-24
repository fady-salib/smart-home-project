///*
// * main2.c
// *
// *  Created on: Sep 4, 2023
// *      Author: Hanos_000
// */
#include"LIB/STD_TYPES.h"
#include"LIB/BIT_MATH.h"
#include"SERVICE/Security_Interface.h"
#include"SERVICE/InteractiveLCD_Interface.h"
#include"MCAL/DIO/DIO_Interface.h"
#include"HAL/LM35/LM35_Interface.h"
#include"SERVICE/Services_Interface.h"
#include"TMU/TMU_Interface.h"
#include"MCAL/USART/USART_Interface.h"
#include<util/delay.h>
Act_temp;





void main()
{
	LCD_Init();
	u8 Start_U2;
	DIO_VoidSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_INPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_INPUT);
	DIO_VoidSetPinDirection(DIO_u8PORTD, DIO_u8PIN6, DIO_u8PIN_INPUT);
	DIO_VoidSetPinValue(DIO_u8PORTD, DIO_u8PIN6, DIO_u8PIN_HIGH);
	USART_voidInit();
while(1){	
	USART_voidRecieve(&Start_U2); //IF PASSWORD IS TURE IN MICROCONTROLLER 1 -> INITIALIZE MICROCONTROLLER 
	if(Start_U2 == 1)
	{
		LCD_GoToWriteString(1,5,"CONTROL ON!");  
	break;}}
	LCD_Init();

	while (1)
	{
		LCD_GoToWriteString(2,0,"TO ENTER PRESS START!");
		_delay_ms(100);
		InteractiveLCD();
		LCD_ClearDisplay();
		Temp_Monitoring();
		



	}

}



































//u16 arrayToNum(u16* arr, u16 length) {
//	u16 num = 0;
//    for (u16 i = 0; i < length; i++) {
//        num = num * 10 + arr[i];
//    }
//    return num;
//}
//
//void Pass(u16 *Pass)
//{
//	LCD_Init();
//	u16 num;
//u8 Flag , i;
//	u16 MultiArr[4] =
//	{ 1000, 100, 10, 1 };
//	KP_stConfiguration KP1 =
//	{ .KP_Colum1_PORT = DIO_u8PORTA, .KP_Colum2_PORT =
//	DIO_u8PORTA, .KP_Colum3_PORT = DIO_u8PORTA, .KP_Colum4_PORT =
//	DIO_u8PORTA, .KP_Row1_PORT = DIO_u8PORTA, .KP_Row2_PORT = DIO_u8PORTA,
//			.KP_Row3_PORT = DIO_u8PORTA, .KP_Row4_PORT = DIO_u8PORTA,
//			.KP_Colum1_PIN = DIO_u8PIN0, .KP_Colum2_PIN = DIO_u8PIN1,
//			.KP_Colum3_PIN = DIO_u8PIN2, .KP_Colum4_PIN = DIO_u8PIN3,
//			.KP_Row1_PIN =
//			DIO_u8PIN4, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
//			.KP_Row4_PIN = DIO_u8PIN7 };
//	Init_KP(&KP1);
//
//	while (Flag < 4) //loop till the user finish inserting the pass
//	{
//		u8 key_pressed = 0xFF; //return the variable that holds the pressed key from keypad to its initial value
//		while (key_pressed == 0xFF) //repeat till the user press any key
//		{
//			
//			key_pressed = Read_KP(&KP1); //if the user pressed any button in keypad save the value in key_pressed
//			
//		}
//		MultiArr[Flag] = key_pressed;
//		 num = arrayToNum(MultiArr, 4);
//
//     
//     						  
//
//		Flag++;
//	
//	}
//	
//	*Pass = num;
//	
//
//    u8 first4digits = *Pass / 100;
//	u8 last4digits = *Pass % 100;
//	
//		TWI_voidMaterInit(0x01);
//		EEPROM_voidSendData(0x1234, first4digits);
//		EEPROM_voidRecieveData(0x1234, &first4digits);
//		EEPROM_voidSendData(0x1245, last4digits);
//		EEPROM_voidRecieveData(0x1245, last4digits);
//
//	}
//	void main()
//	{
//u16 x;		
//u16 *p = &x;
//
//
//		LCD_Init();
//		u16 data ;
//		Pass(&data);
//
//u16 z,y;
//
//		EEPROM_voidRecieveData(0x1234, &z);
//		LCD_WriteNumber(z);
//		EEPROM_voidRecieveData(0x1245, &y);
//				LCD_WriteNumber(y);

//	}
//

/*
 * InteractiveLCD_Prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Hanos_000
 */
//#include"../LIB/STD_TYPES.h"
//#include"../LIB/BIT_MATH.h"
//#include<util/delay.h>
//#include "../HAL/Key_Pad/KP_Interface.h"
//#include "../HAL/Key_Pad/KP_Private.h"
//#include"../MCAL/TWI/TWI_Interface.h"
//#include"../HAL/EEPROM/EEPROM_Interface.h"
//#include"../MCAL/DIO/DIO_Interface.h"
//#include"../HAL/LCD/LCD_interface.h"
//#include"../TMU/TMU_Interface.h"
///////////////////////////////////////////////////////////////////////////
/*NO NEED IN MASTER */
////////////////////////////////////////////////////////////////////////////
//u8 Act_temp;
//u8 Temp;
//Clock_Num[6];
//void InteractiveLCD()
//{
//	u8 temp;
//	KP_stConfiguration KP1 =
//	{ .KP_Colum1_PORT = DIO_u8PORTC, .KP_Colum2_PORT =
//	DIO_u8PORTC, .KP_Colum3_PORT = DIO_u8PORTC, .KP_Colum4_PORT =
//	DIO_u8PORTC, .KP_Row1_PORT = DIO_u8PORTC, .KP_Row2_PORT = DIO_u8PORTC,
//			.KP_Row3_PORT = DIO_u8PORTC, .KP_Row4_PORT = DIO_u8PORTC,
//			.KP_Colum1_PIN = DIO_u8PIN0, .KP_Colum2_PIN = DIO_u8PIN1,
//			.KP_Colum3_PIN = DIO_u8PIN2, .KP_Colum4_PIN = DIO_u8PIN3,
//			.KP_Row1_PIN =
//			DIO_u8PIN4, .KP_Row2_PIN = DIO_u8PIN5, .KP_Row3_PIN = DIO_u8PIN6,
//			.KP_Row4_PIN = DIO_u8PIN7 };
//	Init_KP(&KP1);
//
//	if (1) // Slave start SPI
//	{
//		LCD_Init();
//
//		LCD_GoToWriteString(0, 6, "WELCOME!");
//		LCD_GoToWriteString(2, 0, "FOR SETTING ENTER'+'");
//		LCD_GoToWriteString(3, 0, "TEMPERATURE IS:");
//		LM35_voidReadValue(DIO_u8PIN0, &Temp);
//
//		LCD_GoToWriteNumber(3, 15, Temp);
//		LCD_GoToWriteString(3, 17, "C");
//		
//
//		u8 key_pressed = 0xFF;
//		while (key_pressed == 0xFF)
//		{
//			key_pressed = Read_KP(&KP1);
//		}
//
//		if (key_pressed == '+')
//		{
//			LCD_ClearDisplay();
//
//			LCD_GoToWriteString(0, 0, "SETTING:");
//			LCD_GoToWriteString(1, 0, "1-SECURITY");
//			LCD_GoToWriteString(2, 0, "2-SERVICES");
//			LCD_GoToWriteString(3, 0, "3-CLOSE LCD");
//			while (1)
//			{
//				key_pressed = 0xFF;
//				while (key_pressed == 0xFF)
//				{
//					key_pressed = Read_KP(&KP1);
//				}
//				if (key_pressed == 1) //SECURITY
//				{
//					LCD_GoToWriteString(0, 0, "SECURITY");
//					LCD_GoToWriteString(1, 0, "1-CHANGE PASSWORD");
//					LCD_GoToWriteString(2, 0, "2-ADD EMERGENCY NUM");
//					LCD_GoToWriteString(3, 0, "3-ADD PHONE NUM");
//
//					while (1)
//					{
//						key_pressed = 0xFF;
//						while (key_pressed == 0xFF)
//						{
//							key_pressed = Read_KP(&KP1);
//						}
//						if (key_pressed == 1) // Change Password
//						{
//							LCD_ClearDisplay();
//							LCD_WriteString(":)");
//
//						}
//						else if (key_pressed == 2) //ADD Emerg
//						{
//							LCD_ClearDisplay();
//							Add_Emergn_NUM();
//
//						}
//						else if (key_pressed == 3) //ADD Num
//						{
//							LCD_ClearDisplay();
//							Add_Phone_NUM();
//
//						}
//
//						break;
//					}
//
//				}
//				else if (key_pressed == 2) //  
//				{
//					LCD_GoToWriteString(0, 0, "SERVICES");
//					LCD_GoToWriteString(1, 0, "1-SET DAILY ACT");
//					LCD_GoToWriteString(2, 0, "2-SET CLOCK");
//					LCD_GoToWriteString(3, 0,
//							"3-MORE..                        ");
//
//					while (1)
//					{
//						key_pressed = 0xFF;
//						while (key_pressed == 0xFF)
//						{
//							key_pressed = Read_KP(&KP1);
//						}
//						if (key_pressed == 1) //SET DAILY ACTIVITIES
//						{
//							LCD_ClearDisplay();
//							LCD_WriteString("SET DAILY");
//
//						}
//						else if (key_pressed == 2) //SET CLOCK
//						{
//							LCD_ClearDisplay();
//							 SET_Time();
//
//						}
//						else if (key_pressed == 3) //MORE..
//						{
//
//							LCD_GoToWriteString(1, 0, "4-SET TEMPERATURE");
//							LCD_GoToWriteString(2, 0, "5-ELECTRICITY MANAGE");
//							LCD_GoToWriteString(3, 0, "6-TURN DEVICE ON/OFF");
//
//							while (1)
//							{
//								key_pressed = 0xFF;
//								while (key_pressed == 0xFF)
//								{
//									key_pressed = Read_KP(&KP1);
//								}
//								if (key_pressed == 4) //SET TEMP
//								{
//									LCD_ClearDisplay();
//									Set_Temp(&Act_temp);
//
//								}
//								else if (key_pressed == 5) //ELECTRICITY MANAGING
//								{
//									LCD_ClearDisplay();
//									LCD_WriteString("ELECTRICITY MANAGING");
//
//								}
//								else if (key_pressed == 6) //TURN DEVICE ON/OFF
//								{
//									SET_DEVICE();
//
//								}
//
//								break;
//							}
//						}
//
//						break;
//					}
//				}
//
//				break;
//			}
//		}
//	}
//
//}
//
////					
////					if (key_pressed == '#')
////					{
////						LCD_ClearDisplay(); //3MAL #
////						LCD_GoToWriteString(0, 0, "SETTING:");
////						LCD_GoToWriteString(1, 0, "1-SECURITY");
////						LCD_GoToWriteString(2, 0, "2-SERVICES");
////						LCD_GoToWriteString(3, 0, "3-CLOSE LCD");
////						while (1)
////						{
////							if (key_pressed == '1') //SECURITY
////							{
////								LCD_GoToWriteString(0, 0, "SECURITY");
////								LCD_GoToWriteString(1, 0, "1-CHANGE PASSWORD");
////								LCD_GoToWriteString(2, 0, "2-ADD EMERGENCY NUM");
////								LCD_GoToWriteString(3, 0, "3-ADD PHONE NUM");
////								_delay_ms(200);
////								while (1)
////								{
////									if (1) // Change Password
////									{
////										_delay_ms(200);
////										while (1)
////										{
////											//do operation
////										}
////	
////									}
////	
////									else if (2) //ADD EMERGENCY NUM
////									{
////										_delay_ms(200);
////										while (1)
////										{
////											//do operation
////										}
////									}
////									else if (3) //ADD PHONE NUMBER
////									{
////										_delay_ms(200);
////										while (1)
////										{
////											//do operation
////										}
////									}
////									else
////									{
////	
////									} // break
////								}
////							}
////						}
////					}
////			}
////		}
////}	
//
////	while (1)
////	{
////
////		if (1) // Slave start SPI
////		{
////			LCD_Init();
////
////			LCD_GoToWriteString(0, 4, "WELCOME");
////			LCD_GoToWriteString(1, 0, "FOR SETTING ENTER #");
////			_delay_ms(500);
////			u8 key_pressed = 0xFF; 
////			while (key_pressed == 0xFF) 
////			{key_pressed = Read_KP(&KP1);} 
////
////				
////				if (key_pressed == '#')
////				{
////					LCD_ClearDisplay(); //3MAL #
////					LCD_GoToWriteString(0, 0, "SETTING:");
////					LCD_GoToWriteString(1, 0, "1-SECURITY");
////					LCD_GoToWriteString(2, 0, "2-SERVICES");
////					LCD_GoToWriteString(3, 0, "3-CLOSE LCD");
////					while (1)
////					{
////						if (key_pressed == '1') //SECURITY
////						{
////							LCD_GoToWriteString(0, 0, "SECURITY");
////							LCD_GoToWriteString(1, 0, "1-CHANGE PASSWORD");
////							LCD_GoToWriteString(2, 0, "2-ADD EMERGENCY NUM");
////							LCD_GoToWriteString(3, 0, "3-ADD PHONE NUM");
////							_delay_ms(200);
////							while (1)
////							{
////								if (1) // Change Password
////								{
////									_delay_ms(200);
////									while (1)
////									{
////										//do operation
////									}
////
////								}
////
////								else if (2) //ADD EMERGENCY NUM
////								{
////									_delay_ms(200);
////									while (1)
////									{
////										//do operation
////									}
////								}
////								else if (3) //ADD PHONE NUMBER
////								{
////									_delay_ms(200);
////									while (1)
////									{
////										//do operation
////									}
////								}
////								else
////								{
////
////								} // break
////							}
////
////						}
////						else if (2)
////						{
////
////						}
////						else if (3) // close LCD
////						{
////							//Back
////						}
////
////						else
////						{
////
////						}
////					}
////				}
////			
////		}
////		else
////		{
////
////		}
////	}
////
////}
//
////void main()
//// {
//// 	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_INPUT);
//// 	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_INPUT);
//// 	DIO_VoidSetPinValue(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_HIGH);
//// 	DIO_VoidSetPinValue(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_HIGH);
//// 
//// 	LCD_Init();
//// 	TMU_CreateTask(LCD, 40, 0);
//// 
//// 	while (1)
//// 	{
//// 
//// 		LCD(&X, &Y);
//// 
//// 		if (X == DIO_u8PIN_LOW)
//// 		{
//// 			LCD_ClearDisplay();
//// 			LCD_WriteString("Welcome");
//// 			//LCD_WriteNumber(B_Next);
//// 
//// 			B_Next++;
//// 			_delay_ms(200);
//// 			
//// 			if (B_Next >= 2)
//// 			{
//// 				LCD_ClearDisplay();
//// 				LCD_WriteString("Setting");
//// 				//LCD_WriteNumber(B_Next);
//// 				B_Next++;
//// 				_delay_ms(200);
//// 				if (B_Next >= 4)
//// 				{
//// 					LCD_ClearDisplay();
//// 					LCD_WriteString("Security");
//// 					//LCD_WriteNumber(B_Next);
//// 					_delay_ms(200);
//// 					B_Next = 0;
//// 				}
//// 
//// 			}
//// 
//// 		}
//// 
//// 	}
//// }	

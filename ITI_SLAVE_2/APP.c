///*
// * main2.c
// *
// *  Created on: Sep 4, 2023
// *      Author: Hanos_000
// */
#include"LIB/STD_TYPES.h"
#include"LIB/BIT_MATH.h"
#include"MCAL/DIO/DIO_Interface.h"
#include"HAL/Key_Pad/KP_Interface.h"
#include"SERVICE/Services_Interface.h"
#include"TMU/TMU_Interface.h"
#include"MCAL/USART/USART_Interface.h"
#include<util/delay.h>








void main()
{
	
	LCD_Init();
		DIO_VoidSetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_INPUT);
		DIO_VoidSetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
		LCD_Init();
//USE RTOS TO CREATE TASK FOR TIMER 		
TMU_CreateTask(TIMER,1000,0); 
//USE RTOS TO CREATE TASK FOR SYSTEM TEMPERATURE STATE
TMU_CreateTask(SystemState_Setter,50,1);
TMU_Start_Scheduler();
while(1)
{

	
}
}
















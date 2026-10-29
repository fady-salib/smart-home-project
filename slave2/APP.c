///*
// * main2.c
// *
// *  Created on: Sep 4, 2023
// *      Author: Hanos_000
// */
#include"LIB/STD_TYPES.h"
#include "HAL/LCD/LCD_interface.h"
#include"LIB/BIT_MATH.h"
#include"MCAL/DIO/DIO_Interface.h"
#include"HAL/Key_Pad/KP_Interface.h"
#include"SERVICE/Services_Interface.h"
#include"TMU/TMU_Interface.h"
#include"MCAL/USART/USART_Interface.h"
#include<util/delay.h>








int main(void)
{

	LCD_Init();
		DIO_VoidSetPinDirection(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_INPUT);
		DIO_VoidSetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
		LCD_Init();
//Cooperative periodic clock task
TMU_CreateTask(TIMER,1000,2);
//Cooperative temperature and clock-input tasks
TMU_CreateTask(SystemState_Setter,50,0);
TMU_CreateTask(Clock_Input,20,1);
TMU_Start_Scheduler();
while(1)
{
    TMU_Dispatch();


}
}
















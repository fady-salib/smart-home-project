/*
 * LM35_Prog.c
 *
 *  Created on: Aug 29, 2023
 *      Author: M.H
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"LM35_Interface.h"
#include "../../../common/HomeLogic.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../MCAL/ADC/ADC_Interface.h"


void LM35_voidReadValue(u8 Copy_u8Pin,u8 *Copy_u16value){


	DIO_VoidSetPinDirection(DIO_u8PORTA,Copy_u8Pin,DIO_u8PIN_INPUT);
	ADC_voidInit();
	u16 raw = 0;
	if (Copy_u16value == NULL) return;
	ADC_StartConv(Copy_u8Pin, &raw);
	*Copy_u16value = home_lm35_celsius(raw);

}
/*Used Driver*/

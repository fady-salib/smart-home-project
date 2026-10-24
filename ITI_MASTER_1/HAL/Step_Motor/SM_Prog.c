/*
 * Prog.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Hanos_000
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<util/delay.h>
#include"../../MCAL/DIO/DIO_Interface.h"
#include"SM_Interface.h"

void Init_SM(SM_st *Copy_SM_st)
{
	DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin, DIO_u8PIN_LOW);
	DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin, DIO_u8PIN_LOW);
	DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin, DIO_u8PIN_LOW);
	DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin, DIO_u8PIN_LOW);
	
	u8 i, j;
	DIO_VoidSetPortDirection(Copy_SM_st->SM_Port, DIO_u8PORT_OUTPUT);
	if (Copy_SM_st->Step_Type == Full_Step)
	{
		if (Copy_SM_st->SM_Direction == Counter_Clock_Wise)
		{
			for (j = 0; j < Copy_SM_st-> SM_No_of_Steps; j++)
			{
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
						DIO_u8PIN_HIGH);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
				DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
						DIO_u8PIN_HIGH);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
				DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
						DIO_u8PIN_HIGH);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
				DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
				DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
						DIO_u8PIN_HIGH);
				_delay_ms(5);
			}
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin, DIO_u8PIN_LOW);

		}

		else if (Copy_SM_st->SM_Direction == Clock_Wise)
		{
			for (j = 0; j < Copy_SM_st-> SM_No_of_Steps; j++)
			{
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
						DIO_u8PIN_HIGH);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
						DIO_u8PIN_HIGH);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
						DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
						DIO_u8PIN_HIGH);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
						DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
						DIO_u8PIN_HIGH);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
						DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
						DIO_u8PIN_LOW);
				_delay_ms(5);
			
			}
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin, DIO_u8PIN_LOW);
		}
	}

	else if (Copy_SM_st->Step_Type == Half_Step)
	{
		if (Copy_SM_st->SM_Direction == Counter_Clock_Wise)
		{
			for (j = 0; j < Copy_SM_st-> SM_No_of_Half_Steps; j++)
			{
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
						DIO_u8PIN_HIGH);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
				DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
						DIO_u8PIN_HIGH);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
				DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
						DIO_u8PIN_HIGH);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
				DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
						DIO_u8PIN_HIGH);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
				DIO_u8PIN_LOW);
				_delay_ms(5);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
						DIO_u8PIN_HIGH);
				
			}
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin, DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin, DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin, DIO_u8PIN_LOW);
				DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin, DIO_u8PIN_LOW);
		}
	
	

	
		else if (Copy_SM_st->SM_Direction == Clock_Wise)
	
		{
		for (j = 0; j < Copy_SM_st-> SM_No_of_Half_Steps; j++)
		{
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
					DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
					DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
			DIO_u8PIN_LOW);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
					DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin,
			DIO_u8PIN_LOW);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
					DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin,
			DIO_u8PIN_LOW);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin,
					DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin,
			DIO_u8PIN_LOW);
			
		}
		DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Blue_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Pink_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Yellow_Pin, DIO_u8PIN_LOW);
			DIO_VoidSetPinValue(Copy_SM_st->SM_Port, Copy_SM_st->Orange_Pin, DIO_u8PIN_LOW);
	}
	}

}

//Used Driver

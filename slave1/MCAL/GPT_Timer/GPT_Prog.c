/*
 * GPT_Prog.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Hanos_000
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../Global_INT/Global_INT_Interface.h"
#include "../GPT_Timer/GPT_Interface.h"
#include "../GPT_Timer/GPT_Private.h"

FUNC_PTR Global_Timer0_CBF = NULL;

void __vector_10(void)__attribute((signal,used));
void __vector_11(void)__attribute((signal,used));

void GPT_Init(GPT_stConfig *Copy_stConfig)
{
	if (Copy_stConfig->GPT_Timer == GPT_Timer0)
	{
		if (Copy_stConfig->GPT_WG_Mode == GPT_Normal)
		{
			CLR_BIT(Timer_TCCR0_REG, TCCR0_WGM00_BIT);
			CLR_BIT(Timer_TCCR0_REG, TCCR0_WGM01_BIT);
			Timer_TCCR0_REG |= Copy_stConfig->GPT_Prescaler;
			Timer_TCNT0_REG = Copy_stConfig->GPT_Preload;
			Global_Timer0_CBF = Copy_stConfig->GPT_OVF_CBF;
			SET_BIT(Timer_TIMSK_REG, TIMSK_TOIE0_BIT);
			G_INT_Enable();
		}
		if (Copy_stConfig->GPT_WG_Mode == GPT_CTC)
		{
			CLR_BIT(Timer_TCCR0_REG, TCCR0_WGM00_BIT);
			SET_BIT(Timer_TCCR0_REG, TCCR0_WGM01_BIT);
			Timer_TCCR0_REG |= Copy_stConfig->GPT_Prescaler;
			Timer_OCR0_REG = Copy_stConfig->GPT_COM_Value;
			Global_Timer0_CBF = Copy_stConfig->GPT_OVF_CBF;
			SET_BIT(Timer_TIMSK_REG, TIMSK_OCIE0_BIT);
			G_INT_Enable();
		}
		else
		{

		}
	}
	else
	{

	}
}

void GPT_Set_Preload(u8 Copy_u8Preload)
{
	Timer_TCNT0_REG = Copy_u8Preload;
}


void __vector_10(void)
{
	if (Global_Timer0_CBF != NULL)
	{
		Global_Timer0_CBF();
	}
}
void __vector_11(void)
{
	if (Global_Timer0_CBF != NULL)
	{
		Global_Timer0_CBF();
	}
}

//USED DRIVER 

/*
 * EXT_INT_Prog.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Hanos_000
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../Global_INT/Global_INT_Interface.h"
#include"EXT_INT_Private.h"
#include"EXT_INT_Config.h"
#include"EXT_INT_Interface.h"

FUNC_PTR Global_EXTI0_CPF = NULL;
FUNC_PTR Global_EXTI1_CPF = NULL;
FUNC_PTR Global_EXTI2_CPF = NULL;

void __vector_1(void)__attribute((signal,used));
void __vector_2(void)__attribute((signal,used));
void __vector_3(void)__attribute((signal,used));



void EXT_INT_Init(EXTI_St *Copy_EXT_INT_st)
{
	/*The External Interrupt 1 is activated by if the SREG I-bit and the
	corresponding interrupt mask in the GICR are set.*/
	
	u8 check = 1;
	if (Copy_EXT_INT_st->EXT_INT == EXT_INT_0)
	{
		
		
		if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_0_Low_Level_SC)
		{
			CLR_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
		}
		else if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_0_Any_Change_SC)
		{
			SET_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
		}
		else if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_0_Falling_Edge_SC)
		{
			CLR_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
		}
		else if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_0_Rising_Edge_SC)
		{
			SET_BIT(MCUCR_REG, MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC01_BIT);
		}
		else
		{
			check = 0;
    //Prevent Enable The global interrupt
		}
		if (check == 1)
		{
			G_INT_Enable();
			SET_BIT(GICR_REG, GICR_INT0_BIT);
			
			Global_EXTI0_CPF = Copy_EXT_INT_st ->EXT_INT_CBF;
		}

	}
	else if (Copy_EXT_INT_st->EXT_INT == EXT_INT_1)
	{
		if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_1_Low_Level_SC)
		{
			CLR_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
		}
		else if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_1_Any_Change_SC)
		{
			SET_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			CLR_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
		}
		else if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_1_Falling_Edge_SC)
		{
			CLR_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
		}
		else if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_1_Rising_Edge_SC)
		{
			SET_BIT(MCUCR_REG, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR_REG, MCUCR_ISC11_BIT);
		}
		else
		{
			check = 0;

		}
		if (check == 1)
		{
			G_INT_Enable();
			SET_BIT(GICR_REG, GICR_INT1_BIT);
			
			Global_EXTI1_CPF = Copy_EXT_INT_st ->EXT_INT_CBF;
		}

	}
	else if (Copy_EXT_INT_st->EXT_INT == EXT_INT_2)
	{
		if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_2_Falling_Edge_SC)
		{
			CLR_BIT(MCUCSR_REG, MCUCSR_ISC2);

		}
		else if (Copy_EXT_INT_st->EXT_INT_SC == EXT_INT_2_Rising_Edge_SC)
		{
			SET_BIT(MCUCSR_REG, MCUCSR_ISC2);

		}
		else
		{
			check = 0;
		}
		if (check == 1)
		{
			G_INT_Enable();
			SET_BIT(GICR_REG, GICR_INT2_BIT);
			
			Global_EXTI2_CPF = Copy_EXT_INT_st ->EXT_INT_CBF;
		}
	}
	else
	{

	}
}

void EXT_INT_Disable(EXTI_St *Copy_EXT_INT_st)
{
	if (Copy_EXT_INT_st->EXT_INT == EXT_INT_0)
	{
		G_INT_Disable();
		CLR_BIT(GICR_REG, GICR_INT0_BIT);
		
	}
	else if (Copy_EXT_INT_st->EXT_INT == EXT_INT_1)
	{
		G_INT_Disable();
		CLR_BIT(GICR_REG, GICR_INT1_BIT);
		
	}
	else if (Copy_EXT_INT_st->EXT_INT == EXT_INT_2)
	{
		G_INT_Disable();
		CLR_BIT(GICR_REG, GICR_INT2_BIT);
		
	}
	else
	{

	}

}

void __vector_1(void)
{
	if (Global_EXTI0_CPF != NULL)
	{
		Global_EXTI0_CPF();
	}

}
void __vector_2(void)
{
	if (Global_EXTI1_CPF != NULL)
		{
		Global_EXTI1_CPF();
		}

}
void __vector_3(void)
{
	if (Global_EXTI2_CPF != NULL)
		{
		Global_EXTI2_CPF();
		}

}


//Used Driver

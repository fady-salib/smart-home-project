/*
 * TMU_Prog.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Hanos_000
 */

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/GPT_Timer/GPT_Interface.h"
#include"../MCAL/Global_INT/Global_INT_Interface.h"
#include"TMU_Config.h"
#include"TMU_Private.h"
#include"TMU_Interface.h"

static TCB_t Tasks_Arr[TMU_Tasks_Num] =
{
{ NULL } };

void TMU_CreateTask(void (*Copy_ptr_Func), u16 Copy_Periodicity,u8 Copy_Priority)
{
	if (Tasks_Arr[Copy_Priority].Pftask == NULL)
	{
		Tasks_Arr[Copy_Priority].Pftask = Copy_ptr_Func;
		Tasks_Arr[Copy_Priority].Periodicity = Copy_Periodicity;
		Tasks_Arr[Copy_Priority].Task_State = Task_Resumed;
		
	}
}

void TMU_Delete_Task(u8 Copy_Priority)
{
	Tasks_Arr[Copy_Priority].Pftask = NULL;
}

void TMU_Suspend_Task(u8 Copy_Priority)
{
	Tasks_Arr[Copy_Priority].Task_State = Task_Suspended;
}

void TMU_Resume_Task(u8 Copy_Priority)
{
	Tasks_Arr[Copy_Priority].Task_State = Task_Resumed;
}

void TMU_Start_Scheduler(void)
{
	GPT_stConfig Timer0 =
		{
			.GPT_Timer = GPT_Timer0, 
			.GPT_WG_Mode = GPT_CTC,
			.GPT_Prescaler = GPT_Prescaler_64 ,
			.GPT_COM_Value = 125, 
			.GPT_OVF_CBF = Scheduler
		};
		
	  GPT_Init(&Timer0);


	G_INT_Enable();
}

void Scheduler(void)
{
	u8 Local_Counter = 0;
	static u16 Local_Index = 0;
	Local_Index++;

	for (Local_Counter = 0; Local_Counter < TMU_Tasks_Num; Local_Counter++)
	{

		if (Tasks_Arr[Local_Counter].Pftask != NULL)
		{
			if (Tasks_Arr[Local_Counter].Task_State == Task_Resumed)
			{	
				if (Local_Index % Tasks_Arr[Local_Counter].Periodicity == 0)
				{
					Tasks_Arr[Local_Counter].Pftask();
				}
		}
	}
}
}

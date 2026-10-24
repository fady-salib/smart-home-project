/*
 * TMU_Private.h
 *
 *  Created on: Aug 30, 2023
 *      Author: Hanos_000
 */

#ifndef COTS_5_RTOS_STACK_1__RTOS_TMU_PRIVATE_H_
#define COTS_5_RTOS_STACK_1__RTOS_TMU_PRIVATE_H_

typedef enum 
{
	Task_Resumed = 0,
	Task_Suspended
	
}enum_Task_State;




typedef struct
{
	void(*Pftask)(void);
	u16 Periodicity;
	
	enum_Task_State Task_State;
}TCB_t ;

void Scheduler(void);
		
#endif /* COTS_5_RTOS_STACK_1__RTOS_TMU_PRIVATE_H_ */

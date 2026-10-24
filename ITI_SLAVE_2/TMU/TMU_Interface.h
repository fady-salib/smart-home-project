/*
 * TMU_Interface.h
 *
 *  Created on: Aug 30, 2023
 *      Author: Hanos_000
 */

#ifndef COTS_5_RTOS_STACK_1__RTOS_TMU_INTERFACE_H_
#define COTS_5_RTOS_STACK_1__RTOS_TMU_INTERFACE_H_

void TMU_CreateTask(void(*Copy_ptr_Func), u16 Copy_Periodicity,u8 Copy_Priority);

void TMU_Suspend_Task(u8 Copy_Priority);
void TMU_Resume_Task(u8 Copy_Priority);
void TMU_Delete_Task(u8 Copy_Priority);




void TMU_Start_Scheduler(void);

#endif /* COTS_5_RTOS_STACK_1__RTOS_TMU_INTERFACE_H_ */

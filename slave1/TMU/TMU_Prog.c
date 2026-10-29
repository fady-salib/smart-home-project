/*
 * TMU_Prog.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Hanos_000
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPT_Timer/GPT_Interface.h"
#include "../MCAL/Global_INT/Global_INT_Interface.h"
#include "TMU_Config.h"
#include "TMU_Interface.h"
#include "TMU_Private.h"
#include <util/atomic.h>

static volatile TCB_t Tasks_Arr[TMU_Tasks_Num];

void TMU_CreateTask(void (*callback)(void), u16 period, u8 priority)
{
    if (priority >= TMU_Tasks_Num || !callback || !period) return;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if (!Tasks_Arr[priority].Pftask) {
            Tasks_Arr[priority].Periodicity = period;
            Tasks_Arr[priority].Remaining = period;
            Tasks_Arr[priority].Pending = 0;
            Tasks_Arr[priority].Task_State = Task_Resumed;
            Tasks_Arr[priority].Pftask = callback;
        }
    }
}
void TMU_Delete_Task(u8 priority)
{
    if (priority >= TMU_Tasks_Num) return;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        Tasks_Arr[priority].Pftask = NULL;
        Tasks_Arr[priority].Pending = 0;
    }
}
void TMU_Suspend_Task(u8 priority)
{
    if (priority >= TMU_Tasks_Num) return;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        Tasks_Arr[priority].Task_State = Task_Suspended;
        Tasks_Arr[priority].Pending = 0;
    }
}
void TMU_Resume_Task(u8 priority)
{
    if (priority >= TMU_Tasks_Num) return;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        Tasks_Arr[priority].Remaining = Tasks_Arr[priority].Periodicity;
        Tasks_Arr[priority].Task_State = Task_Resumed;
    }
}
void TMU_Start_Scheduler(void)
{
    GPT_stConfig timer = {.GPT_Timer = GPT_Timer0, .GPT_WG_Mode = GPT_CTC,
        .GPT_Prescaler = GPT_Prescaler_64, .GPT_COM_Value = 124,
        .GPT_OVF_CBF = Scheduler}; /* 8 MHz / 64 / (124+1) = 1 kHz */
    GPT_Init(&timer);
}
void Scheduler(void)
{
    /* ISR: mark due work only. Never run ADC, LCD or keypad waits here. */
    for (u8 i = 0; i < TMU_Tasks_Num; ++i) {
        if (Tasks_Arr[i].Pftask && Tasks_Arr[i].Task_State == Task_Resumed &&
                Tasks_Arr[i].Remaining && --Tasks_Arr[i].Remaining == 0) {
            Tasks_Arr[i].Remaining = Tasks_Arr[i].Periodicity;
            Tasks_Arr[i].Pending = 1; /* coalesce missed periods */
        }
    }
}
void TMU_Dispatch(void)
{
    for (u8 i = 0; i < TMU_Tasks_Num; ++i) {
        void (*callback)(void) = NULL;
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            if (Tasks_Arr[i].Pending && Tasks_Arr[i].Task_State == Task_Resumed) {
                callback = Tasks_Arr[i].Pftask;
                Tasks_Arr[i].Pending = 0;
            }
        }
        if (callback) callback();
    }
}

#include <assert.h>
#include <stdio.h>
#include "../master/TMU/TMU_Prog.c"
static unsigned calls;
static void task(void) { ++calls; }
void GPT_Init(GPT_stConfig *config)
{
    assert(config->GPT_COM_Value == 124);
    assert(config->GPT_OVF_CBF == Scheduler);
}
int main(void)
{
    TMU_CreateTask(task, 0, 0);
    TMU_CreateTask(task, 1, TMU_Tasks_Num);
    TMU_CreateTask(NULL, 1, 0);
    Scheduler(); TMU_Dispatch(); assert(calls == 0);
    TMU_CreateTask(task, 10, 0);
    for (unsigned i=0; i<70000; ++i) { Scheduler(); TMU_Dispatch(); }
    assert(calls == 7000); /* no global uint16 tick rollover artifact */
    for (unsigned i=0; i<30; ++i) Scheduler();
    assert(calls == 7000); /* ISR never invokes application callbacks */
    TMU_Dispatch(); assert(calls == 7001); /* missed periods coalesce */
    TMU_Suspend_Task(0);
    for (unsigned i=0; i<100; ++i) { Scheduler(); TMU_Dispatch(); }
    assert(calls == 7001);
    TMU_Resume_Task(0);
    for (unsigned i=0; i<10; ++i) { Scheduler(); TMU_Dispatch(); }
    assert(calls == 7002);
    TMU_Delete_Task(0); Scheduler(); TMU_Dispatch(); assert(calls == 7002);
    TMU_Delete_Task(255); TMU_Suspend_Task(255); TMU_Resume_Task(255);
    TMU_Start_Scheduler();
    puts("PASS scheduler: bounds, zero period, foreground dispatch, coalescing, suspend/resume and rollover");
}

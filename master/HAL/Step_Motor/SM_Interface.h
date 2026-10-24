/*
 * SM_Interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Hanos_000
 */

#ifndef HAL_STEP_MOTOR_SM_INTERFACE_H_
#define HAL_STEP_MOTOR_SM_INTERFACE_H_

typedef struct
{
	
	u8 SM_Port;
	u8 Blue_Pin;
	u8 Pink_Pin;
	u8 Yellow_Pin;
	u8 Orange_Pin;
	u8 Step_Type;
	u8 SM_Direction;
	u8 SM_delay;      //control Speed
	u32 SM_No_of_Steps;
	u32 SM_No_of_Half_Steps;

} SM_st; //pins



#define Full_Step 0
#define Half_Step 1
#define Clock_Wise 2
#define Counter_Clock_Wise 3
//Speed (Max = 10 ms between 2 steps , 5 ms between 2 half steps)
void Init_SM(SM_st *Copy_SM_st);

#endif /* HAL_STEP_MOTOR_SM_INTERFACE_H_ */

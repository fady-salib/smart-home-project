/*
 * GPT_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Hanos_000
 */

#ifndef MCAL_GPT_TIMER_GPT_INTERFACE_H_
#define MCAL_GPT_TIMER_GPT_INTERFACE_H_
//timer0_General_Purpose_Singel_Channel 8-bit

typedef enum GPT_TIMER
{
	GPT_Timer0 = 0 , GPT_Timer_1 ,GPT_Timer_2,
}GPT_enum_Timer;

typedef enum GPT_WG_MODE //Waveform generation mode
{
	GPT_Normal,GPT_CTC = 2
}GPT_enum_WG_Mode;

typedef enum GPT_Prescaler_Select
{
	GPT_Prescaler_0,
	GPT_Prescaler_1,
	GPT_Prescaler_8,
	GPT_Prescaler_64,
	GPT_Prescaler_256,
	GPT_Prescaler_1024,
}GPT_enum_Prescaler;

typedef struct 
{
	GPT_enum_Timer GPT_Timer;
	GPT_enum_WG_Mode GPT_WG_Mode;
	GPT_enum_Prescaler GPT_Prescaler;
	u8 GPT_Preload;
	u8 GPT_COM_Value;
	FUNC_PTR GPT_OVF_CBF;
}GPT_stConfig;

void GPT_Init(GPT_stConfig *Copy_stConfig);
//void GPT_Stop_Timer(GPT_enum_Timer *Copy_enum_Timer);
void GPT_Set_Preload(u8 Copy_u8Preload);
//Init Timer 2
#endif /* MCAL_GPT_TIMER_GPT_INTERFACE_H_ */

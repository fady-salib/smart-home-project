/*
 * EXT_INT_Config.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Hanos_000
 */

#ifndef MCAL_EXT_INT_EXT_INT_CONFIG_H_
#define MCAL_EXT_INT_EXT_INT_CONFIG_H_

typedef enum
{
	EXT_INT_0 , EXT_INT_1, EXT_INT_2 
	
}enuEXTI;
		

typedef enum
{
	EXT_INT_0_Low_Level_SC , EXT_INT_0_Any_Change_SC,
	EXT_INT_0_Falling_Edge_SC ,EXT_INT_0_Rising_Edge_SC,
	EXT_INT_1_Low_Level_SC , EXT_INT_1_Any_Change_SC,
	EXT_INT_1_Falling_Edge_SC ,EXT_INT_1_Rising_Edge_SC,
	EXT_INT_2_Falling_Edge_SC ,EXT_INT_2_Rising_Edge_SC 
	
}enuEXTI_0_1_2_SC; 




typedef struct
{
	enuEXTI EXT_INT;
	enuEXTI_0_1_2_SC EXT_INT_SC;
	FUNC_PTR EXT_INT_CBF;
	
}EXTI_St;


#endif /* MCAL_EXT_INT_EXT_INT_CONFIG_H_ */

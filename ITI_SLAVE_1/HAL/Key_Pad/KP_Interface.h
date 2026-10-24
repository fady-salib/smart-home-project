/*
 * KP_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Hanos_000
 */

#ifndef HAL_KEY_PAD_KP_INTERFACE_H_
#define HAL_KEY_PAD_KP_INTERFACE_H_

typedef struct
{
	u8 KP_Colum1_PORT;
	u8 KP_Colum2_PORT;
	u8 KP_Colum3_PORT;
	u8 KP_Colum4_PORT;
	u8 KP_Row1_PORT;
	u8 KP_Row2_PORT;
	u8 KP_Row3_PORT;
	u8 KP_Row4_PORT;
	u8 KP_Colum1_PIN;
	u8 KP_Colum2_PIN;
	u8 KP_Colum3_PIN;
	u8 KP_Colum4_PIN;
	u8 KP_Row1_PIN;
	u8 KP_Row2_PIN;
	u8 KP_Row3_PIN;
	u8 KP_Row4_PIN;
	
	
}KP_stConfiguration;


void Init_KP(KP_stConfiguration *Copy_pstConfig);
u8 Read_KP(KP_stConfiguration *Copy_pstConfig);

#endif /* HAL_KEY_PAD_KP_INTERFACE_H_ */

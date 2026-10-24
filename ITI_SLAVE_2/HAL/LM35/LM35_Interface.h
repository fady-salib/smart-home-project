/*
 * LM35_Interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: M.H
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

#define LM35_PIN0	0
#define LM35_PIN1	1
#define LM35_PIN2	2
#define LM35_PIN3	3
#define LM35_PIN4	4
#define LM35_PIN5	5
#define LM35_PIN6	6
#define LM35_PIN7	7

void LM35_voidReadValue(u8 Copy_u8Pin,u8 *Copy_u16value);

#endif /* HAL_LM35_LM35_INTERFACE_H_ */

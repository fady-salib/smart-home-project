/*
 * USART_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: M.H
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

void USART_voidInit(void);
void USART_voidTransmit(u8 Copy_u8Data);
void USART_u8Recieve(u8 *Copy_ptu8DataSent);
void USART_voidSendString(u8* Copy_pu8String);
void USART_voidDisable(void);


#endif /* MCAL_USART_USART_INTERFACE_H_ */

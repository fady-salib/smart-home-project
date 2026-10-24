/*
 * USART_Private.h
 *
 *  Created on: Aug 23, 2023
 *      Author: M.H
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

#define USART_UDR_REG	(*(volatile u8*)0x2C)

#define USART_UCSRA_REG	(*(volatile u8*)0x2B)
/*USRA REGISTER BITS*/
#define USART_UCSRA_RXC_BIT		7
#define USART_UCSRA_TXC_BIT		6
#define USART_UCSRA_UDRE_BIT	5
#define USART_UCSRA_FE_BIT		4
#define USART_UCSRA_DOR_BIT		3
#define USART_UCSRA_PE_BIT		2
#define USART_UCSRA_U2X_BIT		1
#define USART_UCSRA_MPCM_BIT	0

#define USART_UCSRB_REG	(*(volatile u8*)0x2A)
/*UCSRB REGISTER BITS*/
#define USART_UCSRB_RXCIE_BIT		7
#define USART_UCSRB_TXCIE_BIT		6
#define USART_UCSRB_UDRIE_BIT	    5
#define USART_UCSRB_RIXEN_BIT		4
#define USART_UCSRB_TXEN_BIT		3
#define USART_UCSRB_UCSZ2_BIT		2
#define USART_UCSRB_RXB8_BIT		1
#define USART_UCSRB_TXB8_BIT	    0

#define USART_UBRRL_REG		(*(volatile u8*)0x29)
#define USART_UBRRH_REG		(*(volatile u8*)0x40)

#define USART_UCSRC_REG	(*(volatile u8*)0x40)
/*UCSRC REGISTER BITS*/
#define USART_UCSRC_URSEL_BIT		7
#define USART_UCSRC_UMSEL_BIT		6
#define USART_UCSRC_UPM1_BIT	    5
#define USART_UCSRC_UPM0_BIT		4
#define USART_UCSRC_USBS_BIT		3
#define USART_UCSRC_UCSZ1_BIT		2
#define USART_UCSRC_UCSZ0_BIT		1
#define USART_UCSRC_UCPOL_BIT	    0



#endif /* MCAL_USART_USART_PRIVATE_H_ */

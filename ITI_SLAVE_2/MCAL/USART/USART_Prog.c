/*
 * USART_Prog.c
 *
 *  Created on: Aug 23, 2023
 *      Author: M.H
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include "USART_Interface.h"




void USART_voidInit(void){
	USART_UCSRB_REG |= (1 << USART_UCSRB_RIXEN_BIT) | (1 << USART_UCSRB_TXEN_BIT);

	USART_UCSRC_REG = (1 <<USART_UCSRC_URSEL_BIT) | (0 << USART_UCSRC_UMSEL_BIT) | (0 << USART_UCSRC_UPM0_BIT)
			| (0 << USART_UCSRC_UPM1_BIT) | (0 << USART_UCSRC_USBS_BIT) | (1 << USART_UCSRC_UCSZ0_BIT)
			| (1 << USART_UCSRC_UCSZ1_BIT) | (0 << USART_UCSRB_UCSZ2_BIT);

	u8 Baud = 51;
	USART_UBRRL_REG = Baud;
	USART_UBRRH_REG = (Baud >> 8);
}
void USART_voidTransmit(u8 Copy_u8Data){
while(GET_BIT(USART_UCSRA_REG,USART_UCSRA_UDRE_BIT)==0){
};
USART_UDR_REG=Copy_u8Data;
}
void USART_voidRecieve(u8 *Copy_ptu8DataSent){

	while(GET_BIT(USART_UCSRA_REG,USART_UCSRA_RXC_BIT)==0){

	}

	*Copy_ptu8DataSent=USART_UDR_REG;
}
void USART_voidSendString(u8* Copy_pu8String)
{

	u8 i;
	while (Copy_pu8String[i] != '\0')
	    {
		USART_voidTransmit(Copy_pu8String[i++]);
	    }
}


void USART_voidDisable(void)
{
    // Clear the USART transmitter and receiver enable bits
    USART_UCSRB_REG &= ~((1 << USART_UCSRB_TXEN_BIT) | (1 << USART_UCSRB_RIXEN_BIT));
}




/*USED Driver*/









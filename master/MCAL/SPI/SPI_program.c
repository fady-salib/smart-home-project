#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"SPI_private.h"
#include"SPI_interface.h"

void SPI_Init_Master(void)
{
	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_OUTPUT); //MOSI
	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN_INPUT); //MISO
	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_OUTPUT); //SCK

	SPCR_REG |= (Data_Order_Mode << SPCR_DORD) | (SPI_Master << SPCR_MSTR)
			| (Clock_Polarity_Mode << SPCR_CPOL)
			| (Clock_Phase_Mode << SPCR_CPHA) | (Clock_Rate_Mode << SPCR_SPR0)
			| (SPI_Enable << SPCR_SPE);

	SPSR_REG |= SPI_Double_Speed_Status;

}
void SPI_Init_Slave(void)
{
	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_INPUT); //MOSI
	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN_OUTPUT); //MISO
	DIO_VoidSetPinDirection(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN_INPUT); //SCK

	SPCR_REG |= (Data_Order_Mode << SPCR_DORD) | (SPI_Slave << SPCR_MSTR)
			| (Clock_Polarity_Mode << SPCR_CPOL)
			| (Clock_Phase_Mode << SPCR_CPHA) | (Clock_Rate_Mode << SPCR_SPR0)
			| (SPI_Enable << SPCR_SPE);

	SPSR_REG |= SPI_Double_Speed_Status;
}

void SPI_Trancieve(u8 Copy_Data_Sent, u8 * Copy_Data_Receieved)
{
	SPDR_REG = Copy_Data_Sent;
	while (GET_BIT(SPSR_REG,SPSR_SPIF) == 0)
		; //until receive
	*Copy_Data_Receieved = SPDR_REG;
}

//USED DRIVER

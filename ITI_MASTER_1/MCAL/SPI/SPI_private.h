

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPDR_REG		*((volatile u8*) 0x2f)
#define SPSR_REG		*((volatile u8*) 0x2e)
#define SPSR_SPIF	7
#define SPSR_WCOL	6
#define SPSR_SPI2X	0

#define SPCR_REG		*((volatile u8*) 0x2d)
#define SPCR_SPIE	7
#define SPCR_SPE	6
#define SPCR_DORD	5
#define SPCR_MSTR	4
#define SPCR_CPOL	3
#define SPCR_CPHA	2
#define SPCR_SPR1	1
#define SPCR_SPR0	0

#define SPI_Master 1
#define SPI_Slave 0

#define Data_Order_LSB 1
#define Data_Order_MSB 0

#define CP_LeadingEdgeRising_TrailingEdgeFalling 0
#define CP_LeadingEdgeFalling_TrailingEdgeRising 1

#define CPH_LeadingEdgeSample_TrailingEdgeSetup 0
#define CPH_LeadingEdgeSetup_TrailingEdgeSample 1

#define Fosc_4 0
#define Fosc_16 1
#define Fosc_64 2
#define Fosc_128 3

#define SPI_Double_Speed_Disable 0
#define SPI_Double_Speed_Enable 1

#define SPI_Enable 1
#define SPI_Disable 0





#endif /* SPI_PRIVATE_H_ */

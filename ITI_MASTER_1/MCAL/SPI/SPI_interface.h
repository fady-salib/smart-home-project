

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_Init_Master(void);

void SPI_Init_Slave(void);


void SPI_Trancieve(u8 Copy_Data_Sent,u8 * Copy_Data_Receieved); 





/*
 * Options : 
 *  1-Data_Order_LSB : LSB of the data word is transmitted first
 *  2-Data_Order_MSB : MSB of the data word is transmitted first
 * */
#define Data_Order_Mode Data_Order_LSB

/*
 * Options : 
 *  1-CP_LeadingEdgeRising_TrailingEdgeFalling 
 *  2-CP_LeadingEdgeFalling_TrailingEdgeRising 
 * */

#define Clock_Polarity_Mode CP_LeadingEdgeRising_TrailingEdgeFalling

/*
 * Options : 
 *  1-CPH_LeadingEdgeSample_TrailingEdgeSetup 
 *  2-CPH_LeadingEdgeSetup_TrailingEdgeSample 
 * */

#define Clock_Phase_Mode CPH_LeadingEdgeSetup_TrailingEdgeSample

/*
 * Options : 
 *  1-Fosc_4 : fosc/4 
 *  2-Fosc_16 : fosc/16
 *  3-Fosc_64 : fosc/64
 *  4-Fosc_128 : fosc/128
 * */
#define Clock_Rate_Mode Fosc_128
/*
 * Options : 
 *  1-SPI_Double_Speed_Enable
 *  2-SPI_Double_Speed_Disable
 * */

#define SPI_Double_Speed_Status SPI_Double_Speed_Disable




#endif /* SPI_INTERFACE_H_ */

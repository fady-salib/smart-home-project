/*
 * ADC_Prog.c
 *
 *  Created on: Aug 28, 2023
 *      Author: M.H
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"ADC_Private.h"
#include"ADC_Config.h"
#include"ADC_Interface.h"



void ADC_voidInit(void){

	/*2- Configure Prescaler*/
	ADC_ADCSRA_REG	|=ADC_PRESCALER;
	/*1-Configuring Voltage Reference*/
	ADC_ADMUX_REG|=(ADC_VOLTAGE_REFRENCE<<ADC_ADMUX_REFS0_BIT);
	/*3-SET ADEN*/
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN_BIT);




}
void ADC_StartConv(u8 Copy_u8SelectedChannel,u16 *Copy_pu16Return){
	if(Copy_u8SelectedChannel<=ADC_CHANNEL7){
		/*1-Select Channel*/
		ADC_ADMUX_REG|=Copy_u8SelectedChannel;
		SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADCSC_BIT);
		while(GET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADCSC_BIT)==1);
		      *Copy_pu16Return=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
		}
		else
		{
			/*NO OPERATION*/
		}

}
/*USED DRIVER*/


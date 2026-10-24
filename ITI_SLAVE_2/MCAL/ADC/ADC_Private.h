/*
 * ADC_Private.h
 *
 *  Created on: Aug 28, 2023
 *      Author: M.H
 */

#ifndef MCAL_ADC_PRIVATE_H_
#define MCAL_ADC_PRIVATE_H_

#define ADC_ADMUX_REG	(*(volatile u8*)0x27)

#define ADC_ADMUX_MUX0_BIT 	0
#define ADC_ADMUX_MUX1_BIT 	1
#define ADC_ADMUX_MUX2_BIT 	2
#define ADC_ADMUX_MUX3_BIT 	3
#define ADC_ADMUX_MUX4_BIT 	4
#define ADC_ADMUX_ADLAR_BIT 5
#define ADC_ADMUX_REFS0_BIT 6
#define ADC_ADMUX_REFS1_BIT 7

#define ADC_ADCSRA_REG	(*(volatile u8*)0x26)

#define ADC_ADCSRA_ADCPS0_BIT	0
#define ADC_ADCSRA_ADCPS1_BIT	1
#define ADC_ADCSRA_ADCPS2_BIT	2
#define ADC_ADCSRA_ADCSC_BIT	6
#define ADC_ADCSRA_ADEN_BIT		7


#define ADC_ADCH_REG 	(*(volatile u8*)0x25)
#define ADC_ADCL_REG	(*(volatile u8*)0x24)
/*Vref selection*/
#define ADC_VOLT_AREF	0
#define ADC_VOLT_AVCC	1
#define ADC_VOLT_I_2	3
/*Prescaler selection*/
#define	ADC_PRESCALER_2  	1
#define	ADC_PRESCALER_4		2
#define	ADC_PRESCALER_8		3
#define	ADC_PRESCALER_16	4
#define	ADC_PRESCALER_32	5
#define ADC_PRESCALER_64	6
#define	ADC_PRESCALER_128	7

#define ADMUX_MASK 0xE0


#endif /* MCAL_ADC_PRIVATE_H_ */

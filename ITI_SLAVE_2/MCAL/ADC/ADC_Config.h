/*
 * ADC_Config.h
 *
 *  Created on: Aug 28, 2023
 *      Author: M.H
 */

#ifndef MCAL_ADC_CONFIG_H_
#define MCAL_ADC_CONFIG_H_
/*
 *OPTIONS
 * ADC_VOLT_AREF
 * ADC_VOLT_AVCC
 * ADC_VOLT_I_2
 * */

#define ADC_VOLTAGE_REFRENCE ADC_VOLT_AVCC
/*
 *	OPTIONS:
 *			ADC_PRESCALER_2
 *			ADC_PRESCALER_4
 *			ADC_PRESCALER_8
 *			ADC_PRESCALER_16
 *			ADC_PRESCALER_32
 *			ADC_PRESCALER_64
 *			ADC_PRESCALER_128
 *
 * */
#define ADC_PRESCALER ADC_PRESCALER_128

#endif /* MCAL_ADC_CONFIG_H_ */

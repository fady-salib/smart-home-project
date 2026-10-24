/*
 * ADC_Interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: M.H
 */





void ADC_voidInit(void);
void ADC_StartConv(u8 Copy_u8SelectedChannel,u16 *Copy_pu16Return);

void ADC_READ_PER(u8 Copy_u8Pin,u8 *Copy_u16value);



/**
 * OPTIONS:
 *			ADC_CHANNEL0
 *			ADC_CHANNEL1
 *			ADC_CHANNEL2
 *			ADC_CHANNEL3
 *			ADC_CHANNEL4
 *			ADC_CHANNEL5
 *			ADC_CHANNEL6
 *			ADC_CHANNEL7
 */
#define ADC_CHANNEL0	0
#define ADC_CHANNEL1	1
#define ADC_CHANNEL2	2
#define ADC_CHANNEL3	3
#define ADC_CHANNEL4	4
#define ADC_CHANNEL5	5
#define ADC_CHANNEL6	6
#define ADC_CHANNEL7	7


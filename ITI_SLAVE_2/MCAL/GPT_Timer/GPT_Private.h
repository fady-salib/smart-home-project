/*
 * Timer_Private.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Hanos_000
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define Timer_TCCR0_REG (*(volatile u8*)0x53)
#define Timer_TCNT0_REG (*(volatile u8*)0x52)
#define Timer_OCR0_REG (*(volatile u8*)0x5C)
#define Timer_TIMSK_REG (*(volatile u8*)0x59)
#define Timer_TIFR_REG (*(volatile u8*)0x58)

#define TCCR0_CS00_BIT 0
#define TCCR0_CS01_BIT 1
#define TCCR0_CS02_BIT 2
#define TCCR0_WGM01_BIT 3
#define TCCR0_COM00_BIT 4
#define TCCR0_COM01_BIT 5
#define TCCR0_WGM00_BIT 6
#define TCCR0_FOC0_BIT 7

#define TIMSK_TOIE0_BIT 0
#define TIMSK_OCIE0_BIT 1

#define TIFR_BIT0_TOV0_BIT 0
#define TIFR_BIT1_OCF0_BIT 1

#endif /* TIMER_PRIVATE_H_ */

/*
 * EXT_INT_Private.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Hanos_000
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_EXT_INT_PRIVATE_H_

#define GICR_REG (*(volatile u8*)0x5B)
#define GIFR_REG (*(volatile u8*)0x5A)
#define MCUCR_REG (*(volatile u8*)0x55)
#define MCUCSR_REG (*(volatile u8*)0x54)

#define MCUCR_ISC00_BIT 0
#define MCUCR_ISC01_BIT 1
#define MCUCR_ISC10_BIT 2
#define MCUCR_ISC11_BIT 3

#define MCUCSR_ISC2 6

#define GICR_INT1_BIT 7
#define GICR_INT0_BIT 6
#define GICR_INT2_BIT 5






#endif /* MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */

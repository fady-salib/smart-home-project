/*
 * STD_TYPES.H
 *
 *  Created on: Aug 15, 2023
 *      Author: fadya
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

#define NULL ((void*)0x00)
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
typedef void(*FUNC_PTR)(void);
#define E_OK 0x01
#define E_NOT_OK 0x00
//used lib
#endif /* LIB_STD_TYPES_H_ */

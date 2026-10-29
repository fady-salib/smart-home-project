/*
 * STD_TYPES.H
 *
 *  Created on: Aug 15, 2023
 *      Author: fadya
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

#include <stdint.h>
#include <stddef.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef float f32;
typedef double f64;
typedef void(*FUNC_PTR)(void);
#define E_OK 0x01
#define E_NOT_OK 0x00
//used lib
#endif /* LIB_STD_TYPES_H_ */

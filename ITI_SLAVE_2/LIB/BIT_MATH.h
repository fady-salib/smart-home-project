/*
 * BIT_MATH.H
 *
 *  Created on: Aug 15, 2023
 *      Author: fadya
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


#define SET_BIT(REG,BIT) (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT) (REG &= (~(1<<BIT)))
#define TOG_BIT(REG,BIT) (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)


//used lib


#endif /* LIB_BIT_MATH_H_ */

/*
 * Global_INT_Prog.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Hanos_000
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"Global_INT_Private.h"
#include"Global_INT_Interface.h"

void G_INT_Enable(void)
{
	SET_BIT(SREG_REG,SREG_REG_I_BIT);
}
void G_INT_Disable(void)
{
	CLR_BIT(SREG_REG,SREG_REG_I_BIT);
}


//Used Driver

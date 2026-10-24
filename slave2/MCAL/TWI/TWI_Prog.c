/*
 * TWI_Prog.c
 *
 *  Created on: Aug 26, 2023
 *      Author: M.H
 */
#include "../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "TWI_Private.h"
#include "TWI_Interface.h"



/*Initialize Master*/
void TWI_voidMaterInit(u8 Copy_u8SlaveAddress)
{
	/*1-Choose Prescaler*/
	TWI_TWBR_REG=(u8)(((FCPU/SCL)-16)/2);
	/*2-Assign Slave Address*/
 TWI_TWAR_REG= (Copy_u8SlaveAddress<<1);
 	 /*3-enable*/
 SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWEN_BIT);
}
/*Initialize Slave*/
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress){

	/*2-Assign Slave Address*/
 TWI_TWAR_REG= (Copy_u8SlaveAddress<<1);
 	 /*3-enable*/
 	 SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWEN_BIT);
}
/*As Master Start Condition*/
void TWI_voidStartCond(void){
	CLR_BIT(TWI_TWCR_REG,TWI_TWCR_TWSTO_BIT);
		/*1-Start Condition*/
		SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWSTA_BIT);
		/*2-CLEAR TWINT FLAG TO START OPERATION*/
		SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT);
		/*3-Wait until flag became 1*/
		while(GET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT)==0);
}
/*As Master write Address on Bus*/
void TWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddressToSend){
	/*Clear Start Condition*/
	//CLR_BIT(TWI_TWCR_REG,TWI_TWCR_TWSTA_BIT);
	/*1-Assign Slave address on data bus And setting bit to enable read*/
	TWI_TWDR_REG=((Copy_u8SlaveAddressToSend<<1) |0x01);
	/*2-Clear Flag To Start Operation*/
	SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT);
	/*3-Wait until flag became 1*/
	while(GET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT)==0);
}
void TWI_voidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddressToSend){
	/*Clear Start Condition*/
	//CLR_BIT(TWI_TWCR_REG,TWI_TWCR_TWSTA_BIT);
	/*1-Assign Slave address on data bus And setting bit to enable read*/
	TWI_TWDR_REG=(Copy_u8SlaveAddressToSend<<1);
	/*2-Clear Flag To Start Operation*/
	SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT);
	/*3-Wait until flag became 1*/
	while(GET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT)==0);
}
/*As Master Write Data On Bus*/
void TWI_voidMasterWriteData(u8 Copy_u8SentData){
	/*Assign Data to bus*/
	TWI_TWDR_REG=Copy_u8SentData;
	/*Clear Flag and wait*/
	SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT);
	/*3-Wait until flag became 1*/
	while(GET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT)==0);
}
/*As Master Read Data On Bus*/
void TWI_voidMasterReadData(u8 *Copy_u8ReceivedData){

	/*1Enable ACK*/
	SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWEA_BIT);
	/*2-Clear Flag and wait*/
	SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT);
	/*3-Wait until flag became 1*/
	while(GET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT)==0);
	/*CHECK FOR ACK*/

	*Copy_u8ReceivedData=TWI_TWDR_REG;
}
/*As Master Stop Condition*/
void TWI_voidStopCond(void){
	CLR_BIT(TWI_TWCR_REG,TWI_TWCR_TWSTA_BIT);
  
	/*1-Stop Condition*/
	SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWSTO_BIT);
	/*2-CLEAR TWINT FLAG TO START OPERATION*/
	SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT);
	/*3-Wait until flag became 1*/
//	while(GET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT)==0);
	
}
u8   TWI_GetStatus(u8 Copy_u8Status)
{
    /*Get status*/
    SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT);
    SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWEA_BIT);
    SET_BIT(TWI_TWCR_REG,TWI_TWCR_TWEN_BIT);
    /*Busy wait for TWINT flag*/
    while(!GET_BIT(TWI_TWCR_REG,TWI_TWCR_TWINT_BIT));
    while((TWI_TWSR_REG & 0xF8) != Copy_u8Status);
    return TWI_TWDR_REG;
}
/*USED DRIVER*/

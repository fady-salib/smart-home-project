/*
 * EEPROM_Prog.c
 *
 *  Created on: Aug 28, 2023
 *      Author: M.H
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../MCAL/TWI/TWI_Interface.h"
#include"EEPROM_Interface.h"
#include<util/delay.h>



void EEPROM_voidSendData(u16 Copy_u16Address,u8 Copy_u8Data){
	/*1-Send Start Condition*/
	TWI_voidStartCond();
	/*2-Send (0,1,0,1,A2,b1,b0,w)*/
	TWI_voidSendSlaveAddressWithWrite((u8) (0b01010000) | (A_2 << 2) | (Copy_u16Address >> 8));
	/*3-Send Address*/
	TWI_voidMasterWriteData((u8)Copy_u16Address);
	/*4-Send Data*/
	TWI_voidMasterWriteData(Copy_u8Data);
	/*5-Send Stop Condition*/
	TWI_voidStopCond();
	_delay_ms(200);
}
void EEPROM_voidRecieveData(u16 Copy_u16Address,u8 *Copy_u8ReceivedData)
{


	/*1-Send Start Condition*/
	TWI_voidStartCond();
	/*2-Send (0,1,0,1,A2,b1,b0,w)*/
	TWI_voidSendSlaveAddressWithWrite((u8) (0b01010000) | (A_2 << 2) | (Copy_u16Address >> 8));
	/*3-Send Address*/
	TWI_voidMasterWriteData((u8)Copy_u16Address);
	/*4-Send repeated start Condition*/
	TWI_voidStopCond();
	TWI_voidStartCond();
	/*5-Send Slave Address with read*/
	TWI_voidSendSlaveAddressWithRead((u8) (0b01010000) | (A_2 << 2) | (Copy_u16Address >> 8));
	TWI_voidMasterReadData(Copy_u8ReceivedData);
	TWI_voidStopCond();

}











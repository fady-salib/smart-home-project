/*
 * TWI_Interface.h
 *
 *  Created on: Aug 26, 2023
 *      Author: M.H
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

#define FCPU 8000000UL
#define SCL  100000




/*Initialize Master*/
void TWI_voidMaterInit(u8 Copy_u8SlaveAddress);
/*Initialize Slave*/
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
/*As Master Start Condition*/
void TWI_voidStartCond(void);
/*As Master write Address on Bus*/
void TWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddressToSend);/*TRX->Slave*/
void TWI_voidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddressToSend);/*TRX->Master*/
/*As Master Write Data On Bus*/
void TWI_voidMasterWriteData(u8 Copy_u8SentData);
/*As Master Read Data On Bus*/
void TWI_voidMasterReadData(u8 *Copy_u8ReceivedData);
/*As Master Stop Condition*/
void TWI_voidStopCond(void);
u8   TWI_GetStatus(u8 Copy_u8Status);

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */

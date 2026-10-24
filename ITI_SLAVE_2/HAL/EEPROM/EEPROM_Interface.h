/*
 * EEPROM_Interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: M.H
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_
#define A_2			0
void EEPROM_voidSendData(u16 Copy_u16Address,u8 Copy_u8Data);
void EEPROM_voidRecieveData(u16 Copy_u16Address,u8 *Copy_u8ReceivedData);
void EEPROM_voidSendData2(u16 Copy_u16Address1, u16 Copy_u16Address2, u8 Copy_u8Data1, u8 Copy_u8Data2);
void EEPROM_voidRecieveData2(u16 Copy_u16Address1, u16 Copy_u16Address2, u8 *Copy_u8ReceivedData1, u8 *Copy_u8ReceivedData2);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */

/*
 * Security_Interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Hanos_000
 */

#ifndef SERVICE_SECURITY_INTERFACE_H_
#define SERVICE_SECURITY_INTERFACE_H_

u16 arrayToNum(u16* arr, u16 length);

void Pass(void);  //Set Password

void Add_Emergn_NUM(void); //ADD EMERGENCY NUMBER
void Add_Phone_NUM(void);  //ADD PHONE NUMBER
void SET_DEVICE(void);     //OPEN OR CLOSE (CHANGE STATUS OF DEVICE)





#endif /* SERVICE_SECURITY_INTERFACE_H_ */

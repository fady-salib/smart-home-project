/*
 * TWI_Private.h
 *
 *  Created on: Aug 26, 2023
 *      Author: M.H
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

#define TWI_TWBR_REG (*(volatile u8*)0x20)
#define TWI_TWSR_REG (*(volatile u8*)0x21)
#define TWI_TWAR_REG (*(volatile u8*)0x22)
#define TWI_TWDR_REG (*(volatile u8*)0x23)
#define TWI_TWCR_REG (*(volatile u8*)0x56)
//#define TWI_TWCR_REG (*(volatile u8*)0x56)													)

#define TWI_TWCR_TWIE_BIT 	0
#define TWI_TWCR_TWEN_BIT 	2
#define TWI_TWCR_TWWC_BIT 	3
#define TWI_TWCR_TWSTO_BIT 	4
#define TWI_TWCR_TWSTA_BIT 	5
#define TWI_TWCR_TWEA_BIT 	6
#define TWI_TWCR_TWINT_BIT	7
#define GEN_START                       0x08     //A START condition has been transmitted.
#define GEN_REP_START                   0x10     //A repeated START condition has been transmitted.
#define GEN_SLAW_ACK                    0x18     //SLA+W has been transmitted;ACK has been received.
#define GEN_SLAW_NACK                   0x20     //SLA+W has been transmitted;NACK has been received.
#define GEN_DATA_ACK                    0x28     //Data byte has been transmitted;ACK has been received.
#define GEN_DATA_NACK                   0x30     //Data byte has been transmitted;NACK has been received.
#define GEN_LOST_SLAW_DATA              0x38     //Arbitration lost in SLA+W or databytes.
#define GEN_SLAVE_ADD_WR                0xA8     //Slave address is received with write req.
#define GEN_SLAVE_ADD_RD                0x60     //Slave address is received with read req.
#define GEN_SLAVE_DATA_RECEIVED         0x80     //Read byte is received.
#define GEN_SLAVE_DATA_TRANMITIED       0xC0     //Write byte is received.
#endif /* MCAL_TWI_TWI_PRIVATE_H_ */

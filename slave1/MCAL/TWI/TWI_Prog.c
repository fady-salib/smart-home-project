/*
 * TWI_Prog.c
 *
 *  Created on: Aug 26, 2023
 *      Author: M.H
 */
#include "../../LIB/STD_TYPES.h"
#include "TWI_Private.h"
#include "TWI_Interface.h"

#define TWINT_MASK (1u << TWI_TWCR_TWINT_BIT)
#define TWEN_MASK (1u << TWI_TWCR_TWEN_BIT)
static u8 transfer_ok = 1;

static void wait_status(u8 expected, u8 alternate)
{
    u16 budget = 60000;
    while (!(TWI_TWCR_REG & TWINT_MASK) && --budget) { }
    u8 status = TWI_TWSR_REG & 0xF8u;
    if (!budget || (status != expected && status != alternate)) transfer_ok = 0;
}
u8 TWI_u8LastTransferOK(void) { return transfer_ok; }
void TWI_voidMaterInit(u8 address)
{
    TWI_TWSR_REG &= 0xFCu;
    TWI_TWBR_REG = (u8)(((FCPU / SCL) - 16) / 2);
    TWI_TWAR_REG = address << 1;
    TWI_TWCR_REG = TWEN_MASK;
    transfer_ok = 1;
}
void TWI_voidSlaveInit(u8 address)
{
    TWI_TWAR_REG = address << 1;
    TWI_TWCR_REG = TWEN_MASK;
}
void TWI_voidStartCond(void)
{
    transfer_ok = 1;
    TWI_TWCR_REG = TWINT_MASK | TWEN_MASK | (1u << TWI_TWCR_TWSTA_BIT);
    wait_status(0x08, 0x10);
}
void TWI_voidSendSlaveAddressWithWrite(u8 address)
{
    if (!transfer_ok) return;
    TWI_TWDR_REG = address << 1;
    TWI_TWCR_REG = TWINT_MASK | TWEN_MASK;
    wait_status(0x18, 0x18);
}
void TWI_voidSendSlaveAddressWithRead(u8 address)
{
    if (!transfer_ok) return;
    TWI_TWDR_REG = (address << 1) | 1u;
    TWI_TWCR_REG = TWINT_MASK | TWEN_MASK;
    wait_status(0x40, 0x40);
}
void TWI_voidMasterWriteData(u8 data)
{
    if (!transfer_ok) return;
    TWI_TWDR_REG = data;
    TWI_TWCR_REG = TWINT_MASK | TWEN_MASK;
    wait_status(0x28, 0x28);
}
void TWI_voidMasterReadData(u8 *data)
{
    if (!data) return;
    *data = 0xFF;
    if (!transfer_ok) return;
    /* Single final byte is NACKed; TWINT is write-one-to-clear. */
    TWI_TWCR_REG = TWINT_MASK | TWEN_MASK;
    wait_status(0x58, 0x58);
    if (transfer_ok) *data = TWI_TWDR_REG;
}
void TWI_voidStopCond(void)
{
    TWI_TWCR_REG = TWINT_MASK | TWEN_MASK | (1u << TWI_TWCR_TWSTO_BIT);
    u16 budget = 60000;
    while ((TWI_TWCR_REG & (1u << TWI_TWCR_TWSTO_BIT)) && --budget) { }
    if (!budget) transfer_ok = 0;
}
u8 TWI_GetStatus(u8 status)
{
    wait_status(status, status);
    return transfer_ok ? TWI_TWDR_REG : 0xFF;
}

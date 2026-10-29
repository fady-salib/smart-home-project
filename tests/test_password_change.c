#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../slave1/LIB/STD_TYPES.h"
#include "../slave1/HAL/Key_Pad/KP_Interface.h"
static u8 memory[256], keys[32];
static unsigned position, key_count, printed;
static char message[32];
void Init_KP(KP_stConfiguration *config) { (void)config; }
u8 Read_KP(KP_stConfiguration *config) { (void)config; assert(position<key_count); return keys[position++]; }
void TWI_voidMaterInit(u8 address) { (void)address; }
void EEPROM_voidSendData(u16 address,u8 value) { assert(address<256); memory[address]=value; }
void EEPROM_voidRecieveData(u16 address,u8 *value) { assert(address<256 && value); *value=memory[address]; }
void LCD_ClearDisplay(void) { }
void LCD_WriteString(const char *text) { snprintf(message,sizeof(message),"%s",text); }
u8 LCD_GoToWriteString(u8 row,u8 col,const char *text) { (void)row; (void)col; LCD_WriteString(text); return 1; }
u8 LCD_GoToWriteChar(u8 row,u8 col,u8 value) { (void)row; (void)col; (void)value; return 1; }
u8 LCD_GoToWriteNumber(u8 row,u8 col,u8 value) { (void)row; (void)col; (void)value; ++printed; return 1; }
#include "../slave1/SERVICE/Security_Prog.c"
int main(void)
{
    const u8 input[]={1,'#',2,3,4}; memcpy(keys,input,sizeof(input)); key_count=sizeof(input);
    Change_Pass(); assert(position==5);
    assert(memory[HOME_PIN_HIGH_ADDRESS]==12 && memory[HOME_PIN_LOW_ADDRESS]==34);
    assert(strcmp(message,"Password Saved!")==0);
    position=0; key_count=11; for (unsigned i=0; i<11; ++i) keys[i]=(u8)(i%10);
    Add_Phone_NUM(); assert(position==11 && printed==11);
    puts("PASS real password/phone entry: decimal-only PIN, valid EEPROM pointers, four-digit width and eleven input digits");
}

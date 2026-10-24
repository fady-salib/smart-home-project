
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define LCD_ROW1    1
#define LCD_ROW2    2

#define LCD_COL1    1
#define LCD_COL2    2
#define LCD_COL3    3
#define LCD_COL4    4
#define LCD_COL5    5
#define LCD_COL6    6
#define LCD_COL7    7
#define LCD_COL8    8
#define LCD_COL9    9
#define LCD_COL10   10
#define LCD_COL11   11
#define LCD_COL12   12
#define LCD_COL13   13
#define LCD_COL14   14
#define LCD_COL15   15
#define LCD_COL16   16


void LCD_Init(void);
void LCD_ClearDisplay(void);
void LCD_WriteCommand(u8 Copy_u8Command);
u8 	 LCD_WriteChar(u8 Copy_u8Char);
void LCD_WriteData(u8 Copy_u8Data);
void LCD_WriteString(u8 *Copy_u8PtrString);
u8 LCD_GoTo(u8 Copy_u8Line, u8 Copy_u8Cell);
s32 LCD_WriteNumber(s32 Copy_s32Num);
u8 LCD_WriteFloat(u16 Copy_u16Num);
u8 LCD_GoToWriteNumber(u8 Copy_u8Line, u8 Copy_u8Cell, u8 Copy_s32Num);
u8 LCD_GoToClear(u8 Copy_u8Line, u8 Copy_u8Cell, u8 Copy_u8NumCells);
u8 LCD_GoToWriteChar(u8 Copy_u8Line, u8 Copy_u8Cell, u8 Copy_u8Char);
u8 LCD_GoToWriteString(u8 Copy_u8Line, u8 Copy_u8Cell, const u8 *Copy_u8PtrString);
void LCD_BCD_To_Char(u8 Copy_u8Data);

#endif /* LCD_INTERFACE_H_ */

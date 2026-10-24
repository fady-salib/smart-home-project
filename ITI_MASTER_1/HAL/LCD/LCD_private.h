

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/* ====================== Private Macros ===================== */
#define _4_BIT_MODE				1
#define _8_BIT_MODE				2

#define LINE_0_ADDRESS			0x80
#define LINE_1_ADDRESS			0xC0
#define LINE_2_ADDRESS			0x94
#define LINE_3_ADDRESS			0xD0

#define CGRAM_ADDRESS			0x40			
#define DDRAM_ADDRESS			0x80

#define _4_BIT_MODE_COMMAND		0x02

/* Function Set Mask */
#define DATA_LENGTH_8BIT		0x34
#define DATA_LENGTH_4BIT		0x20

#define NUMBER_LINES_1			0x24
#define NUMBER_LINES_2			0x28
#define LCD_u8OFFSET 0x80



#define LCD_BIT_MODE == _4_BIT_MODE
#define DATA_LENGTH			DATA_LENGTH_4BIT


#define FUNCTION_SET_MASK		DATA_LENGTH | NUMBER_LINES

/* Clear Screen Mask */
#define CLEAR_SCREEN			0x01

/* Display ON/OFF Mask */
#define DISPLAY_ON				0xC
#define DISPLAY_OFF				0x8

#define	CURSOR_ON				0xA
#define	CURSOR_OFF				0x8

#define BLINK_CURSOR_ON			0x09
#define BLINK_CURSOR_OFF		0x08

#define DISPLAY_ON_OFF_MASK		DISPLAY_ON_OFF | CURSOR_ON_OFF | BLINK_CURSOR_ON_OFF

/* Entry Mode Set */
#define I_DDRAM_ADDR_SHIFT_LEFT		0x7
#define D_DDRAM_ADDR_SHIFT_RIGHT	0x5

#define I_DDRAM_ADDR_NO_SHIFT		0x6
#define D_DDRAM_ADDR_NO_SHIFT		0x4

/* ======================= Private Functions Prototypes ====================== */




#endif /* LCD_PRIVATE_H_ */

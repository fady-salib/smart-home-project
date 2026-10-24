
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* ====================== Function Set Configurations ===================== */

/*
	Options :


			- NUMBER_LINES_1
			- NUMBER_LINES_2
*/
#define NUMBER_LINES		NUMBER_LINES_2

/* ====================== Display ON/OFF Configurations ====================== */
/*
	Options :
			- DISPLAY_ON
			- DISPLAY_OFF
*/

#define DISPLAY_ON_OFF		DISPLAY_ON

/*
	Options :
			- CURSOR_ON
			- CURSOR_OFF
*/
#define CURSOR_ON_OFF		CURSOR_OFF

/*
	Options :
			- BLINK_CURSOR_ON
			- BLINK_CURSOR_OFF
*/
#define BLINK_CURSOR_ON_OFF		BLINK_CURSOR_OFF

/*
	Options :
			- I_DDRAM_ADDR_SHIFT_LEFT
			- D_DDRAM_ADDR_SHIFT_RIGHT

			- I_DDRAM_ADDR_NO_SHIFT
			- D_DDRAM_ADDR_NO_SHIFT
*/

#define ENTRY_MODE_SET		I_DDRAM_ADDR_NO_SHIFT
#define LCD_PORT 			DIO_u8PORTB

#endif /* LCD_CONFIG_H_ */

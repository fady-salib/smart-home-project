
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../HAL/LCD/LCD_private.h"
#include "../../HAL/LCD/LCD_config.h"
#include "../../HAL/LCD/LCD_interface.h"
//#include "../../MCAL/DIO/DIO_Interface.h"
//#include "../../MCAL/DIO/DIO_Private.h"
//#include "../../HAL/LCD/LCD_interface.h"
//#include "../../HAL/LCD/LCD_config.h"
//#include "../../HAL/LCD/LCD_private.h"

#include <util/delay.h>

/* ====================== Functions Definitions ===================== */
void LCD_Init(void)
{
	//Set direction

	DIO_VoidSetPortDirection(LCD_PORT,DIO_u8PORT_OUTPUT);
	 _delay_ms(50);
	 /* Send 4Bit mode command */
	 LCD_WriteCommand(_4_BIT_MODE_COMMAND);

	 /* Set the interface data length , number of lines */
	 LCD_WriteCommand(FUNCTION_SET_MASK);

	 /* Display ON/OFF Control */
	 LCD_WriteCommand(DISPLAY_ON_OFF_MASK);

	 /* Clear the Screen */
	 LCD_WriteCommand(CLEAR_SCREEN);
	 _delay_ms(1);

	 /* Entry Mode Set */
	 LCD_WriteCommand(ENTRY_MODE_SET);


}

void LCD_WriteCommand(u8 Copy_u8Command)
{
	/* First Half */
    /* Clear RS pin and RW pin to send Command */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN0,DIO_u8PIN_LOW); //RS = 0
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN1,DIO_u8PIN_LOW); //RW = 0
	
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Command,4)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Command,5)); //DB5
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Command,6)); //DB5
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Command,7)); //DB7
	
	/* Trigger the EN bit */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_LOW);
	_delay_ms(1);

		  /* Second Half */
	  /* Sending the command to the LCD */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Command,0)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Command,1)); //DB5
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Command,2)); //DB6
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Command,3)); //DB7

	/* Trigger the EN bit */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_LOW);
	_delay_ms(1);

}
void LCD_WriteData(u8 Copy_u8Data)
{
	/* First Half */
    /* Clear RS pin and RW pin to send Command */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN0,DIO_u8PIN_HIGH); //RS = 1
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN1,DIO_u8PIN_LOW); //RW = 0
	
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Data,4)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Data,5)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Data,6)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Data,7)); //DB4
	
	/* Trigger the EN bit */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_LOW);
	_delay_ms(1);
		  /* Second Half */
		  /* Sending the command to the LCD */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Data,0)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Data,1)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Data,2)); //DB4
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Data,3)); //DB4

	/* Trigger the EN bit */
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(LCD_PORT,DIO_u8PIN2,DIO_u8PIN_LOW);
	_delay_ms(1);

}
void LCD_WriteString ( u8 *Copy_u8PtrString)
{
	u8 i=0;
	while(Copy_u8PtrString[i] !='\0')
	{
		LCD_WriteData(Copy_u8PtrString[i]);
		i++;
	}

}

u8 LCD_GoTo(u8 Copy_u8Line, u8 Copy_u8Cell)
{
    u8 Ret = E_OK;

    if(Copy_u8Line == 0)
    {
        LCD_WriteCommand(0x80 + Copy_u8Cell);
        _delay_us(40);
    }
    else if(Copy_u8Line == 1)
    {
        LCD_WriteCommand(0xC0 + Copy_u8Cell);
        _delay_us(40);
    }
    else if(Copy_u8Line == 2)
    {
        LCD_WriteCommand(0x94 + Copy_u8Cell);
    }
    else if(Copy_u8Line == 3)
    {
        LCD_WriteCommand(0xD4 + Copy_u8Cell);
    }

    return Ret;
}
void LCD_ClearDisplay(void)
{
	LCD_WriteCommand(CLEAR_SCREEN);
	_delay_ms(1);
}
u8	LCD_WriteChar(u8 Copy_u8Char)
{
	u8 Ret = E_OK;
	LCD_WriteData(Copy_u8Char);
	return Ret;
}
s32 LCD_WriteNumber(s32 Copy_s32Num)
{
	u8 Ret = E_OK;

	u8 iterator = 0 ,Rem = 0;
	u8 Str[100];

	/* if the user send 0 */
	if(Copy_s32Num == 0)
	{
		LCD_WriteChar('0');
		_delay_ms(1);
		return Ret;
	}

	/* if the user send negative number */
	if(Copy_s32Num < 0)
	{
		Copy_s32Num *= -1;
		LCD_WriteChar('-');
	}

	/* Convert the number to string "But Reversed" */
	while(Copy_s32Num > 0)
	{
		/* Getting Remainder "Last Digit" */
		Rem = Copy_s32Num % 10;

		/* Assigning the Last Digit to the String */
		Str[iterator] = Rem + '0';
		/* Increasing the iterator of the string */
		iterator++;

		/* Deleting the last digit from the number */
		Copy_s32Num /= 10;
	}

	/* Printing every character of the string */
	/* In a reverse order because the array was reversed already */
	for(; iterator>0 ; iterator--)
	{
		LCD_WriteChar(Str[iterator-1]);
		_delay_us(1);
	}

	return Ret;
}


u8 LCD_GoToWriteNumber(u8 Copy_u8Line, u8 Copy_u8Cell, u8 Copy_s32Num)
{
	u8 Ret = E_OK;

	LCD_GoTo(Copy_u8Line,Copy_u8Cell);
	LCD_WriteNumber(Copy_s32Num);

	return Ret;
}
u8 LCD_GoToClear(u8 Copy_u8Line, u8 Copy_u8Cell, u8 Copy_u8NumCells)
{
	u8 Ret = E_OK;
	u8 iterator = 0;

	LCD_GoTo(Copy_u8Line,Copy_u8Cell);
	for(iterator = 0; iterator < Copy_u8NumCells; iterator++)
	{
		LCD_WriteChar(' ');
	}

	return Ret;
}

u8 LCD_GoToWriteChar(u8 Copy_u8Line, u8 Copy_u8Cell, u8 Copy_u8Char)
{
	u8 Ret = E_OK;

	LCD_GoTo(Copy_u8Line,Copy_u8Cell);
	LCD_WriteChar(Copy_u8Char);

	return Ret;
}


u8 LCD_GoToWriteString(u8 Copy_u8Line, u8 Copy_u8Cell, const u8 *Copy_u8PtrString)
{
	u8 Ret = E_OK;

	LCD_GoTo(Copy_u8Line,Copy_u8Cell);
	LCD_WriteString(Copy_u8PtrString);

	return Ret;
}





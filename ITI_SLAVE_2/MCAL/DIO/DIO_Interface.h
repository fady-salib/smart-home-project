
#include"../../LIB/STD_TYPES.h"
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
/*Ports Defines*/
#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

/*Pins definition*/
#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7


/*Pin Direction*/
#define DIO_u8PIN_INPUT 0
#define DIO_u8PIN_OUTPUT 1

/*Port Direction*/
#define DIO_u8PORT_INPUT 0
#define DIO_u8PORT_OUTPUT 0xFF

/*Pin Value*/
#define DIO_u8PIN_HIGH 1
#define DIO_u8PIN_LOW 0

/*Bits selection*/
#define DIO_u8M4B 4
#define DIO_u8L4B 0
/*Pin level*/
/**Name: DIO_voidSetPinDirection
 * Description:to set pin direction high or low
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8Pin
 * @u8 Copy_u8Direction
 * Return: void
 * */
void DIO_VoidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void DIO_VoidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_Pu8Return);
void DIO_VoidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);


/*Port Level*/
void DIO_VoidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DIO_VoidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_VoidGetPortValue(u8 Copy_u8Port, u8 *Copy_Pu8Return);
u8 DIO_ReadPin(u8 Copy_u8Port, u8 Copy_u8Pin);
void DIO_VoidTogglePIN(u8 Copy_u8Port,u8 Copy_u8Pin);

/*Extra Bonus Assignment */
/*direction*/
/*4Bits level*/

/**Name: DIO_voidSet4BitsValue
 * Description:to set value for successive four bits at once
 * Inputs:
 * @Copy_u8Port  : Selected Port (DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD)
 * @Copy_u8Value : value to assign in 4 bits (value limit: 0 : (2^4) -1)
 * @Copy_u8BitSelection : selected 4 bits (DIO_u8M4B, DIO_u8L4B) (defined in Interface file)
 * Return: void 
 * */

/*New function to initialize all pins at once*/
void DIO_voidInit(/*????????*/);
/*you may or may not use cfg*/

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */

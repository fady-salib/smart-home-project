
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"../../MCAL/DIO/DIO_Private.h"
volatile u8 *DIO_ArrpVu8_DDR[4] =
{ DIO_DDRA_REG, DIO_DDRB_REG, DIO_DDRC_REG, DIO_DDRD_REG };
volatile u8 *DIO_ArrpVu8_PORT[4] =
{ DIO_PORTA_REG, DIO_PORTB_REG, DIO_PORTC_REG, DIO_PORTD_REG };
volatile u8 *DIO_ArrpVu8_PIN[4] =
{ DIO_PINA_REG, DIO_PINB_REG, DIO_PINC_REG, DIO_PIND_REG };

void DIO_VoidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{

	if ((Copy_u8Port <= DIO_u8PORTD) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		/*short to select port and pin */
		if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			SET_BIT(*DIO_ArrpVu8_DDR[Copy_u8Port], Copy_u8Pin);
		}
		else if (Copy_u8Direction == DIO_u8PIN_INPUT)
		{
			CLR_BIT(*DIO_ArrpVu8_DDR[Copy_u8Port], Copy_u8Pin);
		}
		else
		{
			/*empty */

		}
	}
	else
	{
		/*empty */

	}

}
void DIO_VoidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if ((Copy_u8Port <= DIO_u8PORTD) && (Copy_u8Pin <= DIO_u8PIN7))
	{
		/*short to select port and pin */
		if (Copy_u8Value == DIO_u8PIN_HIGH)
		{
			SET_BIT(*DIO_ArrpVu8_PORT[Copy_u8Port], Copy_u8Pin);
		}
		else if (Copy_u8Value == DIO_u8PIN_LOW)
		{
			CLR_BIT(*DIO_ArrpVu8_PORT[Copy_u8Port], Copy_u8Pin);
		}
		else
		{
			/*empty */

		}
	}
	else
	{
		/*empty */

	}
}
void DIO_VoidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_Pu8Return)
{
	if ((Copy_u8Port <= DIO_u8PORTD) && (Copy_u8Pin <= DIO_u8PIN7))
     	{

		   *Copy_Pu8Return=GET_BIT(*DIO_ArrpVu8_PIN[Copy_u8Port],Copy_u8Pin);
		}
		else
		{
			/*empty */

		}
}

/*Port Level*/
void DIO_VoidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	if (Copy_u8Port <= DIO_u8PORTD)
	{

		*DIO_ArrpVu8_DDR[Copy_u8Port] = Copy_u8Direction;
	}
	else
	{
       /*empty*/
	}
}

/*Port value*/
void DIO_VoidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	if (Copy_u8Port <= DIO_u8PORTD)
	{
		*DIO_ArrpVu8_DDR[Copy_u8Port] = Copy_u8Value;
	}
	else
	{
		/*empty*/
	}

}

void DIO_VoidGetPortValue(u8 Copy_u8Port, u8 *Copy_Pu8Return)
{
	if (Copy_u8Port <= DIO_u8PORTD)
	{
		*Copy_Pu8Return = *DIO_ArrpVu8_PIN[Copy_u8Port];
	}
	else
	{
		/*empty*/
	}

}

void DIO_VoidTogglePIN(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	  if((Copy_u8Port <= DIO_u8PORTD) && (Copy_u8Pin <= DIO_u8PIN7))
		{
		  TOG_BIT(*DIO_ArrpVu8_PORT[Copy_u8Port],Copy_u8Pin);
		}
	  else
	  		  {

	  		  }
}



/*
 * KP_Prog.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Hanos_000
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"KP_Config.h"
#include"KP_Interface.h"
void Init_KP(KP_stConfiguration *Copy_pstConfig)
{
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Colum1_PORT,Copy_pstConfig->KP_Colum1_PIN,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Colum2_PORT,Copy_pstConfig->KP_Colum2_PIN,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Colum3_PORT,Copy_pstConfig->KP_Colum3_PIN,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Colum4_PORT,Copy_pstConfig->KP_Colum4_PIN,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Row1_PORT,Copy_pstConfig->KP_Row1_PIN,DIO_u8PIN_INPUT);
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Row2_PORT,Copy_pstConfig->KP_Row2_PIN,DIO_u8PIN_INPUT);
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Row3_PORT,Copy_pstConfig->KP_Row3_PIN,DIO_u8PIN_INPUT);
	DIO_VoidSetPinDirection(Copy_pstConfig->KP_Row4_PORT,Copy_pstConfig->KP_Row4_PIN,DIO_u8PIN_INPUT);
	
}
u8 Read_KP(KP_stConfiguration *Copy_pstConfig)
{
    u8 Pressed_key = KP_Not_Pressed;
    u8 Local_KP_Arr[Rows_NUM][Columns_NUM] = KP_Arr; // Transpose KP_Arr
    
	u8 Colum_Index ,Row_Index ;
	u8 Colum_PORT_Arr [Columns_NUM] = {Copy_pstConfig->KP_Colum1_PORT,Copy_pstConfig->KP_Colum2_PORT,Copy_pstConfig->KP_Colum3_PORT,Copy_pstConfig->KP_Colum4_PORT};
	u8 Row_PORT_Arr [Rows_NUM] = {Copy_pstConfig->KP_Row1_PORT,Copy_pstConfig->KP_Row2_PORT,Copy_pstConfig->KP_Row3_PORT,Copy_pstConfig->KP_Row4_PORT};
	u8 Colum_Pin_Arr [Columns_NUM] = {Copy_pstConfig->KP_Colum1_PIN,Copy_pstConfig->KP_Colum2_PIN,Copy_pstConfig->KP_Colum3_PIN,Copy_pstConfig->KP_Colum4_PIN};
	u8 Row_Pin_Arr [Rows_NUM] = {Copy_pstConfig->KP_Row1_PIN,Copy_pstConfig->KP_Row2_PIN,Copy_pstConfig->KP_Row3_PIN,Copy_pstConfig->KP_Row4_PIN};
	u8 State = 0;
	for(Colum_Index = 0; Colum_Index < Columns_NUM;Colum_Index ++ )
		{
		DIO_VoidSetPinValue(Colum_PORT_Arr[Colum_Index],Colum_Pin_Arr[Colum_Index],DIO_u8PIN_HIGH);
		}
	for(Row_Index = 0; Row_Index < Rows_NUM;Row_Index ++ )
		{
			DIO_VoidSetPinValue(Row_PORT_Arr[Row_Index],Row_Pin_Arr[Row_Index],DIO_u8PIN_HIGH);
		}

    for (Colum_Index = 0; Colum_Index < Columns_NUM; Colum_Index++)
    {
        DIO_VoidSetPinValue(Colum_PORT_Arr[Colum_Index], Colum_Pin_Arr[Colum_Index], DIO_u8PIN_LOW);
        for (Row_Index = 0; Row_Index < Rows_NUM; Row_Index++)
        {
            DIO_VoidGetPinValue(Row_PORT_Arr[Row_Index], Row_Pin_Arr[Row_Index], &State);
            if (State == DIO_u8PIN_LOW)
            {
                while (State == DIO_u8PIN_LOW)
                {
                    DIO_VoidGetPinValue(Row_PORT_Arr[Row_Index], Row_Pin_Arr[Row_Index], &State);
                }
                Pressed_key = Local_KP_Arr[Row_Index][Colum_Index]; // Update to use Local_KP_Arr
            }
        }
        DIO_VoidSetPinValue(Colum_PORT_Arr[Colum_Index], Colum_Pin_Arr[Colum_Index], DIO_u8PIN_HIGH);
    }
    return Pressed_key;
}


/*
 * main.c
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../SERVICE/RTOS/RTOS_Interface.h"


void Func1(void);
void Func2(void);
void Func3(void);
void Func4_Delete(void);

int main ()
{

	u8 delete=3;
	DIO_voidSetPinDirection(PORTA , PIN0 , OUTPUT);
	DIO_voidSetPinDirection(PORTA , PIN1 , OUTPUT);
	DIO_voidSetPinDirection(PORTA , PIN2 , OUTPUT);

	DIO_voidSetPinDirection(PORTA , PIN7 , OUTPUT);


	RTOS_voidCreateTask(0,1000,&Func1,1);
	RTOS_voidCreateTask(1,2000,&Func2,2);
	RTOS_voidCreateTask(2,3000,&Func3,3);
	RTOS_voidCreateTask(3,3000,&Func4_Delete,4);

	RTOS_voidDeleteTask(delete);
	RTOS_voidStart();

	GIE_voidEnableInterruptGlobal();
	while(1)
	{

	}
}


void Func1(void)
{
	static u8 Local_u8PinVal=0 ;
	if (Local_u8PinVal == 0)
	{
		DIO_voidSetPinValue(PORTA , PIN0 , Local_u8PinVal);
		Local_u8PinVal = 1;

	}
	else
	{
		DIO_voidSetPinValue(PORTA , PIN0 , Local_u8PinVal);
		Local_u8PinVal = 0;
	}
}
void Func2(void)
{
	static u8 Local_u8PinVal=0 ;
	if (Local_u8PinVal == 0)
	{
		DIO_voidSetPinValue(PORTA , PIN1 , Local_u8PinVal);
		Local_u8PinVal = 1;

	}
	else
	{
		DIO_voidSetPinValue(PORTA , PIN1 , Local_u8PinVal);
		Local_u8PinVal = 0;
	}
}
void Func3(void)
{
	static u8 Local_u8PinVal=0 ;
	if (Local_u8PinVal == 0)
	{
		DIO_voidSetPinValue(PORTA , PIN2 , Local_u8PinVal);
		Local_u8PinVal = 1;

	}
	else
	{
		DIO_voidSetPinValue(PORTA , PIN2 , Local_u8PinVal);
		Local_u8PinVal = 0;
	}
}

void Func4_Delete(void)
{
	static u8 Local_u8PinVal=0 ;
	if (Local_u8PinVal == 0)
	{
		DIO_voidSetPinValue(PORTA , PIN7 , Local_u8PinVal);
		Local_u8PinVal = 1;

	}
	else
	{
		DIO_voidSetPinValue(PORTA , PIN7 , Local_u8PinVal);
		Local_u8PinVal = 0;
	}
}

/*
 * DIO.c
 *
 * Created: 11-Nov-23 2:19:01 PM
 *  Author: JOE
 */ 


#include "../../../LIB/STD.h"
#include "../HEADER/DIO_PROTO_TYPES.h"



void DIO_SET_PORT_DIREC (DIO_PORT_ID PORT,  DIO_DIRECTION DIRECTION)

{
	switch(PORT)
	{
		case DIO_PORTA:
		
		DDRA = DIRECTION;
		
		break;
		
		case DIO_PORTB:
		
		DDRB = DIRECTION;
		
		break;
		
		case DIO_PORTC:
		
		DDRC = DIRECTION;
		
		break;
		
		case DIO_PORTD:
		
		DDRD = DIRECTION;
		
		break;
		
		default:
		break;
		
	}
}



void DIO_SET_PIN_DIREC (DIO_PORT_ID PORT , DIO_PIN_ID PIN  , DIO_DIRECTION DIRECTION)
{
	switch (PORT)
	{
		case DIO_PORTA:
		if (DIRECTION == OUTPUT)
		{
			SET_BIT (DDRA,PIN);
		}
		else
		{
			CLR_BIT (DDRA,PIN);
		}
		break;

		case DIO_PORTB:
		if (DIRECTION == OUTPUT)
		{
			SET_BIT (DDRB,PIN);
		}
		else
		{
			CLR_BIT (DDRB,PIN);
		}
		break;

		case DIO_PORTC:
		if (DIRECTION == OUTPUT)
		{
			SET_BIT (DDRC,PIN);
		}
		else
		{
			CLR_BIT (DDRC,PIN);
		}
		break;

		case DIO_PORTD:
		if (DIRECTION == OUTPUT)
		{
			SET_BIT (DDRD,PIN);
		}
		else
		{
			CLR_BIT (DDRD,PIN);
		}
		break;
	}
}


void DIO_SET_PIN_VALUE (DIO_PORT_ID PORT , DIO_PIN_ID PIN , DIO_LEVEL VALUE)

{
	switch (PORT)
	{
		case DIO_PORTA:
		if (VALUE == STD_LOW)
		{
			CLR_BIT ( PORTA, PIN);
		}
		else
		{
			SET_BIT(PORTA,PIN);
		}
		break;

		case DIO_PORTB:
		if (VALUE == STD_LOW)
		{
			CLR_BIT (PORTB,PIN);
		}
		else
		{
			SET_BIT(PORTB,PIN);
		}
		break;

		case DIO_PORTC:
		if (VALUE == STD_LOW)
		{
			CLR_BIT (PORTC,PIN);
		}
		else
		{
			SET_BIT(PORTC,PIN);
		}
		break;

		case DIO_PORTD:
		if (VALUE == STD_LOW)
		{
			CLR_BIT (PORTD,PIN);
		}
		else
		{
			SET_BIT(PORTD,PIN);
		}
		break;
	}
}


void DIO_SET_PORT_VALUE (DIO_PORT_ID PORT, uint8 VALUE)
{
	switch(PORT)
	{
		case DIO_PORTA:
		
		PORTA = VALUE;
		
		break;
		
		case DIO_PORTB:
		
		PORTB = VALUE;
		
		break;
		
		case DIO_PORTC:
		
		PORTC = VALUE;
		
		break;
		
		case DIO_PORTD:
		
		PORTD = VALUE;
		
		break;
		
		default:
		break;
	}
}

void DIO_TOOGLE_PIN (DIO_PORT_ID PORT, DIO_PIN_ID PIN)
{
	switch (PORT)
	{
		case DIO_PORTA:
		TOOGLE_BIT (PORTA,PIN);
		break;

		case DIO_PORTB:
		TOOGLE_BIT (PORTB,PIN);
		break;

		case DIO_PORTC:
		TOOGLE_BIT (PORTC,PIN);
		break;

		case DIO_PORTD:
		TOOGLE_BIT (PORTD,PIN);
		break;
	}
}


DIO_LEVEL DIO_READ_PIN (DIO_PORT_ID PORT, DIO_PIN_ID PIN )
{
	DIO_LEVEL VALUE;
	
	switch(PORT)
	{
		case DIO_PORTA:
		
		VALUE = GET_BIT(PINA,PIN);
		
		break;
		
		case DIO_PORTB:
		
		VALUE = GET_BIT(PINB,PIN);
		
		break;
		
		case DIO_PORTC:
		
		VALUE = GET_BIT(PINC,PIN);
		
		break;
		
		case DIO_PORTD:
		
		VALUE = GET_BIT(PIND,PIN);
		
		break;
		
		default:
		break;
	}
	
	return VALUE;
}


uint8  DIO_READ_PORT   (DIO_PORT_ID PORT )

{
	uint8 VALUE;
	
	switch(PORT)
	{
		case DIO_PORTA:
		
		VALUE = PINA;
		
		break;
		
		case DIO_PORTB:
		
		VALUE = PINB;
		
		break;
		
		case DIO_PORTC:
		
		VALUE = PINC;
		
		break;
		
		case DIO_PORTD:
		
		VALUE = PIND;
		
		break;
		
		default:
		break;
	}
	
	return VALUE;
}


void DIO_SET_PULL_UP_RES (DIO_PORT_ID PORT, DIO_PIN_ID PIN)

{
	switch (PORT)
	{
		
		case DIO_PORTA:
		
		SET_BIT (PORTA , PIN);
		
		break;
		
		case DIO_PORTB:
		
		SET_BIT (PORTB , PIN);
		
		break;
		
		case DIO_PORTC:
		
		SET_BIT (PORTC ,PIN);
		
		break;
		
		case DIO_PORTD:
		
		SET_BIT (PORTD , PIN);
		
		break;
		
		default:
		break;
	}
}

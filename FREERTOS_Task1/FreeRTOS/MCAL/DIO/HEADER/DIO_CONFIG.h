/*
 * DIO_CONFIG.h
 *
 * Created: 11-Nov-23 2:19:16 PM
 *  Author: JOE
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "../../../LIB/REGs/DIO_REGs.h"
#include "../../../LIB/BIT_Math.h"

typedef enum
{
	DIO_PORTA =0,
	
	DIO_PORTB =1,
	
	DIO_PORTC =2,
	
	DIO_PORTD =3
	
}DIO_PORT_ID;

typedef enum
{
	DIO_PIN0 = 0,
	
	DIO_PIN1 = 1,
	
	DIO_PIN2 = 2,
	
	DIO_PIN3 = 3,
	
	DIO_PIN4 = 4,
	
	DIO_PIN5 = 5,
	
	DIO_PIN6 = 6,
	
	DIO_PIN7 = 7
	
}DIO_PIN_ID;

typedef enum{
	
	INPUT = 0,
	
	OUTPUT = 1
}DIO_DIRECTION;

typedef enum{
	
	STD_LOW = 0,
	
	STD_HIGH = 1
}DIO_LEVEL;



#endif /* DIO_CONFIG_H_ */

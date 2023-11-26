/*  file guard */

#include "../../LIB/STD_TYPES.h"


#ifndef  DIO_INTERFACE_H
#define  DIO_INTERFACE_H

#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define HIGH   1
#define LOW    0

#define INPUT  0
#define OUTPUT 1


/*******************************************************/
/*func . Name : DIO_voidSetPinValue                   */
/*i/p argument : Copy_u8PortId options : PORTA, PORTB ,PORTC , PORTD*/
/*   Copy_u8PinId   : PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7*/
/* Copy_u8Value : HIGH , LOW */
/*Return : void */
/*****************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Value);

/*******************************************************/
/*func . Name : DIO_voidSetPinDirection                  */
/*i/p argument : Copy_u8PortId options : PORTA, PORTB ,PORTC , PORTD*/
/*   Copy_u8PinId   : PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7*/
/* Copy_u8Direction : INPUT , OUTPUT */
/*Return : void */
/*****************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Direction);

/*******************************************************/
/*func . Name : DIO_u8GetPinValue                  */
/*i/p argument : Copy_u8PortId options : PORTA, PORTB ,PORTC , PORTD*/
/*   Copy_u8PinId   : PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7*/
/*Return : Local_u8Variable   ( unsigned character)*/
/*****************************************************************/
u8  DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId );


void DIO_voidSetPortValue(u8 Copy_u8PortId  , u8 Copy_u8Value);
void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction);
u8  DIO_u8GetPortValue(u8 Copy_u8PortId);



#endif

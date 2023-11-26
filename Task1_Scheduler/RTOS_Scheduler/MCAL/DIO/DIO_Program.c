#include "..\..\LIB\STD_TYPES.h"
#include"..\..\LIB\BIT_MATH.h"


#include"DIO_Interface.h"
#include "DIO_Private.h"

/**********************************************************************/
/* function Name : DIO_voidSetPinValue                                */
/* i/p argument : Copy_u8PortId options : PORTA, PORTB ,PORTC , PORTD */
/* Copy_u8PinId : PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7             */
/* Copy_u8Value : HIGH , LOW                                          */
/* Return : void                                                      */
/**********************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Value)
{     /*i/p validation */
   if (Copy_u8PortId > PORTD ||  Copy_u8PinId > PIN7)
   {
         // DO NOTHING 
   }
   else
   {
    switch (Copy_u8Value)
       {
       case LOW:
              switch(Copy_u8PortId)
              {
                case PORTA :   CLR_BIT(PORTA_REG , Copy_u8PinId ) ;           break;
                case PORTB :    CLR_BIT(PORTB_REG , Copy_u8PinId ) ;          break;
                case PORTC :    CLR_BIT(PORTC_REG , Copy_u8PinId );           break;
                case PORTD :    CLR_BIT(PORTD_REG , Copy_u8PinId ) ;          break;
                default:
                break;
              }
        break;
        case HIGH :
              switch(Copy_u8PortId)
              {
                case PORTA :   SET_BIT(PORTA_REG , Copy_u8PinId ) ;           break;
                case PORTB :    SET_BIT(PORTB_REG , Copy_u8PinId ) ;          break;
                case PORTC :    SET_BIT(PORTC_REG , Copy_u8PinId );           break;
                case PORTD :    SET_BIT(PORTD_REG , Copy_u8PinId ) ;          break;
                default:
                break;
              }
        break;
       
       default:
        break;
       }
   }
   
       
}
/**********************************************************************/
/* function Name : DIO_voidSetPinDirection                            */
/* i/p argument : Copy_u8PortId options : PORTA, PORTB ,PORTC , PORTD */
/* Copy_u8PinId : PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7             */
/* Copy_u8Direction : INPUT , OUTPUT                                  */
/* Return : void                                                      */
/**********************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Direction)
{
      /*i/p validation */
   if (Copy_u8PortId > PORTD ||  Copy_u8PinId > PIN7)
   {
         // DO NOTHING 
   }
   else
   {
    switch (Copy_u8Direction)
       {
       case INPUT:
              switch(Copy_u8PortId)
              {
                case PORTA :   CLR_BIT(DDRA_REG , Copy_u8PinId ) ;           break;
                case PORTB :    CLR_BIT(DDRB_REG , Copy_u8PinId ) ;          break;
                case PORTC :    CLR_BIT(DDRC_REG , Copy_u8PinId );           break;
                case PORTD :    CLR_BIT(DDRD_REG , Copy_u8PinId ) ;          break;
                default:
                break;
              }
        break;
        case OUTPUT :
              switch(Copy_u8PortId)
              {
                case PORTA :   SET_BIT(DDRA_REG , Copy_u8PinId ) ;           break;
                case PORTB :    SET_BIT(DDRB_REG , Copy_u8PinId ) ;          break;
                case PORTC :    SET_BIT(DDRC_REG , Copy_u8PinId );           break;
                case PORTD :    SET_BIT(DDRD_REG , Copy_u8PinId ) ;          break;
                default:
                break;
              }
        break;
       
       default:
        break;
       }
   }

}
/**********************************************************************/
/* function Name : DIO_u8GetPinValue                                  */
/* i/p argument : Copy_u8PortId options : PORTA, PORTB ,PORTC , PORTD */
/* Copy_u8PinId : PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7             */
/* Return : Local_u8Variable   ( unsigned character)                  */
/**********************************************************************/
u8  DIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId )
{
     u8 Local_u8Variable;
     switch(Copy_u8PortId)
     {
      case PORTA :  Local_u8Variable=GET_BIT(PINA_REG , Copy_u8PinId);   break;
      case PORTB :  Local_u8Variable=GET_BIT(PINB_REG , Copy_u8PinId);   break;
      case PORTC :  Local_u8Variable=GET_BIT(PINC_REG , Copy_u8PinId);   break;
      case PORTD :  Local_u8Variable=GET_BIT(PIND_REG , Copy_u8PinId);   break;
      default:
      break;
     }

     return Local_u8Variable;
}


void DIO_voidSetPortValue(u8 Copy_u8PortId  , u8 Copy_u8Value)
{
     switch (Copy_u8PortId)
     {
     case PORTA :  PORTA_REG= Copy_u8Value;      break;
     case PORTB :  PORTB_REG= Copy_u8Value;      break;
     case PORTC :  PORTC_REG= Copy_u8Value;      break;
     case PORTD :  PORTD_REG= Copy_u8Value;      break;
     
     default:
      break;
     }
}

void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction)
{
      switch(Copy_u8PortId)
		{
			case PORTA :DDRA_REG = Copy_u8Direction ;
						break ;
			case PORTB :
						DDRB_REG = Copy_u8Direction ;
						break ;
			case PORTC :
						DDRC_REG = Copy_u8Direction ;
						break ;
			case PORTD :
						DDRD_REG = Copy_u8Direction ;
						break ;
			default :
						break ;

		}
}

u8  DIO_u8GetPortValue(u8 Copy_u8PortId)
{
    u8 Local_u8Variable ;
	switch(Copy_u8PortId)
	{
		case PORTA : Local_u8Variable=PINA_REG ;
			break ;
		case PORTB : Local_u8Variable=PINB_REG ;
			break ;
		case PORTC : Local_u8Variable=PINC_REG ;
			break ;
		case PORTD : Local_u8Variable=PIND_REG ;
			break ;
		default :
			break ;

	}
	return Local_u8Variable ;
}

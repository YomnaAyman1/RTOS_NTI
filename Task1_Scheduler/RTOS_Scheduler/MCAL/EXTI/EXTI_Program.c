/*
 * EXTI_Program.c
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_Interface.h"

void (*GPF) (void) = NULL;

void EXTI_INIT(void)
{
      #if   (INT_ENABLE == INT0)
	       /* pin config*/
	      //DIO_voidSetPinDirection(PORTD , PIN2 , OUTPUT);
	      /* enable int0*/
	      SET_BIT(GICR_REG , 6);

             #if  (INT_SENSE_CONTROL == FALLING_EDGE)
	              /*FALLING edge */
	             DIO_voidSetPinValue(PORTD , PIN2 , HIGH);
	             SET_BIT(MCUCR_REG , 1);
	             CLR_BIT(MCUCR_REG , 0);
             #elif (INT_SENSE_CONTROL == RISING_EDGE)
	             /* rising edge*/
	             SET_BIT(MCUCR_REG , 1);
	             SET_BIT(MCUCR_REG , 0);
             #elif (INT_SENSE_CONTROL == LOW_LEVEL)
	             /* low level */
	             CLR_BIT(MCUCR_REG , 1);
	             CLR_BIT(MCUCR_REG , 0);
             #else
	             /* on change */
	             CLR_BIT(MCUCR_REG , 1);
	             SET_BIT(MCUCR_REG , 0);

             #endif
       #elif (INT_ENABLE == INT1)
	             /* pin config*/
	             //DIO_voidSetPinDirection(PORTD , PIN2 , OUTPUT);
	             /* enable int0*/
	              SET_BIT(GICR_REG , 7);

	           #if  (INT_SENSE_CONTROL == FALLING_EDGE)
	              /*FALLING edge */
	             DIO_voidSetPinValue(PORTD , PIN2 , HIGH);
	             SET_BIT(MCUCR_REG , 3);
	             CLR_BIT(MCUCR_REG , 2);
	           #elif (INT_SENSE_CONTROL == RISING_EDGE)
	             /* rising edge*/
	             SET_BIT(MCUCR_REG , 3);
	             SET_BIT(MCUCR_REG , 2);
	           #elif (INT_SENSE_CONTROL == LOW_LEVEL)
	             /* low level */
	             CLR_BIT(MCUCR_REG , 3);
	             CLR_BIT(MCUCR_REG , 2);
	           #else
	             /* on change */
	             CLR_BIT(MCUCR_REG , 3);
	             SET_BIT(MCUCR_REG , 2);

	           #endif
       #elif  (INT_ENABLE == INT2)
	             //DIO_voidSetPinDirection(PORTB , PIN2 , OUTPUT);
	    	             /* enable int0*/
	    	     SET_BIT(GICR_REG , 5);

	    	       #if  (INT_SENSE_CONTROL == FALLING_EDGE)
	    	          /*FALLING edge */
	    	         DIO_voidSetPinValue(PORTD , PIN2 , HIGH);
	    	         CLR_BIT(MCUCSR_REG , 6);
	    	       #elif (INT_SENSE_CONTROL == RISING_EDGE)
	    	         /* rising edge*/
	    	         SET_BIT(MCUCSR_REG , 6);

	              #endif

      #endif
}
void EXTI_voidEnableInterrupt (u8 Copy_u8ExtiNum , u8 Copy_u8SenseControl)
{
     switch (Copy_u8ExtiNum)
     {
     case INT0 : SET_BIT(GICR_REG , 6);
          switch (Copy_u8SenseControl)
          {
            case FALLING_EDGE :
            	SET_BIT(MCUCR_REG , 1);
            	CLR_BIT(MCUCR_REG , 0);
            	break;
            case RISING_EDGE :
                SET_BIT(MCUCR_REG , 1);
                SET_BIT(MCUCR_REG , 0);
                break;
            case LOW_LEVEL :
               	CLR_BIT(MCUCR_REG , 1);
               	CLR_BIT(MCUCR_REG , 0);
               	break;
            case  ON_CHANGE :
            	CLR_BIT(MCUCR_REG , 1);
                SET_BIT(MCUCR_REG , 0);
                break;
            default :         break;
          }
          break;
     case INT1 : SET_BIT(GICR_REG , 7);
               switch (Copy_u8SenseControl)
               {
                 case FALLING_EDGE :
                	 SET_BIT(MCUCR_REG , 3);
                	 CLR_BIT(MCUCR_REG , 2);
                 	break;
                 case RISING_EDGE :
                	 SET_BIT(MCUCR_REG , 3);
                	 SET_BIT(MCUCR_REG , 2);
                     break;
                 case LOW_LEVEL :
                	 CLR_BIT(MCUCR_REG , 3);
                	 CLR_BIT(MCUCR_REG , 2);
                    	break;
                 case  ON_CHANGE :
                	 CLR_BIT(MCUCR_REG , 3);
                	 SET_BIT(MCUCR_REG , 2);
                     break;
                 default :           break;
               }
           break;
    case INT2 :
    	   SET_BIT(GICR_REG , 5);
                   switch (Copy_u8SenseControl)
                   {
                     case FALLING_EDGE :
                    	 CLR_BIT(MCUCSR_REG , 6);
                     	break;
                     case RISING_EDGE :
                    	 SET_BIT(MCUCSR_REG , 6);
                         break;

                      default :           break;
                     }
            break;
       default :            break;
     }
}
void EXTI_voidDisableInterrupt (u8 Copy_u8ExtiNum )
{
      switch(Copy_u8ExtiNum)
      {
      case INT0 : CLR_BIT(GICR_REG , 6);      break;
      case INT1 : CLR_BIT(GICR_REG , 7);      break;
      case INT2 : CLR_BIT(GICR_REG , 5);      break;
      default :                               break;
      }
}

void EXTI_voidSetCALLBack(void ( *LPF) (void))
{
	GPF = LPF;
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if (GPF != NULL)
	{
		GPF();
	}
}

void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if (GPF != NULL)
	{
		GPF();
	}
}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if (GPF != NULL)
	{
		GPF();
	}
}




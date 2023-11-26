/*
 * TIMER_Program.c
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_Interface.h"
#include "TIMER_Private.h"
#include "TIMER_Config.h"


void (*pNotificationT0CompareMatch) (void) = NULL;


void Timers_void_Timer0Init ()
{
               	/* CTC MODE */
                 CLR_BIT(TIMERS_TCCR0_REG ,6);
                 SET_BIT(TIMERS_TCCR0_REG ,3);

                 //SET_BIT(TIMERS_TCCR0_REG , 5);
                 //CLR_BIT(TIMERS_TCCR0_REG , 4);
           		/* Prescaler value=64 */
           		CLR_BIT(TIMERS_TCCR0_REG , 2);
           		SET_BIT(TIMERS_TCCR0_REG ,1);
           		SET_BIT(TIMERS_TCCR0_REG,0);
           		/* En PIE */
           		//SET_BIT(TIMERS_TIMSK_REG , 0);
                // set CompareMatch_VAL
           		TIMERS_OCR0_REG = CompareMatch_VAL;
           		// interrupt  for compare match
           		SET_BIT(TIMERS_TIMSK_REG , 1);


}
void Timers_voidSetCallBack_T0_CompareMatch( void ( *LPF)(void))
{
	pNotificationT0CompareMatch= LPF;
}


/*ISR */
// Compare Match Timer 0
void __vector_10(void)    __attribute((signal));
void __vector_10(void)
{
	if(pNotificationT0CompareMatch != 0)
	{
		pNotificationT0CompareMatch();
	}

}




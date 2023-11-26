/*
 * ADC_Program.c
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"



void ADC_voidInit (void)
{   DIO_voidSetPortDirection(PORTA , INPUT);
	SET_BIT(ADMUX_REG , REFS0);       // BIT 6
    CLR_BIT(ADMUX_REG , REFS1);        // BIT 7

    CLR_BIT(ADMUX_REG , ADATA);      // BIT 5

    CLR_BIT(ADCSRA_REG , ADATA);    // BIT 5

    ADCSRA_REG = (ADCSRA_REG & 0XF8 ) | (0b11000000);

    CLR_BIT(ADCSRA_REG , ADIE);   // BIT 3

    SET_BIT(ADCSRA_REG , ADEN);    // BIT 7
}
u16 ADC_u16GetRead(u8 Copy_channelNumber)
{   if (Copy_channelNumber < 8)
     {
	   ADMUX_REG = (ADMUX_REG & 0XE0)  | Copy_channelNumber;
       SET_BIT(ADCSRA_REG , ADSC);           // BIT 6

       while ( GET_BIT(ADCSRA_REG , ADIF) == 0 );
       SET_BIT(ADCSRA_REG , ADIF);             // BIT 4
     }

  return ADC_DATA ;
}








void ADC_StartConversion(u8 Copy_channelNumber)
{

}

// Function call back to Interrupt
void ADC_SetCallBackFunction(void (*ADC_call) (void) )
{

}


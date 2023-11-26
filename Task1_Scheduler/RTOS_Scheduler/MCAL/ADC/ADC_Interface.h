/*
 * ADC_Interface.h
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void ADC_voidInit (void);
u16 ADC_u16GetRead(u8 Copy_channelNumber);
void ADC_StartConversion(u8 Copy_channelNumber);
void ADC_SetCallBackFunction(void (*ADC_call) (void) );

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */

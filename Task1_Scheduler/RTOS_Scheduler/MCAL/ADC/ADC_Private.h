/*
 * ADC_Private.h
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_


#define ADMUX_REG        *((volatile u8*)(0x27))
#define ADCSRA_REG       *((volatile u8*)(0x26))
#define ADCL_REG         *((volatile u8*)(0x24))
#define ADCH_REG         *((volatile u8*)(0x25))
#define ADC_DATA         *((volatile u16*)(0x24))
#define SFIOR_REG        *((volatile u8*)(0x50))

#define  REFS0  6
#define  REFS1  7
#define  ADATA  5
#define  ADIE   3
#define  ADEN   7
#define  ADSC   6
#define  ADIF   4



#endif /* MCAL_ADC_ADC_PRIVATE_H_ */

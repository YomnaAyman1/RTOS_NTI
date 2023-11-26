
/*preprocessor header file guard*/
#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_


#include "../../../LIB/STD.h"
/********************************************************************************/
/****************************Interfacing macros**********************************/
/********************************************************************************/

/*possible channels*/
#define CHANNEL_A            1      //activating action of OC1A
#define CHANNEL_B            2      //activating action of OC1B

/*possible frequencies represented by values to be set on ICR1 register*/
#define FREQUENCY_1000       1000
#define FREQUENCY_500        2000
#define FREQUENCY_250        4000
#define FREQUENCY_200        5000
#define FREQUENCY_125        8000
#define FREQUENCY_100        10000
#define FREQUENCY_50         20000
#define FREQUENCY_40		 25000
#define FREQUENCY_25		 40000
#define FREQUENCY_20		 50000

/********************************************************************************/
/**************************Functions' prototype**********************************/
/********************************************************************************/


/*Description  :  this function is to initialize FAST PWM on TIMER/COUNTER0       */
/*Input        :  output channel [channelA or channelB]			                  */
/*             :  frequency of output signal									  */
/*             :  Duty cycle for setting ON timer                                 */
/*Output       :  error indicator                                     			  */
/*Configuration:  post-build    								                  */
uint8 PWM_u8Init(uint8 Copy_u8Channel , uint16 Copy_u8Frequency , uint16 Copy_u16OCRValue);


#endif /* PWM_INTERFACE_H_ */

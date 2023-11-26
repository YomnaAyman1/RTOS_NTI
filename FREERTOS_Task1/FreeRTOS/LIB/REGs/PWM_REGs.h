
/*preprocessor header file guard*/
#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

#include "../STD.h"

#define TCCR1A            *((volatile uint8*)(0x4F))
#define TCCR1B            *((volatile uint8*)(0x4E))
#define TCNT1             *((volatile uint16*)(0x4C))
#define OCR1A             *((volatile uint16*)(0x4A))
#define OCR1B             *((volatile uint16*)(0x48))
#define ICR1              *((volatile uint16*)(0x46))
#define TIMSK             *((volatile uint8*)(0x59))


#endif /* PWM_PRIVATE_H_ */

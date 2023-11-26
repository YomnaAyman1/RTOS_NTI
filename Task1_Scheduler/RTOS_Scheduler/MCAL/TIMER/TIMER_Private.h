/*
 * TIMER_Private.h
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TIMERS_TCCR0_REG    *((volatile u8*) (0x53))
#define TIMERS_TCNT0_REG    *((volatile u8*) (0x52))
#define TIMERS_OCR0_REG     *((volatile u8*) (0x5C))
#define TIMERS_TIMSK_REG    *((volatile u8*) (0x59))
#define TIMERS_TIFR_REG     *((volatile u8*) (0x58))



#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */

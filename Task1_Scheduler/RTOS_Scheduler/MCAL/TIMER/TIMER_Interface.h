/*
 * TIMER_Interface.h
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_


#define NORMAL_MODE    0
#define CTC_MODE           1
#define PWM_MODE            2
#define FAST_PWM_MODE       4

#define CounterMode     NORMAL_MODE


void Timers_void_Timer0Init ();
void Timers_voidSetCallBack_T0_CompareMatch( void ( *LPF_1)(void));

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */

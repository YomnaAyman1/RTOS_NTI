/*file guard */
#ifndef MCAL_EXTI_INTERFACE_H
#define MCAL_EXTI_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define FALLING_EDGE    0
#define RISING_EDGE     1
#define LOW_LEVEL       2
#define ON_CHANGE       4

#define INT_SENSE_CONTROL     FALLING_EDGE

#define INT0            0
#define INT1            1
#define INT2            2

#define INT_ENABLE      INT1
void EXTI_INIT(void);
void EXTI_voidEnableInterrupt (u8 Copy_u8ExtiNum , u8 Copy_u8SenseControl);
void EXTI_voidDisableInterrupt (u8 Copy_u8ExtiNum );
void EXTI_voidSetCALLBack(void (*LPF) (void));


#endif

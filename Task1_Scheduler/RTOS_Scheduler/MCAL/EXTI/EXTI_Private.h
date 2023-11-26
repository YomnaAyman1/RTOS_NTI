/*
 * EXTI_Private.h
 *
 *  Created on: 2023
 *      Author: Yomna
 */

#ifndef MCAL_EXTI_PRIVATE_H_
#define MCAL_EXTI_PRIVATE_H_



#define MCUCR_REG      *((volatile u8*) (0x55))
#define MCUCSR_REG     *((volatile u8*) (0x54))
#define GICR_REG       *((volatile u8*) (0x5B))
#define GIFR_REG       *((volatile u8*) (0x5A))


#endif /* MCAL_EXTI_PRIVATE_H_ */

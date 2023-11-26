/*
 * INTERRUPTS_REGs.h
 *
 * Created: 11-Nov-23 3:18:24 PM
 *  Author: JOE
 */ 


#ifndef INTERRUPTS_REGS_H_
#define INTERRUPTS_REGS_H_

#include "STD.h"

/*

 BIT NO.7 IN THIS REG. IS THE ONE RESPONSIBLE FOR ENABLING THE GLOBAL INTERRUPT ... 0 DIS , 1 ENABLE 
 
 ( NAME: STATES REGISTER )
 
*/

#define SREG (*(volatile uint8*)(0x5F))      

 /*
 
  BIT NO.6 IN THIS REG. IS THE ONE RESPONSIBLE FOR ENABLING THE EXTERNAL_INTERRUPT0 .. 0 DIS , 1 ENABLE 
  
  ( FOR EACH EXTERNAL INTERRUPT , THEIR IS A PIN RESPOSIABLE FOR IT .. DATA SHEET  )
  
 */

#define GICR (*(volatile uint8*)(0x5B))   

/*

 BIT NO.6 IN THIS REG. IS THE ONE RESPONSIBLE FOR RISING A FLAG WHEN EXTERNARL_INTERRUPT0 IS ENABLED .. 0 DIS , 1 ENABLE 
 
 ( FOR EACH EXTERNAL INTERRUPT , THEIR IS A PIN RESPOSIABLE FOR IT .. DATA SHEET  )
 
*/ 

#define GIFR (*(volatile uint8*)(0x5A))    

/*

RESPONSIBLE FOR STATING AT WHICH SIGNAL LEVEL THE INTERRUPTS SHOULD ACCOUR ..( DATA SHEET )

*/

#define MCUCR (*(volatile uint8*)(0x55))  

#define MCUCSR (*(volatile uint8*)(0x54))




#endif /* INTERRUPTS_REGS_H_ */
/*
 * UART_REGs.h
 *
 * Created: 11-Nov-23 3:24:26 PM
 *  Author: JOE
 */ 


#ifndef UART_REGS_H_
#define UART_REGS_H_

#include "STD.h"

/*
  PLEASE KEEP IN MIND THAT ( UCSRC ) & ( UBRRH ) ARE BOTH HAVING THE SAME ADDRESS, TO CHOOSE WHICH REG TO USE 
  
  WRITE 1 ON BIT.7 IN ( UCSRC ) TO USE UCSRC : BY DEFULT IS SET	
  
  WRITE 0 ON BIT.7 IN ( UCSRC ) TO USE UBRRH		
 */						
																	
/*
 DATA REG.  
 
 WHEN READING  (RECIEVING ) : RX 
 
 WHEN WRITTING ( SENDING ) :  TX
*/
														
#define UDR 				(*(volatile uint8 *)(0x2C))	


// THE ONES RESPONSIBLE FOR INITILIZING ALL THE CONFIGURATIONS IN UART //


#define UCSRA 				(*(volatile uint8 *)(0x2B))
#define UCSRB 				(*(volatile uint8 *)(0x2A))
#define UCSRC				(*(volatile uint8 *)(0x40))

/*
 RESPONSIBLE FOR SELECTING THE BAUD RATE
-> THE " HIGH " & " LOW " IDEA WAS MADE IN ORDER TO BE ABLE TO DIVIDE BY LARGE NUMBER AS HAVING ONLY 8 BITS IS NOT ENOUGH 
-> FIRST IT WIL FILL THE 8 BITS OF UBRRL THEN USE THE FOUR BITS ( IF NEEDED ) OF UBRRH 
*/

#define UBRRH 				(*(volatile uint8 *)(0x40))
#define UBRRL    			(*(volatile uint8 *)(0x29))




#endif /* UART_REGS_H_ */
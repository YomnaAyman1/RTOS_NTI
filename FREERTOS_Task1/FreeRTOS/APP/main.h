/*
 * main.h
 *
 *  Created on: Nov 11, 2023
 *      Author: LapTop
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

#include "avr/io.h"


/*Enable Global Interrupt*/


void  Enable_Global_Interrupt(void)
{
	SREG |= (1<<7);
}


#endif /* APP_MAIN_H_ */

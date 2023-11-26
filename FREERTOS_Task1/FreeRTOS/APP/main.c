/*
 * main.c
 *
 *  Created on: Nov 11, 2023
 *      Author: LapTop
 */

#include "util/delay.h"
//#include "avr/io.h"

#include "../MCAL/DIO/HEADER/DIO_PROTO_TYPES.h"
#include "../MCAL/ICU/HEADER/ICU_PROTO_TYPES.h"
#include "../HAL/SERVO/HEADER/SERVO_PROTO_TYPES.h"
#include "../HAL/Ultrasonic/HEADER/ultrasonic_PROTO_TYPES.h"
#include "../HAL/LCD/HEADER/LCD_PROTO_TYPES.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "main.h"

TaskHandle_t xHandle1 = NULL;
TaskHandle_t xHandle2 = NULL;

void ToggleLED1 (void);
void ToggleLED2 (void);

int main ()
{
	DIO_SET_PIN_DIREC(DIO_PORTA, DIO_PIN0, OUTPUT);
	DIO_SET_PIN_DIREC(DIO_PORTA, DIO_PIN5, OUTPUT);

	xTaskCreate(ToggleLED1, NULL, 85, NULL, 2, &xHandle1);
	xTaskCreate(ToggleLED2, NULL, 85, NULL, 1, &xHandle2);
	vTaskStartScheduler();
	while (1)
	{

	}
}

void ToggleLED1 (void)
{
	while(1)
	{
		DIO_TOOGLE_PIN(DIO_PORTA, DIO_PIN0);
		vTaskDelay(1000);
	}
}

void ToggleLED2 (void)
{
	while(1)
	{
		DIO_TOOGLE_PIN(DIO_PORTA, DIO_PIN5);
		vTaskDelay(500);
	}
}

#if(0)
int main()
{
   // DIO_SET_PIN_DIREC(DIO_PORTA , DIO_PIN0 ,OUTPUT);
    //DIO_SET_PIN_DIREC(DIO_PORTD , DIO_PIN5 ,OUTPUT);
    //DIO_SET_PIN_VALUE(DIO_PORTD , DIO_PIN5 ,STD_HIGH);
    uint16 distance = 0;

    Enable_Global_Interrupt();
    LCD_init();

    	/*Display text on LCD then move the cursor to where
    	 *the distance will be displayed*/
    	LCD_displayString("Distance =    cm");

    	/*1. Initialize Ultrasonic driver, which also initializes
    	 *   the ICU driver.
    	 *2. Setup the call back function.
    	 *3. Setup the trigger pin as output pin.
    	 */
    	Ultrasonic_init();

    	while (1)
    	{
    		/*Read the distance calculated by the Ultrasonic driver*/
    		distance = Ultrasonic_readDistance();

    		/*Display the calculated distance:*/
    		/*1. Move the cursor to where the number will be displayed.*/
    		LCD_moveCursor(0, 11);

    		/*2. This function is applied to avoid displaying the third number
    		 *from a previous reading from a number of 3 digits if the new number
    		 *is less than 100.
    		 */
    		if (distance < 30)
    		{
    			LCD_intgerToString(distance);
    			LCD_displayCharacter(' ');
    			//DIO_SET_PIN_VALUE(DIO_PORTD , DIO_PIN5 ,STD_LOW);
    		}
    		else
    		{
    			LCD_intgerToString(distance);


    			/*SERVO_u8Rotate(CHANNEL_A , 45);
    			_delay_ms(1000);*/
    			//ServoTask();
    		}

    	}

}

void ServoTask (void)
{
	SERVO_u8Rotate(CHANNEL_A , 0);
	_delay_ms(1000);

	SERVO_u8Rotate(CHANNEL_A , 45);
	_delay_ms(1000);

	SERVO_u8Rotate(CHANNEL_A , 90);
	_delay_ms(1000);

	SERVO_u8Rotate(CHANNEL_A , 135);
	_delay_ms(1000);

	SERVO_u8Rotate(CHANNEL_A , 180);
	_delay_ms(1000);
}
#endif

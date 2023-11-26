#include "../../../LIB/STD.h"
#include "../../../MCAL/PWM/HEADER/PWM_PROTO_TYPES.h"
#include "../HEADER/SERVO_CONFIG.h"
#include "../HEADER/SERVO_PROTO_TYPES.h"



uint8 SERVO_u8Rotate(uint8 Copy_u8Channel , uint8 Copy_u8Angle)
{
	/*local variable for error checking*/
	uint8 Local_u8ErrorState = OK ;

	/*local variable for value of OCR register to get target angle*/
	if (Copy_u8Angle > 180 )
	{
		Copy_u8Angle=180;
	}
	uint32 Local_u16MappedAngle = (((uint32)Copy_u8Angle * 1000) /(uint32)180)  + 999 ;


	/*checking for valid range of rotation angle*/
	if(Copy_u8Angle>=0 && Copy_u8Angle<=180)
	{
		switch(Copy_u8Channel)
		{
		case CHANNEL_A :
			PWM_u8Init(CHANNEL_A , FREQUENCY_50 , Local_u16MappedAngle);
			break ;

		case CHANNEL_B :
			PWM_u8Init(CHANNEL_B , FREQUENCY_50 , Local_u16MappedAngle);
			break ;

		default :
			break ;
		}
	}

	/*in case of input angle out of possible range*/
	else
	{
		Local_u8ErrorState = OUT_OF_RANGE ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;
}

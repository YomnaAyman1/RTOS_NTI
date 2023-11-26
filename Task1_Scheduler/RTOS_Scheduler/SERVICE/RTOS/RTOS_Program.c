
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TIMER/TIMER_Interface.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../SERVICE/RTOS/RTOS_Config.h"
#include "../../SERVICE/RTOS/RTOS_Interface.h"
#include "../../SERVICE/RTOS/RTOS_Private.h"

Task_t  RTOS_ArrTasks[RTOS_NumberTasks]= {{NULL}};
Task_t Empty = {0};
void RTOS_voidStart(void)
{
	Timers_voidSetCallBack_T0_CompareMatch(&RTOS_voidScheduler);
	GIE_voidEnableInterruptGlobal();
	Timers_void_Timer0Init();
}


void  RTOS_voidCreateTask (u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (* pvTaskFunc)(void), u8 Copy_u8FirstDelay )
{
	//Priority == index in array
	RTOS_ArrTasks[Copy_u8Priority].Copy_FirstDelay = Copy_u8FirstDelay;
	RTOS_ArrTasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
	RTOS_ArrTasks[Copy_u8Priority].TaskFunc=pvTaskFunc;
	RTOS_ArrTasks[Copy_u8Priority].State = READY;

}


void RTOS_voidScheduler (void)
{
	static  u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;
	Local_u16TickCounter++;
	// loop on all tasks to check Periodicity
	for (Local_u8TaskCounter=0 ; Local_u8TaskCounter < RTOS_NumberTasks ; Local_u8TaskCounter++)
	{
		if((Local_u16TickCounter % RTOS_ArrTasks[Local_u8TaskCounter].Periodicity)==0 && (RTOS_ArrTasks[Local_u8TaskCounter].State==READY) && (RTOS_ArrTasks[Local_u8TaskCounter].Copy_FirstDelay) == 0 )
		{
			// invoke the task func
			if (RTOS_ArrTasks[Local_u8TaskCounter].TaskFunc != NULL)
			{
				RTOS_ArrTasks[Local_u8TaskCounter].State = Running;
				RTOS_ArrTasks[Local_u8TaskCounter].TaskFunc();
				RTOS_ArrTasks[Local_u8TaskCounter].Copy_FirstDelay =RTOS_ArrTasks[Local_u8TaskCounter].Periodicity -1;
                RTOS_ArrTasks[Local_u8TaskCounter].State = READY;

			}
			else
			{
				//DO NOTHING
			}
		}
		else
		{
			RTOS_ArrTasks[Local_u8TaskCounter].Copy_FirstDelay --;
		}
	}

}


u8  RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	u8 Local_u8ReturnState = 0;
	if (RTOS_ArrTasks[Copy_u8Priority].State == Running)
	{
		RTOS_ArrTasks[Copy_u8Priority].State = Suspended;
	}
	else
	{
		Local_u8ReturnState = 1;
	}
	return Local_u8ReturnState;
}

u8  RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	u8 Local_u8ReturnState = 0;
	if (RTOS_ArrTasks[Copy_u8Priority].State != 0)
	{
		RTOS_ArrTasks[Copy_u8Priority].State = READY;
	}
	else
	{
		Local_u8ReturnState = 1;
	}
	return Local_u8ReturnState;

}

void  RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	u8 Local_u8ReturnState = 0;
	if (RTOS_ArrTasks[Copy_u8Priority].State != DORMANT)
	{
		RTOS_ArrTasks[Copy_u8Priority].State = DORMANT;
		RTOS_ArrTasks[Copy_u8Priority].TaskFunc=NULL;
	}
	else
	{
		Local_u8ReturnState = 1;
	}
}


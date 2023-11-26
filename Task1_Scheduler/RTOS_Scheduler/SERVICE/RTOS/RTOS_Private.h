
#ifndef    RTOS_PRIVATE_H
#define    RTOS_PRIVATE_H


typedef enum
{
	Suspended,
	Running,
	READY,
	DORMANT
}TaskState_t;


// create task different object in task
typedef struct
{
	u16 Periodicity ;
	void (* TaskFunc)(void);
	u8 Copy_FirstDelay;
	// To use in suspend function & resume
	TaskState_t State ;
}Task_t;


void RTOS_voidScheduler (void);


#endif

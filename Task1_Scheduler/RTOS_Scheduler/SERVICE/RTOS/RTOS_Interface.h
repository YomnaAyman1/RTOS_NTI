

#ifndef    RTOS_INTERFACE_H
#define    RTOS_INTERFACE_H


void RTOS_voidStart(void);

void  RTOS_voidCreateTask (u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (* pvTaskFunc)(void), u8 Copy_u8FirstDelay );
//, u8 Copy_u8FirstDelay
// To stop task
u8  RTOS_voidSuspendTask(u8 Copy_u8Priority);
// To return task
u8  RTOS_voidResumeTask(u8 Copy_u8Priority);
//Delete task
void  RTOS_voidDeleteTask(u8 Copy_u8Priority);

#endif

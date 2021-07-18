#include "vardef.h"

typedef struct
{
	uint32 Os_1ms_Counter;
	uint32 Os_5ms_Counter;
	uint32 Os_10ms_Counter;
	uint32 Os_100ms_Counter;
    uint32 Os_1000ms_Counter;
}Os_Counter_t;

extern void Os_Init_Task(void);
extern void Os_1ms_Task(void);
extern void Os_5ms_Task(void);
extern void Os_10ms_Task(void);
extern void Os_100ms_Task(void);
extern void Os_1000ms_Task(void);
extern void Os_Handler(void);
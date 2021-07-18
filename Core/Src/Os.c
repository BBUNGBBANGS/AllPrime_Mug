#include "Os.h"

void Os_Init_Task(void)
{

}

void Os_1ms_Task(void)
{

}

void Os_5ms_Task(void)
{

}

void Os_10ms_Task(void)
{

}

void Os_100ms_Task(void)
{

}

void Os_1000ms_Task(void)
{

}
Os_Counter_t Os_Counter;
void Os_Handler(void)
{
	if(Os_Counter.Os_1ms_Counter % 1 == 0)
	{
		(void)Os_1ms_Task();
		Os_Counter.Os_1ms_Counter++;
	}
	if(Os_Counter.Os_1ms_Counter % 5 == 0)
	{
		(void)Os_5ms_Task();
		Os_Counter.Os_5ms_Counter++;
	}
	if(Os_Counter.Os_1ms_Counter % 10 == 0)
	{
		(void)Os_10ms_Task();
		Os_Counter.Os_10ms_Counter++;
	}
	if(Os_Counter.Os_1ms_Counter % 100 == 0)
	{
		(void)Os_100ms_Task();
		Os_Counter.Os_100ms_Counter++;
	}
	if(Os_Counter.Os_1ms_Counter % 1000 == 0)
	{
		(void)Os_1000ms_Task();
		Os_Counter.Os_1000ms_Counter++;
	}

    return;
}
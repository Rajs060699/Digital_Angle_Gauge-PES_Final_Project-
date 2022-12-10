/*****************************
 * Title:Systick.c
 *
 * Author:Rajesh Srirangam
 *
 * Description :: Implementing five functions in this file:
* 				  init_systick()	- to configure the systick timer of KL25Z
*				  systick_handler()	- to obtain interupt for every 10ms
*				  now()				- to get time since startup
*				  reset_timer()		- to reset timer to count to 0
*				  get_timer()		- to get time since reset
*
*			   Tools used	: MCUXpresso,FRDM-KL25Z dev board
*
*
*
*
*
 *
 */
#include "Systick.h"
typedef uint32_t ticktime_t;
static volatile ticktime_t boottime=0;
static volatile ticktime_t count=0;
int flag=0;
/**
 *
 * @function	: function to set the clock and configure the Systick timer
 *
 * @parameters	: NULL
 * @return		: returns NULL
 */
void init_systick()
{
	SysTick->LOAD=479999;
	NVIC_SetPriority(SysTick_IRQn,3);
	SysTick->VAL=0;
	SysTick->CTRL=SysTick_CTRL_TICKINT_Msk|SysTick_CTRL_ENABLE_Msk|SysTick_CTRL_CLKSOURCE_Msk ;
}
/**
 *
 * @function	: function to return the time since startup
 *
 * @parameters	: none
 * @return		: returns time since startup
 */
ticktime_t now()
{
return boottime;
}
/**
 *
 * @function	: function to reset timer to 0
 *
 * @parameters	: NULL
 * @return		: returns NULL
 */

void reset_timer()
{
count=0;
}
/**
 *
 * @function	: function to return ticks since the last call to reset_timer()-get_timer()
 *
 * @parameters	: NULL
 * @return		: returns the time since last call to reset
 */

ticktime_t get_timer()
{
return count;
}
/**
 *
 * @function	: timer interrupt called based on the timer value where count,bootime incremented
 *
 * @parameters	: none
 * @return		: returns NULL
 */

void SysTick_Handler()
{
count++;
boottime++;
flag=1;
}
/**
 *
 *@function: To get interrupt status using bool as function
 * @parameters	: none
 * @return		: returns bool status
 */

bool get_interrupt_status()
{
	bool value = 0;
	NVIC_DisableIRQ(SysTick_IRQn); //Disable IRQ
	if(flag == 1)
	{
		value = 1;
	}
	else
	{
		value = 0;
	}
	flag = 0;
	NVIC_EnableIRQ(SysTick_IRQn); //Enable IRQ
	return value;
}


/****************************
 * Title:Systick.h
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
 *
 *

 */
/*****************************HEADERS*********************/
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <MKL25Z4.h>

/*************************FUNCTION DEFINITIONS ************************/
void init_systick();
/**
 *
 * @function	: function to set the clock and configure the Systick timer
 *
 * @parameters	: NULL
 * @return		: returns NULL
 */
void reset_timer();
/**
 *
 * @function	: function to reset timer to 0
 *
 * @parameters	: NULL
 * @return		: returns NULL
 */

bool get_interrupt_status();
/**
 *
 *@function: To get interrupt status using bool as function
 * @parameters	: none
 * @return		: returns bool status
 */
typedef uint32_t ticktime_t;
ticktime_t get_timer();
ticktime_t now();
/**
 *
 *@function: It gives current time for the every interrupt of 10ms occured
 * @parameters	: none
 * @return		: returns bool status
 */


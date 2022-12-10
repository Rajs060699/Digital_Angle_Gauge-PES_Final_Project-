/***********************************
 * Title:LED.h
 *
 *Description:Declaration of three function to configure TPM Clock,Duty cycles,Transition of colors from initial to final
 *
 *Author:Rajesh Srirangam
 *
 *Reference links: *https://github.com/alexander-g-dean/ESF/tree/master/NXP/Code/Chapter_7/PWM_LED/Source
 *
 */
/*********************************HEADERS*************************/
#include <MKL25Z4.h>
/********************************FUNCTION DEFINITIONS*******************/
void PWM_START();
/**
 * @function	: function to configure RGB Leds through TPM module and enable the clocks to 48Mhz
 *
 * @parameters	: NULL
 * @return		: NULL
 */


void colors();
/**********************************
 *@function:Function to compute duty cycles of RGB with the help of MOD 48000 and able to control leds through Duty cycles
 *
 *@parameters:Return RGB to colors function when used
 *
 *@return:NULL
 *
 *
 */

/*******************************
 *
 * Author Rajesh Srirangam
 * Title test_led_pwm.c
 * Description Used for testing LED glow through PWM
 */

/*********HEADERS********/
#include "test_led_pwm.h"
#include "fsl_debug_console.h"
/*************************/

/***************************
 * Function test_led_PWM()
 * Param NULL
 * Return NULL
 * Description Used for testing LED running through PWM
 */
void test_led_PWM()
{
	PRINTF("Red LED Initiated\r\n");
    colors(255,0,0);
	reset_timer();
	while(get_timer() < DELAY_500MSEC);

	PRINTF("Green LED Initiated\r\n");
	colors(0,255,0);
	reset_timer();
	while(get_timer() < DELAY_500MSEC);

	PRINTF("Blue LED Initiated\r\n");
	colors(0,0,255);
	reset_timer();
	while(get_timer() < DELAY_500MSEC);

	PRINTF("White LED Initiated\r\n");
	colors(255,255,255);
	reset_timer();
	while(get_timer() < DELAY_500MSEC);

	PRINTF("Colors Off\r\n");
    colors(0,0,0);
	reset_timer();
	while(get_timer() < DELAY_500MSEC);

	PRINTF("LED Test through PWM Done\r\n");

}

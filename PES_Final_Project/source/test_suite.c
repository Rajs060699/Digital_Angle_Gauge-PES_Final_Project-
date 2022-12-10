/******************************
 * Author Rajesh Srirangam
 * Title test_suite.h
 * Description Used for testing modules
 */

/**********HEADERS**********/
#include "test_suite.h"
#include "fsl_debug_console.h"
/****************************/

/********************************
 * Function test_suite()
 * Return NULL
 * Param NULL
 * Description Used for running test suites for modules like PWM,DAG and CBFIFO
 */
void test_suite()
{
	PRINTF("Testing started\r\n");

	PRINTF("cbfifo test started\r\n");
	test_cbfifo();
	PRINTF("cbfifo test done\r\n");

	PRINTF("PWM Test started\r\n");
	test_led_PWM();
	PRINTF("PWM Test Closed\r\n");

	PRINTF("Angle Detection Test Started\r\n");
	test_angle_detect_color();
	PRINTF("Angle Detection Test Done\r\n");

	PRINTF("Testing complete\r\n");
}


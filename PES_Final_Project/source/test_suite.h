/******************************
 * Author Rajesh Srirangam
 * Title test_suite.h
 * Description Used for testing modules
 */

/**********HEADERS********/
#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "test_cbfifo.h"
#include "test_led_pwm.h"
#include "test_angle_detect.h"
/*****************************/

/********************************
 * Function test_suite()
 * Return NULL
 * Param NULL
 * Description Used for running test suites for modules like PWM,DAG and CBFIFO
 */
void test_suite();

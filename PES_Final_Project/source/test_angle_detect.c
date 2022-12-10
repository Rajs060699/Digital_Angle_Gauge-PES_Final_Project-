/*****************************
 * Author Rajesh Srirangam
 * Title test_angle_detect.h
 * Description Used for angle detection test
 */

/**********HEADERS**********/
#include "test_angle_detect.h"
#include "fsl_debug_console.h"
#include "statemachine.h"
/*************************/


/*************************
 * Function test_angle_detect_color()
 * Param NULL
 * Return NULL
 * Description Used for testing angle detection
 */
void test_angle_detect_color()
{
	/* angle 0 test case */
	PRINTF("Angle 0 not detected as not present. No color lit.\r\n");
	angle_detect_color_assign(0,0);
	reset_timer();
	while(get_timer() <DEL_500MSEC);

	/* angle 30 test case */
	PRINTF("Angle 30 detected. Red color lit.\r\n");
	angle_detect_color_assign(30,30);
	reset_timer();
	while(get_timer() < DEL_500MSEC);

	/* angle 45 test case */
	PRINTF("Angle 45 detected. Green color lit.\r\n");
	angle_detect_color_assign(45,45);
	reset_timer();
	while(get_timer() < DEL_500MSEC);

	/* angle 60 test case */
	PRINTF("Angle 60 detected. Blue color lit.\r\n");
	angle_detect_color_assign(60,60);
	reset_timer();
	while(get_timer() < DEL_500MSEC);

	/* angle 90 test case */
	PRINTF("Angle 90 detected. White color lit.\r\n");
	angle_detect_color_assign(90,90);
	reset_timer();
	while(get_timer() < DEL_500MSEC);

	/* angle -1 test case */
	PRINTF("Invalid angle. No color lit.\r\n");
	angle_detect_color_assign(-1,-1);
	reset_timer();
	while(get_timer() < DEL_500MSEC);

}

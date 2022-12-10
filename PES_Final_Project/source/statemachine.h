/*************************************
 * Author Rajesh Srirangam
 * Title statemachine.h
 * Description Used for state machine initialisation
 */

/***********HEADERS**********/
#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "MMA8451Q.h"
#include "LED.h"
#include "Systick.h"
#include "switch.h"
/***************************/

/**********MACROS**********/
#define DELAY_750 75
#define DELAY_250 25
#define MAINTAIN_REFERENCE_LEVEL 0
#define UPDATE_REFERENCE_LEVEL 1
/**************************/

/**************STRUCTURES***************/
typedef enum
{
	INITIALISATION_STATE=0,
    CALIBRATION_STATE,
	COMPUTE_ANGLE_TILT
}state_t;
/*************************************/

/******************************
 * Function handle_calibrate_to_zero
 * Param NULL
 * Return NULL
 * Description Used for setting calibrate to zero
 */
state_t handle_calibrate_to_zero();


/******************************
 * Function handle_calibrate_state
 * Param NULL
 * Return NULL
 * Description Used for setting calibrate in any state
 */
state_t handle_calibrate_state();

/******************************
 * Function handle_angle_gauge_state
 * Param NULL
 * Return NULL
 * Description Used for setting angle for any given state
 */
state_t handle_angle_gauge_state();

/******************************
 * Function angle_detect_color_assign
 * Param NULL
 * Return NULL
 * Description Used for setting color based on the angle
 */

void angle_detect_color_assign(int,int);

/******************************
 * Function set_reference_angle
 * Param NULL
 * Return NULL
 * Description Used for setting reference angle
 */

void set_reference_angle(int);

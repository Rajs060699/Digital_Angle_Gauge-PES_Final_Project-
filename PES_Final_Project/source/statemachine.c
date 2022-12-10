/*************************************
 * Author Rajesh Srirangam
 * Title statemachine.h
 * Description Used for state machine initialisation
 */

/**************HEADERS**********/
#include "statemachine.h"
#include "fsl_debug_console.h"
/******************************/

/*********GLOBAL DECLARATION**********/
int accel_state=0;
acclerometer_parameters_t accelerometer_parameters = {0,0,0,0,0,0,0};
extern uint8_t switch_initiated;
extern int cap_tap_detected;
int reference_angle = 0;
extern int calibrate_receive_flag;
extern int final_roll_val;
extern int final_pitch_val;
/**********************************/

/**************************
 * Function void state_machine()
 * Return NULL
 * Param NULL
 * Description Used for Initialisation of state machine
 */
void state_machine()
{

		switch(accel_state)
		{
			case INITIALISATION_STATE: 		 handle_calibrate_to_zero();
											 break;
			case CALIBRATION_STATE:	         handle_calibrate_state();
											 break;
			case COMPUTE_ANGLE_TILT:		 handle_angle_gauge_state();
											 break;
		}
}

/******************************
 * Function handle_calibrate_to_zero
 * Param NULL
 * Return NULL
 * Description Used for setting calibrate to zero
 */

state_t handle_calibrate_to_zero()
{
		colors(0,0,255);
	 read_full_xyz(&accelerometer_parameters);
	 convert_xyz_to_roll_pitch(&accelerometer_parameters,MAINTAIN_REFERENCE_LEVEL);
	 if(accelerometer_parameters.roll_val == 0.0)
	  {
		convert_xyz_to_roll_pitch(&accelerometer_parameters,UPDATE_REFERENCE_LEVEL);
		if(accelerometer_parameters.ref_roll_val < 0)
		{
			accelerometer_parameters.ref_roll_val = accelerometer_parameters.ref_roll_val*(-1);
		}
		PRINTF("Angle Zero Detection\n\r");
				colors(0,0,0);
				reset_timer();
				while(get_timer() < DELAY_250);
		set_reference_angle((int)accelerometer_parameters.ref_roll_val);
		accel_state= COMPUTE_ANGLE_TILT;
		return accel_state;
	}
	 if(calibrate_receive_flag==1||switch_initiated==1)
	 {
		 calibrate_receive_flag=1;
		 switch_initiated=0;
			accel_state= CALIBRATION_STATE;
				return accel_state;
	 }
	accel_state= INITIALISATION_STATE;
		return accel_state;
}

/******************************
 * Function handle_calibrate_state
 * Param NULL
 * Return NULL
 * Description Used for setting calibrate in any state
 */

state_t handle_calibrate_state()
{
    colors(0,0,0);
	//if(cap_tap_detected||calibrate_receive_fl)
		//cap_tap_detected = 0;
		calibrate_receive_flag=0;
		printf("Calibrated if touch capacitor detected\r\n");
		read_full_xyz(&accelerometer_parameters);
		convert_xyz_to_roll_pitch(&accelerometer_parameters,UPDATE_REFERENCE_LEVEL);
		if(accelerometer_parameters.ref_roll_val < 0)
		{
			accelerometer_parameters.ref_roll_val = accelerometer_parameters.ref_roll_val*(-1);
		}
		set_reference_angle((int)accelerometer_parameters.ref_roll_val);
		accel_state= COMPUTE_ANGLE_TILT;
			return accel_state;
//    colors(0,0,0);
//    accel_state= CALIBRATION_STATE;
//	return accel_state;
}


/******************************
 * Function handle_angle_gauge_state
 * Param NULL
 * Return NULL
 * Description Used for setting angle for any given state
 */

state_t handle_angle_gauge_state()
{

	read_full_xyz(&accelerometer_parameters);
	convert_xyz_to_roll_pitch(&accelerometer_parameters,MAINTAIN_REFERENCE_LEVEL);
	if(accelerometer_parameters.roll_val < 0)
	{
		accelerometer_parameters.roll_val = accelerometer_parameters.roll_val*(-1);
	}
    colors(0,0,0);
    final_roll_val =  (int)(accelerometer_parameters.roll_val - accelerometer_parameters.ref_roll_val);
    final_pitch_val= (int)(accelerometer_parameters.pitch_val - accelerometer_parameters.ref_pitch_val);
	angle_detect_color_assign(final_roll_val,final_pitch_val);
	if(switch_initiated||calibrate_receive_flag)
	{
		switch_initiated = 0;
		calibrate_receive_flag=0;
		accel_state= CALIBRATION_STATE;
					return accel_state;
	}
	accel_state= COMPUTE_ANGLE_TILT;
					return accel_state;
}

/******************************
 * Function angle_detect_color_assign
 * Param NULL
 * Return NULL
 * Description Used for setting color based on the angle
 */

void angle_detect_color_assign(int color_assign_roll,int color_assign_pitch)
{
	if(color_assign_roll==30||color_assign_pitch==30)
		{

			colors(255,0,0);

		}
	else if(color_assign_roll==45||color_assign_pitch==45)
		{

			colors(0,255,0);

		}
	else if(color_assign_roll==60||color_assign_pitch==60)
		{

			colors(0,0,255);

		}
	else if(color_assign_roll==90||color_assign_pitch==90)
		{

	        colors(255,255,255);
		}
	}

/******************************
 * Function angle_detect_color_assign
 * Param NULL
 * Return NULL
 * Description Used for setting color based on the angle
 */

void set_reference_angle(int ref_received )
{
	reference_angle = ref_received;
}

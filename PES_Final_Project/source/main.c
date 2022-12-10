/**********************************
 * Author Rajesh Srirangam
 * Title main.c
 * Description: Used for intialisation functions
 *
 */

/***************HEADERS***************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "I2C.h"
#include "UART.h"
#include "LED.h"
#include  "switch.h"
#include "Systick.h"
#include "sysclock.h"
#include "statemachine.h"
#include "test_suite.h"
/*****************************/

/*******function prototypes*******/
void System_Start();
void state_machine();
void calibrate_check();
/*********************************/

/*********MACROS**********/
#define BAUDRATE 38400
/**************************/

/*************GLOBAL DECLARATION**********/
int flag_check = 0;
char *inputstr;
char str[256];
int calibrate_receive_flag = 0;
int angle_receive_flag=0;
int i =0;
char ch1;
int final_roll_val;
int final_pitch_val;
/************************************/

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
    PRINTF("System Initialisation Started.............\n\r");
    System_Start(); //System_Initialisation
    PRINTF("Entered Test Suite to Test Modules\n\r");
    test_suite(); //test modules
    while(1)
    {
    	calibrate_check();  //calibrate check includes command for calibrate and angle
    	//PRINTF("\n\r?");
    	//initiate_command_input();
        state_machine();  //state machine intialisation
    }
    return 0;
}

/***********************************
 * Function void calibrate_check()
 * Return NULL
 * Param NULL
 * Description Used to pass commands like angle and caliberate
 */
void calibrate_check()
{
   		ch1 = getchar();
   		if(ch1!= 0 && ch1!='\r')    //check enter and command
   		{
   				if(ch1 == 0x08)   //backspace
   				{
   					i--;
   					str[i] = '\0';
   					ch1 = getchar();
   				}
   				else
   				{
   					str[i] = ch1; //if enter or backspace not given
   					i++;
   				}
   			}

   			else if(ch1 == '\r')    //Enter command check
   			{
   				flag_check = 1;
   				str[i] = '\0';
   			}

   		if(flag_check == 1)
   		{
   				int compare_calib,compare_angle;
   				compare_calib =strcmp(str,"calibrate");
   				compare_angle=strcmp(str,"angle");
   					if(compare_calib== 0)    //comapre caliberation
   					{
   						calibrate_receive_flag = 1;
   						flag_check = 0;
   						i = 0;
   					}
   					else if(compare_angle==0)  //compare angle
   					{
   						PRINTF("roll angle =%d deg \n\r",final_roll_val);
   						PRINTF("pitch angle =%d deg \n\r",final_pitch_val);
   						flag_check = 0;
   						i=0;
   					}
   					else
   					{
   						PRINTF("Unknown Command\n\r");
   						i = 0;
   						flag_check = 0;
   					}
   					PRINTF("\n\r");
   					PRINTF("Enter Commands to do Calibrate and for Angle detection\n\r");
   		}
   }
void System_Start()
{
	    sysclock_init(); //system clock intialisation
	    init_systick();  //systick initialisation
	    PWM_START();    //PWM LED colors intialisation
	    uart0_init(BAUDRATE);  //uart initialisation
		//__enable_irq();//enable interrupt
	    init_switch();   //switch initialisation
	    i2c_init();    //i2c initialisation
	    /* Initialize the accelerometer */
	    	if (!init_mma())
	    	{
	    		/* Light red error LED */
	    		colors(255, 0, 0);
	    		while (1)
	    			;
	    		/* not able to initialize mma */
	    	}
}


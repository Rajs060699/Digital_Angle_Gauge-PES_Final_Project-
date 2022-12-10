/********************************
 * Title:LED.c
 *
 * Author:Rajesh Srirangam
 *
 * Description:Implementation of three functions PWM_START()-To initialise TPM module
 *                                               colors(red,green,blue)-To update Cnv Values
 *                                               transitioncolor_state()-used to compare initial and final values of states
 *Tools used:MCUXpresso,FRDM KL25Z
 *
 *Identification of leveraged code:
 *
 *Applicable links:
 *
 *https://github.com/alexander-g-dean/ESF/tree/master/NXP/Code/Chapter_7/PWM_LED/Source
 *
 *
 */
/***********HEADERS**********/
#include "LED.h"
/**************************/

/*******MACROS********/
#define RED_LED 18
#define GREEN_LED 19
#define BLUE_LED 1
#define DELAY1S 100
/*******************/

/*********GLOBAL DECLARATION***********/
int red = 0, green = 0, blue = 0;
/***********************************/

/**
 * @function	: void PWM_START()
 *
 * @parameters	: NULL
 * @return		: NULL
 * @Description : function to configure RGB Leds through TPM module and enable the clocks to 48Mhz
 */


void PWM_START()
{
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;        // Enable clock for port D
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;        // Enable clock for port B
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;         // Enable clock for TPM0
	SIM->SCGC6 |= SIM_SCGC6_TPM2_MASK;         // Enable clock for TPM2
	PORTB->PCR [RED_LED] &=~PORT_PCR_MUX_MASK; //Setting and clearing for Port B 18 pin
	PORTB->PCR [RED_LED]|=PORT_PCR_MUX(3);
	PORTB->PCR [GREEN_LED] &=~PORT_PCR_MUX_MASK; //Setting and clearing for Port B 19 pin
	PORTB->PCR [GREEN_LED]|=PORT_PCR_MUX(3);
	PORTD->PCR [BLUE_LED] &=~PORT_PCR_MUX_MASK;  //Setting and clearing for Port D 1st pin
	PORTD->PCR [BLUE_LED]|=PORT_PCR_MUX(4);//Set Pin 1 of port D as Alternate function
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC (1) | SIM_SOPT2_PLLFLLSEL_MASK); //Setting clock for 48MHz
	TPM2->MOD=480000;             				//Loading the counter to 48000
	TPM0->MOD=480000;             				//Loading the counter to 48000
	TPM2->SC= TPM_SC_PS(1);       				//Setting TPM direction to prescalar 2
	TPM0->SC= TPM_SC_PS(1);       				//Setting TPM direction to prescalar 2
	TPM2->CONF|=TPM_CONF_DBGMODE(3); 			//Can be operated in debug mode
	TPM0->CONF|=TPM_CONF_DBGMODE(3);  			//Can be operated in debug mode
	TPM2->CONTROLS[0]. CnSC= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK; //Setting channel 0 to edge aligned low TPM
	TPM2->CONTROLS [0].CnV=0;           		//Setting duty cycle of channel 0 to 0
	TPM2->CONTROLS[1]. CnSC= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK; //Setting channel 1 to edge aligned low TPM
	TPM2->CONTROLS [1].CnV=0;         			//Setting duty cycle of channel 1 to 0
	TPM0->CONTROLS[1]. CnSC= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK; //Setting channel 1 to edge aligned low TPM
	TPM0->CONTROLS [1].CnV=0;          			//Setting duty cycle of channel 1 to 0
	TPM2->SC |=TPM_SC_CMOD(1);          		//Set TPM
	TPM0->SC |=TPM_SC_CMOD(1);         			//Set TPM
}
/**********************************
 *@function:Function to compute duty cycles of RGB with the
 *help of MOD 48000 and able to control leds through Duty cycles
 *
 *@parameters:Return RGB to colors function when used
 *
 *@return:NULL
 *
 *
 */
void colors(int red, int green, int blue) {
	TPM2->CONTROLS[0].CnV  = (red * 48000) / 255;
	TPM2->CONTROLS[1].CnV  = (green * 48000) / 255;
	TPM0->CONTROLS[1].CnV  = (blue * 48000) / 255;
}


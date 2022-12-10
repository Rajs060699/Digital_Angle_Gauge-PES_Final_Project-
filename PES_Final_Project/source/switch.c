/******************************
 * Author Rajesh Srirangam
 * Title switch.c
 * Description Used for initialisation of switch
 * Reference links :Taken reference from Dean Code
 *
 */

/*************HEADERS**********/
#include "switch.h"
/***************************/

/********GLOBAL HEADERS********/
int switch_initiated=0;
/***************************/


/*****************************
 * Function init_switch()
 * Param NULL
 * Return NULL
 * Description Used for initialisation of switch
 */
void init_switch()
{

	/* Enable clock source to the pin */
		SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
		/* Setting up port multiplexing for GPIO */
		PORTD->PCR[SWITCH_POS] &= ~PORT_PCR_MUX_MASK;
		PORTD->PCR[SWITCH_POS] |= PORT_PCR_MUX(1);

		/* Enable the pull select and pull enable */
		PORTD->PCR[SWITCH_POS] |= PORT_PCR_PE(1) | PORT_PCR_PS(1);

		/* Enable the interrupt on any edge */
		PORTD->PCR[SWITCH_POS] |= PORT_PCR_IRQC(11);

		/* Set direction to input */
		GPIOD->PDDR &= ~(1 << SWITCH_POS);

		/* Set the priroity of switch */
		NVIC_EnableIRQ(PORTD_IRQn);
}

/********************************
 * Function PORTD_IRQHandler()
 * Param NULL
 * Return NULL
 * Description Used for Push Button Interrupt
 */
void PORTD_IRQHandler(void)
{
	switch_initiated = 0;

	if ((PORTD->ISFR & (1<<SWITCH_POS)))
	{
		/* clearing on purpose to create a debounce condition */
		switch_initiated = 0;

		/* reading again to confirm that the
		 * switch was not pressed accidentally */
		if(	(GPIOD->PDIR & (1<<SWITCH_POS)) == 0)
		{
			/* Set the switch flag as the
			 * switch is pressed in reality */
			switch_initiated = 1;
		}
	}

	/* Clear the switch pin flag*/
	PORTD->ISFR |= (1<<SWITCH_POS);
}

/**********************
 * Author Rajesh Srirangam
 *
 * Title UART.c
 *
 * Applicable Links:-
 * UART_IRQHandler() -Reference Alexander G.Dean book Chapter 7
 * UART_Init()-Reference Dean Book Alexander G Dean Chapter 7
 *
 * Description:Initialising UART interrupt along with baudrate,stop bits
 */
/**********HEADERS*******/
#include "uart.h"
#include "stdio.h"
#include "sysclock.h"
#include "cbfifo.h"
/************************/
/************MACRO*****/
#define STOP_BIT 1
/**********************/
/*******GLOBAL DECLARATION******/
char ch;
circular_queue Transmission_Buffer,Receive_Buffer;
/*********************************/
/******************************
 * @Function uart0_init()
 * @Param NULL
 * @Return NULL
 * @Description Used for UART0 Initialisation
 */
void uart0_init(uint32_t baud_rate)
 {
	 uint16_t sbr;
   // Enable clock gating for UARTO and Port A
	 SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;//Enable clock for UART0
	 SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;//Port A clock enable
	 UART0->C2 &= ~UART0_C2_TE_MASK & ~UART0_C2_RE_MASK; //Receiver Enable and Transmission Enable
	 SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);//Clock source set to MCGFLLCLK or  MCGPLLCLK/2
	 SIM->SOPT2 |= 0x00U;//Clock MCGFLLCLK is set and clock is set for 24MHz
	 PORTA->PCR[1] = PORT_PCR_ISF_MASK | PORT_PCR_MUX(2); // Alternate Function Rx is set
	 PORTA->PCR[2]=  PORT_PCR_ISF_MASK | PORT_PCR_MUX(2); // Alternate Function Tx is set
	 sbr = (uint16_t) ((SYSCLOCK_FREQUENCY)/(baud_rate * UART_OVERSAMPLE_RATE));//Set Baudrate and Oversampling rate
	 UART0->BDH &= ~UART0_BDH_SBR_MASK;
	 UART0->BDH |= UART0_BDH_SBR(sbr>>8);
	 UART0->BDL = UART0_BDL_SBR(sbr);
	 //UART0->C4 |= UART0_C4_OSR(UART_OVERSAMPLE_RATE-1);
	 UART0->BDH |= UART0_BDH_RXEDGIE(0)|UART0_BDH_SBNS(STOP_BIT)|UART0_BDH_LBKDIE(0);//Stop Bit is 2 and RX interrupt and LIN is disabled
	 UART0->C1= UART0_C1_LOOPS(0) | UART0_C1_M(0) |UART0_C1_PE(0);//Start ,8 bits data and stop is enabled and parity is disabled
	 UART0->C3 = UART0_C3_TXINV (0) | UART0_C3_ORIE (1)| UART0_C3_NEIE (1) | UART0_C3_FEIE(1)| UART0_C3_PEIE (1);//Disable LoopMode
	 UART0->S1=UART0_S1_OR(1) |UART0_S1_NF(1)|UART0_S1_FE(1)|UART0_S1_PF(1);//Clear error flags
	 UART0->S2 = UART0_S2_MSBF(0)|UART0_S2_RXINV(0);//Disable invert
	  circular_queue_Init(&Transmission_Buffer);//Initiating Tx Buffer using circular queue
	  circular_queue_Init(&Receive_Buffer);//Intiating Rx buffer using circular queue
	  NVIC_SetPriority(UART0_IRQn,2);//UART Interrupt is enabled
	  NVIC_ClearPendingIRQ(UART0_IRQn);
	  NVIC_EnableIRQ(UART0_IRQn);
	  UART0->C2 |= UART_C2_RIE(1);//Receiver Interrupt is enable
	 UART0->C2 |= UART0_C2_TE(1)|UART0_C2_RE(1);//Control Registers of Receiver and Transmitter Enabled
 }
/*******************************
 * Function:UART0_IRQHandler()
 *
 * Param:NULL
 *
 * return:NULL
 *
 * Description:Intialising UART Interrupt
 */
void UART0_IRQHandler()
{
	if(UART0->S1 & (UART0_S1_OR_MASK | UART0_S1_NF_MASK | UART0_S1_FE_MASK | UART0_S1_PF_MASK))
	{
		// clear the error flags

		UART0->S1 |= UART0_S1_OR_MASK | UART0_S1_NF_MASK |	UART0_S1_FE_MASK | UART0_S1_PF_MASK;
		ch = UART0->D;		// read the data register to clear RDRF
	}
	if (UART0->S1 & UART0_S1_RDRF_MASK)
	{
			ch=UART0->D;	// received a character
			cbfifo_enqueue(&Receive_Buffer, &ch, 1);
    }
	if((UART0->C2 & UART0_C2_TIE_MASK) &&(UART0->S1 & UART0_S1_TDRE_MASK))// tx buffer empty
	{
		if(cbfifo_dequeue(&Transmission_Buffer, &ch, 1))		// can send another character
		{
			UART0->D = ch;//if character is received is stored in data register of UART0
		}
		else
		{
			UART0->C2 &= ~UART0_C2_TIE_MASK;//Clear Transmitter Interrupt Enabled
		}
	}
	else
	{
	}
	if ((UART0->S1 & UART0_S1_TDRE_MASK))//If status register is set
	{
				UART0->D = ch;//Store the character in UART0
	}
}

/*****************************
 *
 * Function:int __sys_write()
 *
 * param:NULL
 *
 * return:return data and byte size
 *
 * Description:Sys write will be functional like putchar()/printf()
 *
 */

int __sys_write(int handle, char *buf,int size)
{
	int flag = 0;
	flag = cbfifo_enqueue(&Transmission_Buffer, buf, size);//Flag is set depending on character is received or not
	if(!(UART0->C2 & UART0_C2_TIE_MASK))//if character is received
	{
		UART0->C2 |= UART0_C2_TIE(1);//Set Transmitter Interrupt
	}
	while(cbfifo_length(&Transmission_Buffer) != 0);
	if(flag == 1)
	{
		UART0->C2 &= ~UART0_C2_TIE(1);//Disable Transmitter Interrupt
		return 1;
	}
	else
	{
		return 0;
	}
}
/****************************
 * Function: int __sys_readc()
 *
 * param:NULL
 *
 * return:return character
 *
 * Decription: Sys readc works like getchar()
 */
int __sys_readc(void){

	int rx_char;

	//while(cbfifo_length(&Receive_Buffer) == 0); // wait till character is received

	if(cbfifo_dequeue(&Receive_Buffer, &rx_char, 1) == 1){  //If character received
		return rx_char;
	}
	else
	{
		return 0;
	}
}

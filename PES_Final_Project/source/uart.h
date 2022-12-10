/*****************************
 * Author:Rajesh Srirangam
 *
 * Title:uart.h
 *
 * Description:Intialising UART functions like baudrate,parity and stop bits
 */

/*********HEADERS**************/
#include "MKL25Z4.h"
/******************************/

/*********MACROS***************/
#define UART_OVERSAMPLE_RATE (16)
/*******************************/

/*******Function Prototype*******/

/**********FUNCTION ****************
 * @Function:uart0_init()
 * @Param:return baudrate
 * @Return:NULL
 * @Description Used for UART0 Initialisation
 *
 */
void  uart0_init(uint32_t baud_rate);


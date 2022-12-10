/*******************************
 * Author Rajesh Srirangam
 *
 * Title cbfifo.c
 *
 * Applicable reference
 *
 * circular buffer code -Alexander G Dean Chapter 7 (Reference)
 *
 * Description passing data in circular buffer using enqueue and dequeue operations
 */

/*********HEADERS**********/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "cbfifo.h"
#include "UART.h"
uint32_t count = 0;
/*************************
 * Function:circular_queue_init()
 *
 * Param q
 *
 * return NULL
 *
 * Description initiating read and write buffer of circular buffer
 */

void circular_queue_Init(circular_queue * q)
{
	unsigned int i;
	for (i=0; i<SIZE; i++)
	{
		q->data[i]= 0; //intialising data to NULL
	}
    q-> tail=0 ;     //initialising head and tail are NULL
    q-> head=0;
}
/*************************
 * Function cbfifo_enqueue
 *
 * Param q and nbyte
 *
 * Return NULL
 *
 * Description Will write the data in circular buffer
 */

size_t cbfifo_enqueue(circular_queue *q,void* buf, size_t nbyte)
{
	  uint32_t masking_state;
	uint8_t* buffer_ptr = (uint8_t*)buf;
if ((buf == NULL) || (nbyte < 0)) //check buffer and nbyte
{
return -1;
}
if (nbyte == 0)//check nbyte is NULL or not
{
return 0;
}
if ((nbyte + count) > SIZE)//check nbyte is within the limit or not
{
nbyte = SIZE - count;
}
int j=0;
while(j<nbyte)
 {
 q->data[q->tail++] = buffer_ptr[j];//pass the data to write buffer
 q->tail %= (SIZE-1);
 masking_state = __get_PRIMASK();
 __disable_irq();
 j++;
 count++;
 __set_PRIMASK(masking_state);
}
  	return 1;
  }
/*************************
 * Function cbfifo_dequeue
 *
 * Param q ,buf and nbyte
 *
 * Return NULL
 *
 * Description Will read the data in circular buffer
 */

size_t cbfifo_dequeue(circular_queue *q,void* buf, size_t nbyte)
{
	uint32_t masking_state;
		//size_t index = 0;
		uint8_t* buffer_ptr = (uint8_t*)buf;
if (nbyte < 0) //check nbyte is negative or not
{
return -1;
}
if(buf==NULL)//check buffer is NULL or not
{
	return -1;
}
if ((count== 0) || (nbyte == 0))//check count and nbyte is NULL or not
{
return 0;
}
if (nbyte > count)
{
nbyte = count;
}
int i=0;
while(i<nbyte)
        	{
        		buffer_ptr[i] = q->data[q->head++];//reading from the buffer
        		q->head %=(SIZE-1);
        						// save current masking state
        						masking_state = __get_PRIMASK();
        						// disable interrupts
        						__disable_irq();
        						// update variable
        						i++;
        		count--;
        		// restore  interrupt masking state
        		   			__set_PRIMASK(masking_state);
        	}
return 1;
}
/*************************
 * Function cbfifo_length
 *
 * Param NULL
 *
 * Return NULL
 *
 * Description Will provide the length of circular buffer
 */
size_t cbfifo_length()
{
return count;//will return count
}
/*************************
 * Function cbfifo_capacity
 *
 * Param NULL
 *
 * Return NULL
 *
 * Description will return the capacity of circular buffer
 */
size_t cbfifo_capacity()
{
return SIZE;      //will return the size
}

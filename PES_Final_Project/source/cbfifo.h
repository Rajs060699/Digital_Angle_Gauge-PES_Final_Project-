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
/*********HEADERS*********/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
/********MACROS**********/
#define SIZE 256

typedef struct
{
    uint32_t tail ;
    uint32_t head;
    uint8_t data[SIZE];
} volatile circular_queue;
/*************************
 * Function:circular_queue_init()
 *
 * Param circular_queue*
 *
 * return NULL
 *
 * Description initiating read and write buffer of circular buffer
 */
void circular_queue_Init(circular_queue *);
/*************************
 * Function cbfifo_enqueue
 *
 * Param circular_queue* ,size_t
 *
 * Return NULL
 *
 * Description Will write the data in circular buffer
 */

size_t cbfifo_enqueue(circular_queue*,void*, size_t);
/*************************
 * Function cbfifo_dequeue
 *
 * Param circular_queue* and size_t
 *
 * Return NULL
 *
 * Description Will write the data in circular buffer
 */

size_t cbfifo_dequeue(circular_queue*,void*, size_t);
/*************************
 * Function cbfifo_length
 *
 * Param NULL
 *
 * Return NULL
 *
 * Description Will provide the length of circular buffer
 */
size_t cbfifo_length();
/*************************
 * Function cbfifo_capacity
 *
 * Param NULL
 *
 * Return NULL
 *
 * Description Will capacity of circular buffer
 */
size_t cbfifo_capacity();

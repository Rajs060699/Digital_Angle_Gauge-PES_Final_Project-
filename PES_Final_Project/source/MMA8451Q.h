/********************************
 * @Author Rajesh Srirangam
 * @Title  MMA8451Q.h
 * @Description Used for DAG intialisation
 * @Reference links https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_8/I2C-Demo/src/mma8451.c
 */

/**************HEADERS****************/
#include <MKL25Z4.H>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "I2C.h"
/***************************************/

/******************MACROS**********************/
#define MMA_ADDR 								0x3A
#define REG_XHI 								0x01
#define REG_XLO 								0x02
#define REG_YHI 								0x03
#define REG_YLO 								0x04
#define REG_ZHI									0x05
#define REG_ZLO 								0x06
#define COUNTS_PER_G 							(4096.0)
#define M_PI 									(3.14159265)
#define REG_CTRL1  								0x2A
#define SET										1
/******************************************/

/****************STRUCTURE****************/
typedef struct accl_param
{
	int x;
	int y;
	int z;
	float roll_val;
	float pitch_val;
	float ref_roll_val;
	float ref_pitch_val;
}acclerometer_parameters_t;
/*******************************************/
/***********************************
 * @Function init_mma()
 * @Param NULL
 * @Return NULL
 * @Description Used for initialisation of MMA accelerator
 */
int init_mma(void);
/***********************************
 * @Function read_full_xyz()
 * @Param NULL
 * @Return NULL
 * @Description Used for reading x,y,z coordinates
 */
void read_full_xyz(acclerometer_parameters_t *acc);
/***********************************
 * @Function convert_xyz_to_roll_pitch()
 * @Param NULL
 * @Return NULL
 * @Description Used for calculating roll and pitch values
 */
void convert_xyz_to_roll_pitch(acclerometer_parameters_t *accl_param,uint8_t update_ref);

/***************************
 * Author Rajesh Srirangam
 * Title I2C.h
 * Description Used for I2C Initialisation
 * Reference links:https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_8/I2C-Demo/src/i2c.c
 */

/*****HEADERS*******/
#include <MKL25Z4.H>
/*******************/

/*********MACROS***********/
#define SDA_PIN (PORTE->PCR[24])
#define SCL_PIN (PORTE->PCR[25])
#define FREQ_DIVIDER_VAL (0x10)
#define FREQ_DIVIDER_REG (I2C0->F)
#define CONTROL_REG1 (I2C0->C1)
#define CONTROL_REG2 (I2C0->C2)
#define PCR_MUX_VAL (5u)
#define DATA_REG (I2C0->D)
#define STATUS_REG (I2C0->S)
#define LOCK_DETECT_THRESHOLD (200u)
#define CLOCK_GATING_REG4 (SIM->SCGC4)
#define CLOCK_GATING_REG5 (SIM->SCGC5)
#define I2C_M_START 	I2C0->C1 |= I2C_C1_MST_MASK
#define I2C_M_STOP  	I2C0->C1 &= ~I2C_C1_MST_MASK
#define I2C_M_RSTART 	I2C0->C1 |= I2C_C1_RSTA_MASK
#define I2C_TRAN			I2C0->C1 |= I2C_C1_TX_MASK
#define I2C_REC				I2C0->C1 &= ~I2C_C1_TX_MASK
#define BUSY_ACK 	    while(I2C0->S & 0x01)
#define TRANS_COMP		while(!(I2C0->S & 0x80))
#define I2C_WAIT 			i2c_wait();
#define NACK 	        I2C0->C1 |= I2C_C1_TXAK_MASK
#define ACK           I2C0->C1 &= ~I2C_C1_TXAK_MASK
/***************************************/

/*********************************
 * Function i2c_init()
 * Param NULL
 * Return NULL
 * Description :Used for Initialisation of I2C
 */
void i2c_init(void);
/*********************************
 * Function i2c_busy()
 * Param NULL
 * Return NULL
 * Description :Used for making I2C Line Busy
 */

void i2c_busy(void);

/*********************************
 * Function i2c_wait()
 * Param NULL
 * Return NULL
 * Description :Used for wait of I2C
 */
void i2c_wait(void);
/*********************************
 * Function i2c_start()
 * Param NULL
 * Return NULL
 * Description :Used to start data tranmsisson of I2C
 */
void i2c_start();
/*********************************
 * Function i2c_read_setup()
 * Param NULL
 * Return NULL
 * Description :Used for I2C read of device and slave address
 */

void i2c_read_setup(uint8_t , uint8_t );
/*********************************
 * Function i2c_repeated_read()
 * Param NULL
 * Return NULL
 * Description :Used for repeating I2C read line
 */
uint8_t i2c_repeated_read(uint8_t );
/*********************************
 * Function i2c_read_byte()
 * Param NULL
 * Return NULL
 * Description :Used for reading I2C data
 */
uint8_t i2c_read_byte(uint8_t , uint8_t );
/*********************************
 * Function i2c_write_byte()
 * Param NULL
 * Return NULL
 * Description :Used for writing data in I2C
 */
void i2c_write_byte(uint8_t , uint8_t , uint8_t );

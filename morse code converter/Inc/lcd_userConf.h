/**
*@file: lcd_userConf.h
*@brief: Character LCD I2C STM32 HAL driver
*@author: Veysel Gekdemir 2018
*         Markus Kohler 2020
*@note: This library is compatible with the LCD Displays that have similarities(pinouts, conf., ddram address...) 
*       with HD44780, KS0066U, etc.  The library has been tested on the lcd 16x2.
*/

/**
*@brief: LCD I2C device address
*/
uint8_t i2cDeviceAddr = 0x4E;

/**
*@brief: I2C_HandleTypeDef define
*/
extern I2C_HandleTypeDef hi2c3;
I2C_HandleTypeDef* hi2cx = &hi2c3;

/**
*@brief: LCD (character x line) number definition
*/
//Uncomment one, and only one
#define LCD_16x2
//#define LCD_16x4
//#define LCD_20x2
//#define LCD_20x4

/**
*@brief: Buffer data character number
*/
#define BFR_MAX 100

/*************************END OF FILE*****************************/

/**
*@file: lcd_i2cModule.h
*@brief: Character LCD I2C STM32 HAL driver
*@author: Veysel Gekdemir 2018
*         Markus Kohler 2020
*@note: This library is compatible with the LCD Displays that have similarities(pinouts, conf., ddram address...) 
*       with HD44780, KS0066U, etc.  The library has been tested on the lcd 16x2.
*/

#ifndef LCD_I2CMODULE_H
#define LCD_I2CMODULE_H

#ifdef __cplusplus
extern "C" {
#endif

/*Includes-------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/*---------------------------------------------------------------*/

/*Defines and variables------------------------------------------*/
//LCD instructions
#define LCD_CLEAR_DISPLAY           0x01
#define LCD_RETURN_HOME             0x02
#define LCD_ENTRYMODE_SET           0x04
#define LCD_DISPLAY_CONTROL         0x08
#define LCD_CURSORDISPLAY_SHIFT     0x10
#define LCD_FUNCTION_SET            0x20
#define LCD_SET_CGRAMADDR           0x40
#define LCD_SET_DDRAMADDR           0x80
//#define   LCD_READ_BUSYFLAG           0x100

//Entry mode set sub-options
typedef enum {
    ENTRY_INCREMENT       = 0x02,
    ENTRY_DECREMENT       = 0x00,
    ENTRY_DISPLAY_SHIFT   = 0x01,
    ENTRY_DISPLAY_NOSHIFT = 0x00
} lcd_EntryMode_set_t;

//Display control sub-options
typedef enum {
    DISPLAY_ON   = 0x04,
    DISPLAY_OFF  = 0x00,
    CURSOR_ON    = 0x02,
    CURSOR_OFF   = 0x00,
    BLINK_ON  = 0x01,
    BLINK_OFF = 0x00
} lcd_display_control_t;

//Cursor or display shift sub-options
typedef enum {
    DISPLAY_SHIFT  = 0x08,
    CURSOR_SHIFT   = 0x00,
    SHIFT_TO_RIGHT = 0x04,
    SHIFT_TO_LEFT  = 0x00
} lcd_CursorDisplay_shift_t;

//Function set sub-options
typedef enum {
    MODE_8B        = 0x10,
    MODE_4B        = 0x00,
    MODE_2L        = 0x08,
    MODE_1L        = 0x00,
    MODE_5X10_DOTS = 0x04,
    MODE_5X8_DOTS  = 0x00
} lcd_function_set_t;

//Read busy flag sub-options
// typedef enum {
//     BUSY_FLAG_ON  = 0x01,
//     BUSY_FLAG_OFF = 0x00
// } lcd_read_BusyFlag_t;

//LCD backlight, RS, RW, E definitions for i2c module
//P7............P0 is data that will be sent to lcd through i2c module(PCF8574);
//P0 : RS
//P1 : RW
//P2 : E
//P3 : BT --> backlight pin activation
//P4 : D4
//P5 : D5
//P6 : D6
//P7 : D7
#define LCD_RS     0x01
#define LCD_RW     0x02
#define LCD_E      0x04
#define LCD_BL_ON  0x08 //Backlight on
#define LCD_BL_OFF 0x00 //Backlight off

//LCD string mode
#define STR_NOSLIDE 0x00
#define STR_SLIDE 0x01

/*---------------------------------------------------------------*/

/*Private functions----------------------------------------------*/
void LCD_i2cDeviceCheck(void);
void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetCursor(int line_x, int char_x);
void LCD_BackLight(uint8_t light_state);
void LCD_Set_Command(uint8_t cmd);
void LCD_Write_Data(uint8_t datax);
void LCD_Send_String(char str[], uint8_t mode);
void LCD_Print(char const *ch, float value);

#ifdef __cplusplus
}
#endif

#endif


/*************************END OF FILE*****************************/

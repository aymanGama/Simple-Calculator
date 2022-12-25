/*
 * LCD.h
 *
 * Created: 10/29/2022 12:20:54 PM
 *  Author: Ayman
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LCD_PORT               PORTB 
#define DATADIR_LCD_PORT       DDRB
#define DATADIR_LCD_CONTROL     DDRA
#define LCD_CONTROL            PORTA
#define RS_SWITCH              0
#define RW_SWITCH              2
#define ENABLE_SWITCH          1
#define DATA_SHIFT             4


#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


                           
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

//API
void LCD_init(void);
void LCD_CHECK_ISBUSY();
void LCD_WRITE_COMMAND (unsigned char command);
void LCD_WRITE_CHAR (unsigned char data);
void LCD_WRITE_STRING (char* data);
void LCD_clear_screen();
void lcd_go_to(unsigned char x,unsigned char y);

void lcd_num(int n);




#endif /* LCD_H_ */
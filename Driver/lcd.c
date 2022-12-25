/*
 * lcd.c
 *
 * Created: 10/29/2022 12:21:18 PM
 *  Author: Ayman
 */ 

#include "lcd.h"

void LCD_kick()
{
	LCD_CONTROL |=(1<<ENABLE_SWITCH);
	_delay_ms(1);
	LCD_CONTROL &=~(1<<ENABLE_SWITCH);
	_delay_ms(0.1);
}
void LCD_gotoxy(unsigned char line ,unsigned char position)
{
	if (line ==2)
	{
		if( position < 16 && position >= 0 )
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
		
	}
	else if (line ==1)
	{
		if( position < 16 && position >= 0 )
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
		
		
	}
}



void LCD_init(void)
{
	//_delay_ms(20);
	DATADIR_LCD_CONTROL |=((1<<RS_SWITCH)|(1<<ENABLE_SWITCH)|(1<<RW_SWITCH));                     //set out control PINS AS output
	LCD_CONTROL &=~((1<<RS_SWITCH)|(1<<ENABLE_SWITCH)|(1<<RW_SWITCH));                           // out zero 
	
#ifdef EIGHT_BIT_MODE
	DATADIR_LCD_PORT=0xff ;                                                                      //out data port as output
	_delay_ms(2);

	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	DATADIR_LCD_PORT |=(0xff <<DATA_SHIFT) ;                                                                      //out data port as output
	_delay_ms(15);
	LCD_clear_screen();
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);



#endif
LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR);
LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);   
_delay_ms(2);
LCD_WRITE_COMMAND(LCD_ENTRY_MODE);

}








void LCD_CHECK_ISBUSY(void)
{
	//four bit mode 
	DATADIR_LCD_PORT &=~(0xff <<DATA_SHIFT) ;    
	///eight bit mode 
	//DATADIR_LCD_PORT =0x00 ;                                      // input mode
	LCD_CONTROL |=(1<<RW_SWITCH);                                      // read 
	LCD_CONTROL &=~(1<<RS_SWITCH);
	_delay_ms(1);
	LCD_kick();
	DATADIR_LCD_PORT=0xff ;                                            //output mode for data port
	LCD_CONTROL &=~(1<<RW_SWITCH);                                     //write
}
void LCD_WRITE_COMMAND (unsigned char command)
{
#ifdef EIGHT_BIT_MODE 
	//LCD_CHECK_ISBUSY();
	LCD_CONTROL &=~((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_PORT=command ;
	
	//_delay_ms(1);
	LCD_kick();
#endif
#ifdef FOUR_BIT_MODE
//	LCD_CHECK_ISBUSY();
	LCD_PORT=   (LCD_PORT & 0x0f) | (command & 0xf0)    ;
	LCD_CONTROL &=~((1<<RW_SWITCH)|(1<<RS_SWITCH));
	//_delay_ms(1);
	LCD_kick();
	LCD_PORT=   (LCD_PORT & 0x0f) | (command<<4)    ;
	LCD_CONTROL &=~((1<<RW_SWITCH)|(1<<RS_SWITCH));
	//_delay_ms(1);
	LCD_kick();

#endif
}
void LCD_WRITE_CHAR (unsigned char data)
{
#ifdef EIGHT_BIT_MODE 
	//LCD_CHECK_ISBUSY();
	LCD_CONTROL |= (1<<RS_SWITCH);
	LCD_PORT=data ;
	//LCD_CONTROL &=~(1<<RW_SWITCH);

	//_delay_ms(1);

	LCD_kick();
#endif
#ifdef FOUR_BIT_MODE
	//LCD_CHECK_ISBUSY();
	LCD_PORT=   (LCD_PORT & 0x0f) | (data & 0xf0)    ;
	LCD_CONTROL &=~(1<<RW_SWITCH);
	LCD_CONTROL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_kick();
	LCD_PORT=   (LCD_PORT & 0x0f) | (data<<DATA_SHIFT)    ;
	LCD_CONTROL &=~(1<<RW_SWITCH);
	LCD_CONTROL |= (1<<RS_SWITCH);
	_delay_ms(1);	
	LCD_kick();

#endif
}
void LCD_WRITE_STRING (char* data)
{
	int count = 0 ;
	while (*data > 0)
	{
		count++ ;
		LCD_WRITE_CHAR(*data++) ;
		if (count ==16)
		{
			LCD_gotoxy(2,0) ;
			
		}
		else if (count==32)
		{
			
			LCD_clear_screen();
			LCD_gotoxy(1,0);
			count=0 ;
		}
	}
}

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void lcd_go_to(unsigned char x,unsigned char y) // determine position
{
	unsigned char first[]={0x80,0xC0,0x94,0xD4};
	LCD_WRITE_COMMAND(first [x-1]+y-1);
	_delay_ms(100);
}
void lcd_num(int n)
{
	LCD_WRITE_CHAR((n/1000)+48);
	n %= 1000;

	LCD_WRITE_CHAR((n/100)+48);
	n %= 100;

	LCD_WRITE_CHAR((n/10)+48);
	n %= 10;

	LCD_WRITE_CHAR(n+48);
}
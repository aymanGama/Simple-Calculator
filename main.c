/*
 * simple calculator.c
 *
 * Created: 12/22/2022 5:33:12 PM
 * Author : Ayman
 */ 
#define F_CPU  1000000UL

#include <avr/io.h>
#include <util//delay.h>
#include <lcd.h>
#include <KEYPAD.h>
#include "utiles.h"
#include "KEYPAD.h"
#include "lcd.h"
#define  A 0x39
#define  B 0x36
#define  C 0x33
#define  D 0x30
#define  output 1
#define input 0
int main(void)
{
	
		 uint8_t  count=0;
		// Replace with your application code 
		Port_Direction(B,output);                          	           //DDRB=0xff
		for(count=0;count<2;count++)             		           //DDRA|=(1<<0)|(1<<1)
		{
			Pin_Direction(A,count,output);
		}
		
		for(count=0;count<4;count++)          	                        //DDRD=0x0F
		{
			Pin_Direction(D,count,output);
		}
		for(count=0;count<4;count++)  		                       //PORTD|=(1<<0)|(1<<1)|(1<<2)|(1<<3)

		{
			Port_Write(D,count);
		}
	//KEYBAD_INIT();
	LCD_init();
	uint8_t   i=0 ,j=0;
	uint8_t  arr1[100] , arr2[100];
	uint8_t  result=0;
	uint8_t  var1,var2;
	LCD_WRITE_STRING("enter the nums");
	while (1)
	{
		if(KEYPAD_GET_CHAR()!='C')           // nums in keypad except(C-clear and Anything else)
		{
			LCD_WRITE_COMMAND(0xC);                     //display on , cursor off
			lcd_go_to(2,1+i);
			LCD_WRITE_CHAR(KEYPAD_GET_CHAR());
			arr1[i]=(KEYPAD_GET_CHAR());                   //store all Clicks in arr1
			if(i==1 )                            //store the first 2 digits in the var1
			{
				var1=(arr1[i-1]*10)+arr1[i]; //to make Every two numbers , one number Consists of 2 digit
			}
			if(i==4)                            //store the seconder 2 digits in the var2
			{
				var2=(arr1[i-1]*10)+arr1[i];
			}
			
			if(KEYPAD_GET_CHAR()=='=' && arr1[i-3]=='+')   //summation   operation
			{
				result=var1+var2;
				if(result<10)
				{
					LCD_WRITE_CHAR(result-48+16+48);
				}
				else
				{
					lcd_num(result-48+16);
				}
			}
			if(KEYPAD_GET_CHAR()=='=' && arr1[i-3]=='-')//subtraction operation
			{
				result=var1-var2;
				if(result<10)
				{
					LCD_WRITE_CHAR(result+48);
				}
				else
				{
					lcd_num(result);
				}
			}
			
			if(KEYPAD_GET_CHAR()=='=' && arr1[i-3]=='*')    //multiplication  operation
			{
				var1=var1-16;
				var2=var2-16;
				result=var1 * var2;
				if(result<10)
				{
					LCD_WRITE_CHAR(result+48);
				}
				else
				{
					lcd_num(result);
				}
			}
			if(KEYPAD_GET_CHAR()=='=' && arr1[i-3]=='/') // Division operation
			{
				
				var1=var1-16;
				var2=var2-16;
			
				
				if(var2==0)
				{
					lcd_go_to(3,-3);
					LCD_WRITE_STRING("it is not valid ");
				}
				else
				{
				
					result=(var1) / var2;
					if(result<10)
					{
						LCD_WRITE_CHAR(result+48);
					}
					else
					{
						lcd_num(result);
					}
				}
			}
			
			i++;
			_delay_ms(600);
		}
		else                             
		{
			i=0;                          // to return the first index in arr1
			result=0;                     // to clear this var
			LCD_WRITE_COMMAND(0x1);             // to clear LCD
			lcd_go_to(1,1);
			LCD_WRITE_STRING("enter the nums");
			_delay_ms(100);
			
		}
	}
	
	return 0  ;
}





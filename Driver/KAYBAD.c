/*
 * KAYBAD.c
 *
 * Created: 11/6/2022 5:13:58 AM
 *  Author: Ayman 
 */ 
#include "KEYPAD.h"

char KEKEYBAD_R[] = {R0 , R1 , R2 , R3};
char KEKEYBAD_C[] = {C0 , C1 , C2 , C3};
void KEYBAD_INIT()
{
	DATADIR_KEYPAD &= ~((1<<R0) |(1<<R1) | (1<<R2) | (1<<R3));
	DATADIR_KEYPAD |= ((1<<C0) |(1<<C1) | (1<<C2) | (1<<C3));
	KEYPAD_PORT =0xff ;
	
}

	char KEYPAD_GET_CHAR(void)
	{
		//addition
		while(1)
		{
			
		PORTD=0x01 ;                                           //PORTD |=(1<<PIND0) , PORTD&=~(1<<PIND1), PORTD&=~(1<<PIND1), PORTD&=~(1<<PIND1);
		_delay_ms(1);
		if((PIND & 0b00010000 )) return '7';
		if((PIND & 0b00100000 ))  return '8';
		if((PIND & 0b01000000 )) return '9';
		if((PIND & 0b10000000 ))  return '/';
		
		PORTD=0x02 ;                                        //PORTD &=~(1<<PIND0) , PORTD|=(1<<PIND1), PORTD&=~(1<<PIND1), PORTD&=~(1<<PIND1);
		//_delay_ms(1);
		if((PIND & 0b00010000 )) return '4';
		if((PIND & 0b00100000)) return '5';
		if((PIND & 0b01000000 )) return '6';
		if((PIND & 0b10000000 )) return '*';
		
		PORTD=0x04 ;                                      //PORTD |=(1<<PIND0) , PORTD&=~(1<<PIND1), PORTD|=(1<<PIND1), PORTD&=~(1<<PIND1);
		//_delay_ms(1);
		if((PIND & 0b00010000 )) return '1';
		if((PIND & 0b00100000 )) return '2';
		if((PIND & 0b01000000 )) return '3';
		if((PIND & 0b10000000 )) return '-';
		
		PORTD=0x08 ;                                    //PORTD &=~(1<<PIND0) , PORTD&=~(1<<PIND1), PORTD&=~(1<<PIND1), PORTD|=(1<<PIND1);
		//_delay_ms(1);
		if((PIND & 0b00010000 )) return 'C';
		if((PIND & 0b00100000 )) return '0';
		if((PIND & 0b01000000 )) return '=';
		if((PIND & 0b10000000 )) return '+';
		}
		return 'N';
	}



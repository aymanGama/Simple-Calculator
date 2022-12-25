/*
 * KEYPAD.h
 *
 * Created: 11/6/2022 5:13:17 AM
 *  Author: Ayman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#define KEYPAD_PORT     PORTD
#define DATADIR_KEYPAD  DDRD
#define KEYPAD_PIN      PIND
#define R0  0
#define R1  1
#define R2  2
#define R3  3
#define C0  4
#define C1  5
#define C2  6
#define C3  7
void KEYBAD_INIT();
char KEYPAD_GET_CHAR();




#endif /* KEYPAD_H_ */
/*
 * LCDControl.h
 *
 * Created: 7/4/2020 1:41:59 PM
 *  Author: MohamedRaafat
 */ 


#ifndef LCDCONTROL_H_
#define LCDCONTROL_H_

#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 8000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms

#define	LCD_COMMAND_DIR		DDRD	//Define LCD Commend Port Direction.
#define LCD_DATA_DIR		DDRB	//Define LCD Data Port Direction.
#define LCD_COMMAND_PORT	PORTD	//Define LCD Commend Port. 
#define LCD_DATA_PORT		PORTB	//Define LCD Data Port.

#define RS	2	//Define Registry Select(Data/Commend Registry). 
#define RW	5	//Define Read/Write Signal Pin.
#define EN	7	//Define Enable Signal Pin.


void LCD_Initialize(void);						//Function to Initialize LCD.
void SendCommend(unsigned char Command);		//Function to send commend to LCD.
void SendCharacter(unsigned char Character);	//Function to send Character to display.
void SendString(char *String);					//Function to send string to display.
void StringPostion(unsigned char X , unsigned char Y , char *Str);

#endif /* LCDCONTROL_H_ */
/*
 * KeyPad.h
 *
 * Created: 7/24/2020 4:23:16 PM
 *  Author: MohamedRaafat
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 8000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms

#define KeyDDR DDRA
#define KeyPRT PORTA
#define KeyPIN PINA

char KeyPadScan(void);

#endif /* KEYPAD_H_ */


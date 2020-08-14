/*
 * KeyPad.c
 *
 * Created: 7/24/2020 4:22:59 PM
 *  Author: MohamedRaafat
 */ 
#include "KeyPad.h"
#include "LCD.h"


char KeyPadScan(void)
{
	//PORTA -->  PINA0=1 ; PINA1=0 ; PINA2=0 ; PINA3=0;
	KeyPRT = 0xF1;
	_delay_ms(1);
	if((KeyPIN & 0b00010000))
	{
		return '1'; 
	}
	if((KeyPIN & 0b00100000))
	{
		return '2';
	}
	if((KeyPIN & 0b01000000))
	{
		return '3';
	}
	if((KeyPIN & 0b10000000))
	{
		return 'A';
	}
	
	//PORTA -->  PINA0=0 ; PINA1=1 ; PINA2=0 ; PINA3=0;
	KeyPRT = 0xF2;
	_delay_ms(1);
	if((KeyPIN & 0b00010000))	{return '4';}
	if((KeyPIN & 0b00100000))	{return '5';}
	if((KeyPIN & 0b01000000))	{return '6';}
	if((KeyPIN & 0b10000000))	{return 'B';}
	
	//PORTA -->  PINA0=0 ; PINA1=0 ; PINA2=1 ; PINA3=0;
	KeyPRT = 0xF4;
	_delay_ms(1);
	if((KeyPIN & 0b00010000))	{return '7';}
	if((KeyPIN & 0b00100000))	{return '8';}
	if((KeyPIN & 0b01000000))	{return '9';}
	if((KeyPIN & 0b10000000))	
	{
		LCD_Clear();
		
	}
	
	//PORTA -->  PINA0=0 ; PINA1=0 ; PINA2=0 ; PINA3=1;
	KeyPRT = 0xF8;
	_delay_ms(1);
	if((KeyPIN & 0b00010000))	{return '*';} 
	if((KeyPIN & 0b00100000))	{return '0';}
	if((KeyPIN & 0b01000000))	{return '#';}
	if((KeyPIN & 0b10000000))
	{
		
		return 'D';
	}
	
	return 'N';
}


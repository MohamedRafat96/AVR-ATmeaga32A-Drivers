/*
 * DIO.c
 *
 * Created: 8/9/2020 11:59:51 PM
 *  Author: MohamedRaafat
 */ 
#include "DIO_REG.h"
#include "DIO_TYPES.h"
#include "DIO.h"

void DIO_SetPRT_Dir(DIO_PORT PORT_ID , DIO_DIRECTION DIRECTION)
{
	if (Output == DIRECTION)
	{
		switch(PORT_ID)
		{
			case A: DDRA_REG = 0xFF; break;
			case B: DDRB_REG = 0xFF; break;
			case C: DDRC_REG = 0xFF; break;
			case D: DDRD_REG = 0xFF; break;
		}
	}
	else if (Input == DIRECTION)
	{
		switch(PORT_ID)
		{
			case A: DDRA_REG = 0x00; break;
			case B: DDRB_REG = 0x00; break;
			case C: DDRC_REG = 0x00; break;
			case D: DDRD_REG = 0x00; break;
		}
	}
}
void DIO_SetPRT_Value(DIO_PORT PORT_ID , unsigned char Value)
{
	switch(PORT_ID)
	{
		case A: PORTA_REG = Value; break;
		case B: PORTB_REG = Value; break;
		case C: PORTC_REG = Value; break;
		case D: PORTD_REG = Value; break;
	}
}
void DIO_SetPIN_Dir(DIO_PORT PORT_ID , DIO_PIN PIN_ID , DIO_DIRECTION DIRECTION)
{
	if (PORT_ID <= D && PIN_ID <= PIN7)
	{
		if (Output == DIRECTION)
		{
			switch(PORT_ID)
			{
				case  A: DDRA_REG |= (1<<PIN_ID); break;
				case  B: DDRB_REG |= (1<<PIN_ID); break;
				case  C: DDRC_REG |= (1<<PIN_ID); break;
				case  D: DDRD_REG |= (1<<PIN_ID); break;
			}
		}
		else if (Input == DIRECTION)
		{
			switch(PORT_ID)
			{
				case  A: DDRA_REG &= ~(1<<PIN_ID); break;
				case  B: DDRB_REG &= ~(1<<PIN_ID); break;
				case  C: DDRC_REG &= ~(1<<PIN_ID); break;
				case  D: DDRD_REG &= ~(1<<PIN_ID); break;
			}
		}
	}
}
void DIO_SetPIN_Value(DIO_PORT PORT_ID , DIO_PIN PIN_ID , DIO_Value Value)
{
	if (PORT_ID <= D && PIN_ID <= PIN7)
	{
		if (High == Value)
		{
			switch(PORT_ID)
			{
				case A : PORTA_REG |= (1<<PIN_ID); break;
				case B : PORTB_REG |= (1<<PIN_ID); break;
				case C : PORTC_REG |= (1<<PIN_ID); break;
				case D : PORTD_REG |= (1<<PIN_ID); break;
			}
		}
		else if (Low == Value)
		{
			switch(PORT_ID)
			{
				case A : PORTA_REG &= ~(1<<PIN_ID); break;
				case B : PORTB_REG &= ~(1<<PIN_ID); break;
				case C : PORTC_REG &= ~(1<<PIN_ID); break;
				case D : PORTD_REG &= ~(1<<PIN_ID); break;
			}
		}
	}
}

DIO_Value DIO_GetPIN_Value(DIO_PORT PORT_ID , DIO_PIN PIN_ID)
{
	
 DIO_Value PinValue=Low;
	if (PORT_ID <= D && PIN_ID <= PIN7)
	{
		switch(PORT_ID)
		{
			case A : PinValue = ((PINA_REG >> PIN_ID) & 0x01); break;
			case B : PinValue = ((PINB_REG >> PIN_ID) & 0x01); break;
			case C : PinValue = ((PINC_REG >> PIN_ID) & 0x01); break;
			case D : PinValue = ((PIND_REG >> PIN_ID) & 0x01); break;
		}
	}

	return PinValue;
}
/*
 * GPIO.c
 *
 * Created: 8/9/2020 10:45:56 PM
 * Author : MohamedRaafat
 */ 
#define F_CPU 8000000UL 
#include "DIO_TYPES.h"
#include "DIO.h"
#include <avr/io.h>
#include <util/delay.h>


void Room1(void)
{
	DIO_SetPIN_Dir(C, PIN0 , Output);
	DIO_SetPIN_Dir(D , PIN4 , Input);

	while(1)
	{
	
		if (DIO_GetPIN_Value(D ,PIN4) == High)
		{
			DIO_SetPIN_Value(C , PIN0 , High);
		}
		else if(DIO_GetPIN_Value(D ,PIN4) == Low)
		{
			DIO_SetPIN_Value(C , PIN0 , Low);
		}
	
	}
}
int main(void)
{
	
	Room1();
    while (1) 
    {
			
    }
}


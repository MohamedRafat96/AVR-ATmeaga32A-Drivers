/*
 * LCD.c
 *
 * Created: 7/4/2020 1:49:43 PM
 *  Author: MohamedRaafat
 */ 
#include "LCDControl.h"

/********** [1] Initialize LCD **********//*
	- Make Command PORT O/P
	- Make Data	   PORT O/P
	- Make Enable PIN  = 0
	- Wait For initialize delay > 15 Us
	- Send some Command:
	  * 0x38	init 2 line , 5x7 matrix
	  * 0x0E	Display on , Cursor on 
	  * 0x01	Clear LCD
	- Wait For initialize delay > 15 Us
	- Send Command:
	  * 0x06	Shift Cursor Right
*/
void LCD_Initialize()
{
	LCD_COMMAND_DIR =0xA4;			//Make Command PORT O/P
	LCD_DATA_DIR =0xFF;				//Make Data	   PORT O/P
	LCD_COMMAND_PORT &= ~(1<<EN);	//Make Enable PIN  = 0
	_delay_us(20);					//Wait For initialize delay > 15 Us
	SendCommend(0x38);				//0x38	init 2 line , 5x7 matrix
	SendCommend(0x0E);				//0x0E	Display on , Cursor on
	SendCommend(0x01);				//0x01	Clear LCD
	_delay_us(20);					//Wait For initialize delay > 15 Us
	SendCommend(0x06);				//0x06	Shift Cursor Right
}	

/********** [2] Send Command To LCD **********//*
	- Send Command To Data Port 
	- Register Select Pin (RS) = 0 For Command
	- Read/Write Pin (RW) = 0 For Write
	- Enable Pin (EN) = 1 For High-Low pulse
	- Wait To Make Enable Wide / Delay 1 US
	- Enable Pin (EN) = 0 For High-Low pulse
	- Wait To Make Enable Wide / Delay 3 ms
*/
void SendCommend(unsigned char Command)
{
	LCD_DATA_PORT = Command;		//Send Command To Data Port
	LCD_COMMAND_PORT &= ~(1<<RS);	//Register Select Pin (RS) = 0 For Command
	LCD_COMMAND_PORT &= ~(1<<RW);	//Read/Write Pin (RW) = 0 For Write
	LCD_COMMAND_PORT |= (1<<EN);	//Enable Pin (EN) = 1 For High-Low pulse
	_delay_us(1);					//Wait To Make Enable Wide / Delay 1 US
	LCD_COMMAND_PORT &= ~(1<<EN);	//Enable Pin (EN) = 0 For High-Low pulse
	_delay_ms(3);					//Wait To Make Enable Wide / Delay 3 ms
}
	
/********** [3] Send Data character To LCD **********//*
	- Send Character To Data PORT
	- Register Select Pin (RS) = 1 For Data
	- Read/Write Pin (RW) = 0 For Write
	- Enable Pin (EN) = 1 For High-Low pulse
	- Wait To Make Enable Wide / Delay 1 US
	- Enable Pin (EN) = 0 For High-Low pulse
	- Wait To Make Enable Wide / Delay 1 ms
*/
void SendCharacter(unsigned char Character)
{
	LCD_DATA_PORT = Character;		//Send Character To Data PORT
	LCD_COMMAND_PORT |= (1<<RS);	//Register Select Pin (RS) = 1 For Data
	LCD_COMMAND_PORT &= ~(1<<RW);	//Read/Write Pin (RW) = 0 For Write
	LCD_COMMAND_PORT |= (1<<EN);	//Enable Pin (EN) = 1 For High-Low pulse
	_delay_us(1);					//Wait To Make Enable Wide / Delay 1 US
	LCD_COMMAND_PORT &= ~(1<<EN);	//Enable Pin (EN) = 0 For High-Low pulse
	_delay_ms(3);					//Wait To Make Enable Wide / Delay 3 ms
}
	
/********** [4] Send Data String To LCD **********/
void SendString(char *String)
{
	unsigned char X = 0;
	while(String[X] !=0)
	{
		SendCharacter(String[X]);
		X++;
	}
}

/********** [5] Select Postion Of String in LCD **********/
void StringPostion(unsigned char X , unsigned char Y , char *Str)
{
	//unsigned char CharAddr[] = {0xB0, 0xC0, 0x94, 0xD4};
	//SendCommend(CharAddr[Y-1]+ X-1);
	//_delay_us(100);
	
	if (X == 0 && Y<16)
	SendCommend((Y & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (X == 1 && Y<16)
	SendCommend((Y & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	SendString(Str);
}

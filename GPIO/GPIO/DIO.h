/*
 * DIO.h
 *
 * Created: 8/9/2020 11:04:19 PM
 *  Author: MohamedRaafat
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_SetPRT_Dir(DIO_PORT PORT_ID , DIO_DIRECTION DIRECTION);
void DIO_SetPRT_Value(DIO_PORT PORT_ID , unsigned char Value);
void DIO_SetPIN_Dir(DIO_PORT PORT_ID , DIO_PIN PIN_ID , DIO_DIRECTION DIRECTION);
void DIO_SetPIN_Value(DIO_PORT PORT_ID , DIO_PIN PIN_ID , DIO_Value Value);
DIO_Value DIO_GetPIN_Value(DIO_PORT PORT_ID , DIO_PIN PIN_ID);

#endif /* DIO_H_ */
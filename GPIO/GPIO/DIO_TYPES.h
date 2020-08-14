/*
 * DIO_TYPES.h
 *
 * Created: 8/9/2020 11:19:14 PM
 *  Author: MohamedRaafat
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum
{
	Input,
	Output
}DIO_DIRECTION;

typedef enum
{
	A,
	B,
	C,
	D
}DIO_PORT;

typedef enum
{
	Low,
	High
}DIO_Value;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PIN;
#endif /* DIO_TYPES_H_ */
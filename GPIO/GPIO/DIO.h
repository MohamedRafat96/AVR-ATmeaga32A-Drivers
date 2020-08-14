/*
 * DIO.h
 *
 * Created: 8/9/2020 11:04:19 PM
 *  Author: MohamedRaafat
 */ 


#ifndef DIO_H_
#define DIO_H_

/*************************************************************************/
/*************************************************************************/
#define SetBit(PORT_ID , PIN_ID)		(PORT_ID) |= (1<<(PIN_ID))
#define ClearBit(PORT_ID , PIN_ID)		(PORT_ID) &= ~(1<<(PIN_ID))
#define ToggleBit(PORT_ID , PIN_ID)		(PORT_ID) ^= (1<<(PIN_ID))
#define GetBit(PORT_ID , PIN_ID)		( ((PORT_ID) >> (PIN_ID)) & 0x01 )
/*************************************************************************/


/*************************************************************************/
/*************************************************************************/
#define PORTA_REG	*((volatile unsigned char*) 0x3B)
#define DDRA_REG	*((volatile unsigned char*) 0x3A)
#define PINA_REG	*((volatile unsigned char*) 0x39)

#define PORTB_REG	*((volatile unsigned char*) 0x38)
#define DDRB_REG	*((volatile unsigned char*) 0x37)
#define PINB_REG	*((volatile unsigned char*) 0x36)

#define PORTC_REG	*((volatile unsigned char*) 0x35)
#define DDRC_REG	*((volatile unsigned char*) 0x34)
#define PINC_REG	*((volatile unsigned char*) 0x33)

#define PORTD_REG	*((volatile unsigned char*) 0x32)
#define DDRD_REG	*((volatile unsigned char*) 0x31)
#define PIND_REG	*((volatile unsigned char*) 0x30)
/*************************************************************************/


/*************************************************************************/
/*************************************************************************/
typedef enum{Input, Output} DIO_DIRECTION;
typedef enum{A, B, C, D} DIO_PORT;
typedef enum{Low, High} DIO_Value;
typedef enum{PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7} DIO_PIN;
/*************************************************************************/

/*************************************************************************/
/*************************************************************************/
void DIO_SetPRT_Dir(DIO_PORT PORT_ID , DIO_DIRECTION DIRECTION);
void DIO_SetPRT_Value(DIO_PORT PORT_ID , unsigned char Value);
void DIO_SetPIN_Dir(DIO_PORT PORT_ID , DIO_PIN PIN_ID , DIO_DIRECTION DIRECTION);
void DIO_SetPIN_Value(DIO_PORT PORT_ID , DIO_PIN PIN_ID , DIO_Value Value);
DIO_Value DIO_GetPIN_Value(DIO_PORT PORT_ID , DIO_PIN PIN_ID);
/*************************************************************************/

#endif /* DIO_H_ */
/*
 * DIO.c
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */


#include "DIO.h"

//set pin direction
void DIO_SetPin_Direction(Uint8t port, Uint8t pin, Uint8t direction)
{
	switch (direction)
	{
		case DIO_PIN_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, pin);
			break;
		}
		break;
		case DIO_PIN_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}
}

//set pin high/low
void DIO_SetPin_Value(Uint8t port, Uint8t pin, Uint8t status)
{
	switch (status)
	{
		case DIO_PIN_LOW:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, pin);
			break;
		}
		break;
		case DIO_PIN_HIGH:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, pin);
			break;
		}
		break;
	}
}
//toggle pin high/low
void DIO_TogglPin(Uint8t port, Uint8t pin)
{
	switch (port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		TGL_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		TGL_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		TGL_BIT(PORTD, pin);
		break;
	}
}

//read pin - return 0/1
Uint8t DIO_ReadPin_Value(Uint8t port, Uint8t pin)
{
	Uint8t val = 0;
	switch (port)
	{
		case DIO_PORTA:
		val = GET_BIT(PINA, pin);
		break;
		case DIO_PORTB:
		val = GET_BIT(PINB, pin);
		break;
		case DIO_PORTC:
		val = GET_BIT(PINC, pin);
		break;
		case DIO_PORTD:
		val = GET_BIT(PIND, pin);
		break;
	}
	return val;
}

//set direction for whole port
void DIO_SetPort_Direction(Uint8t port, Uint8t direction)
{
	switch(direction)
	{
		case DIO_PORT_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			DDRA = DIO_PORT_INPUT;
			break;
			case DIO_PORTB:
			DDRB = DIO_PORT_INPUT;
			break;
			case DIO_PORTC:
			DDRC = DIO_PORT_INPUT;
			break;
			case DIO_PORTD:
			DDRD = DIO_PORT_INPUT;
			break;
		}
		break;
		case DIO_PORT_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			DDRA = DIO_PORT_OUTPUT;
			break;
			case DIO_PORTB:
			DDRB = DIO_PORT_OUTPUT;
			break;
			case DIO_PORTC:
			DDRC = DIO_PORT_OUTPUT;
			break;
			case DIO_PORTD:
			DDRD = DIO_PORT_OUTPUT;
			break;
		}
		break;
	}
}

//set value for whole port
void DIO_SetPort_Value(Uint8t port, Uint8t status)
{
	switch(status)
	{
		case DIO_PORT_LOW:
		switch(port)
		{
			case DIO_PORTA:
			PORTA = DIO_PORT_INPUT;
			break;
			case DIO_PORTB:
			PORTB = DIO_PORT_INPUT;
			break;
			case DIO_PORTC:
			PORTC = DIO_PORT_INPUT;
			break;
			case DIO_PORTD:
			PORTD = DIO_PORT_INPUT;
			break;
		}
		break;
		case DIO_PORT_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			PORTA = DIO_PORT_OUTPUT;
			break;
			case DIO_PORTB:
			PORTB = DIO_PORT_OUTPUT;
			break;
			case DIO_PORTC:
			PORTC = DIO_PORT_OUTPUT;
			break;
			case DIO_PORTD:
			PORTD = DIO_PORT_OUTPUT;
			break;
		}
		break;
	}
}

//toggle whole port
void DIO_TogglPort(Uint8t port)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA ^= DIO_PORT_HIGH;
		break;
		case DIO_PORTB:
		PORTB ^= DIO_PORT_HIGH;
		break;
		case DIO_PORTC:
		PORTC ^= DIO_PORT_HIGH;
		break;
		case DIO_PORTD:
		PORTD ^= DIO_PORT_HIGH;
		break;
	}
}

//read whole port - return 0x00 ~ 0xFF
Uint8t DIO_ReadPort_Value(Uint8t port)
{
	Uint8t val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = PINA;
		break;
		case DIO_PORTB:
		val = PINB;
		break;
		case DIO_PORTC:
		val = PINC;
		break;
		case DIO_PORTD:
		val = PIND;
		break;
	}
	return val;
}

//Activate internal Pull up resistor
void DIO_SetPullUp(Uint8t port, Uint8t pin)
{
	switch(port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, pin);
		break;
	}
}

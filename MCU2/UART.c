/*
 * UART.c
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */



#include "UART.h"


void UART_Init(void)
{
	Uint16t UBRR_Val = 0;//Baud rate value variable

	UCSRB = (1 << RXEN) | (1 << TXEN);//Enable Transmitter and Receiver bits
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);//Full configuration for UART
	UBRR_Val = (((FRQ) / (16 * BAUDRATE)) - 1);//Baud Rate Calculations

	//set baud rate
	UBRRL = UBRR_Val;
	UBRRH = UBRR_Val >> 8;
}

void UART_Transmit(Uint8t data)
{
	UDR = data;
	while(GET_BIT(UCSRA, TXC) != 1);//waiting transmit complete
}

Uint8t UART_Receive(void)
{
	while(GET_BIT(UCSRA, RXC) != 1);//waiting receive complete
	return UDR;
}

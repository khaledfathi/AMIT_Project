/*
 * SPI.c
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */


#include "SPI.h"


void SPI_Init(void)
{
	if(SPI_MODE == MASTER){
		SET_BIT(SPI_PORT, MOSI);
		CLR_BIT(SPI_PORT, MISO);
		SET_BIT(SPI_PORT, CLK);
		SET_BIT(SPI_PORT, SS);
		SPCR = 0x53;// SPI Control Register | set [SPE,MSTR,SPR1,SPR0]
	}else if ( SPI_MODE == SLAVE){
		CLR_BIT(SPI_PORT, MOSI);
		SET_BIT(SPI_PORT, MISO);
		CLR_BIT(SPI_PORT, CLK);
		CLR_BIT(SPI_PORT, SS);
		SPCR = 0x43;// SPI Control Register | set [SPE,SPR1,SPR0]
	}
}

void SPI_Transmit(Uint8t data)
{
	SPDR = data;
	while (GET_BIT(SPSR, SPIF) != 1);
}

Uint8t SPI_Receive(void)
{
	while (GET_BIT(SPSR, SPIF) != 1);
	return SPDR;
}


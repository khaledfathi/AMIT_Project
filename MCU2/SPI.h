/*
 * SPI.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */

#ifndef SPI_H_
#define SPI_H_

#include "SPI_CONFIG.h"

void SPI_Init(void);
void SPI_Transmit(Uint8t data);
Uint8t SPI_Receive(void);
void SPI_SlaveSelect(Uint8t slave);


#endif /* SPI_H_ */

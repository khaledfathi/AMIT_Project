/*
 * SPI_CONFIG.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "CPU_CONFIG.h"


#define MASTER 1
#define SLAVE  0

#define MOSI 5
#define MISO 6
#define CLK  7
#define SS   4

#define SPI_PORT DDRB

#define SPI_MODE MASTER


#endif /* SPI_CONFIG_H_ */

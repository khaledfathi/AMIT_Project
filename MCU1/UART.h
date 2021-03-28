/*
 * UART.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */

#ifndef UART_H_
#define UART_H_


#include "UART_CONFIG.h"

void UART_Init(void);
void UART_Transmit(Uint8t data);
Uint8t UART_Receive(void);


#endif /* UART_H_ */

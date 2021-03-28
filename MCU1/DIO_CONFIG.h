/*
 * DIO_CONFIG.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 *
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "CPU_CONFIG.h"

//Renaming port names
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//Renaming pin names
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//Renaming pin status
#define DIO_PIN_INPUT   0
#define DIO_PIN_OUTPUT  1
#define DIO_PIN_LOW     0
#define DIO_PIN_HIGH    1

//Renaming port status
#define DIO_PORT_INPUT  0x00
#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_LOW    0x00
#define DIO_PORT_HIGH   0xFF


#endif /* DIO_CONFIG_H_ */

/*
 * DIO.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */

#ifndef DIO_H_
#define DIO_H_

#include "DIO_CONFIG.h"


void DIO_SetPin_Direction(Uint8t port, Uint8t pin, Uint8t direction);
void DIO_SetPin_Value(Uint8t port, Uint8t pin, Uint8t status);
void DIO_TogglPin(Uint8t port, Uint8t pin);
Uint8t DIO_ReadPin_Value(Uint8t port, Uint8t pin);

void DIO_SetPullUp(Uint8t port, Uint8t pin);

void DIO_SetPort_Direction(Uint8t port, Uint8t direction);
void DIO_SetPort_Value(Uint8t port, Uint8t status);
void DIO_TogglPort(Uint8t port);
Uint8t DIO_ReadPort_Value(Uint8t port);




#endif /* DIO_H_ */

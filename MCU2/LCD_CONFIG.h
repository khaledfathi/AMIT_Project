/*
 * LCD_CONFIG.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 *      Configure LCD for 4 bit mode
 */


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "CPU_CONFIG.h"

#define LCD_PORT 	DIO_PORTA

//LCD_RW     	   	   Ground [Only Write on LCD]
#define LCD_RS         DIO_PIN2
#define LCD_EN         DIO_PIN3

//LCD_DATA0      	   Not Used in 4bit mode
//LCD_DATA1       	   Not Used in 4bit mode
//LCD_DATA2       	   Not Used in 4bit mode
//LCD_DATA3       	   Not Used in 4bit mode
#define LCD_DATA4       DIO_PIN4
#define LCD_DATA5       DIO_PIN5
#define LCD_DATA6       DIO_PIN6
#define LCD_DATA7       DIO_PIN7

#define LCD_LOW        DIO_PIN_LOW
#define LCD_HIGH       DIO_PIN_HIGH
#define LCD_OUTPUT     DIO_PIN_OUTPUT

#endif /* LCD_CONFIG_H_ */

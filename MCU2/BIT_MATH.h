/*
 * BIT_MATH.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT)	 REG |= (1<<BIT)
#define CLR_BIT(REG,BIT)	 REG &=~ (1<<BIT)
#define GET_BIT(REG,BIT)	 ((REG>>BIT)&1)
#define TGL_BIT(REG,BIT)     REG ^= (1<<BIT)

#define GET_LOW_Nibble(REG)  REG & 0x0F
#define GET_HIGH_Nibble(REG) (REG>>4) & 0x0F

#define GET_PORT(REG) REG & 0xFF
#define TGL_PORT(REG) REG ^= 0xFF

#endif /* BIT_MATH_H_ */

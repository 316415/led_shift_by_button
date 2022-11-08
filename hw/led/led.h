/*
 * led.h
 *
 * Created: 2022-11-08 오후 3:51:33
 *  Author: kccistc
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define LED_DDR  DDRA
#define LED_PORT PORTA

void Led_Init();
void Led_RightShift();
void Led_LeftShift();

#endif /* LED_H_ */
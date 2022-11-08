/*
 * Button.h
 *
 * Created: 2022-11-08 오후 2:49:59
 *  Author: kccistc
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BUTTON_MODE 4
#define BUTTON_UP   5

#define RELEASED 1
#define PUSHED   0
enum {PUSH_ACT=10, RELEASED_ACT};

typedef struct _button
{
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	uint8_t pinNum;
	uint8_t prevState;
}Button_typedef;

void Button_Init(Button_typedef *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
int Button_GetState(Button_typedef *button);

#endif /* BUTTON_H_ */
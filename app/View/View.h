/*
 * View.h
 *
 * Created: 2022-11-08 오후 3:30:01
 *  Author: kccistc
 */ 


#ifndef VIEW_H_
#define VIEW_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../hw/led/led.h"
#include "../Tick/Tick.h"

enum{IDLE, LEFT_SHIFT, RIGHT_SHIFT};

void View_SetState(int state);
void View();
void View_LeftShift();
void View_RightShift();

#endif /* VIEW_H_ */
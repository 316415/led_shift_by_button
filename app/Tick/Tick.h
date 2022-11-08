/*
 * Tick.h
 *
 * Created: 2022-11-08 오후 4:44:00
 *  Author: kccistc
 */ 


#ifndef TICK_H_
#define TICK_H_

#include <avr/io.h>

void Tick_Init();
void incTick();
uint32_t getTick();

#endif /* TICK_H_ */
/*
 * Tick.c
 *
 * Created: 2022-11-08 오후 4:44:08
 *  Author: kccistc
 */ 

#include "Tick.h"

static uint32_t tickCounter = 0;

void Tick_Init()
{
	TCCR0 |= (1<<WGM01); //CTC mode
	TCCR0 |= (1<<CS02); //64분주비
	OCR0 = 250 - 1; //1ms 간격으로 interrupt 발생
	TIMSK |= (1<<OCIE0); //interrupt enable OCR0와 TCNT 같아지면 interrupt 발생
}
void incTick()
{
	tickCounter++;
}

uint32_t getTick()
{
	return tickCounter;
}
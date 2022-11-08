/*
 * View.c
 *
 * Created: 2022-11-08 오후 3:30:08
 *  Author: kccistc
 */ 

#include "View.h"
int viewState = IDLE;

void View_SetState(int state)
{
	viewState = state;
}

void View()
{
	switch(viewState)
	{
		case IDLE:
		break;
		case LEFT_SHIFT:
		View_LeftShift();
		break;
		
		case RIGHT_SHIFT:
		View_RightShift();
		break;
	}
}

void View_LeftShift()
{
	static uint32_t prevTime = 0;
	if(getTick() - prevTime < 200) return;
	
	prevTime = getTick();
	Led_LeftShift();
}

void View_RightShift()
{
	static uint32_t prevTime = 0;
	if(getTick() - prevTime < 200) return;
	
	prevTime = getTick();
	Led_RightShift();
}
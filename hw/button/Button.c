/*
 * Button.c
 *
 * Created: 2022-11-08 오후 2:49:45
 *  Author: kccistc
 */ 
/*동일 함수 늘리기 싫어서 각 함수의 변수만을 따옴. 아래 struct _button으로 이어짐
int prevState = RELEASED;
int Button_GetState()
{
	int curState = PINE & (1<<BUTTON_MODE);
	if((curState == PUSHED) && (prevState == RELEASED))
	{
		prevState = PUSHED;
		_delay_ms(10); //chattering
		return PUSH_ACT;
	}
	else if((curState!=PUSHED) && (prevState == PUSHED))
	{
		prevState = RELEASED;
		_delay_ms(10);
		return RELEASED_ACT;
	}
	return PUSH_ACT;
}

int Button_GetState2()
{
	int curState = PINE & (1<<BUTTON_UP);
	if((curState == PUSHED) && (prevState == RELEASED))
	{
		prevState = PUSHED;
		_delay_ms(10); //chattering
		return PUSH_ACT;
	}
	else if((curState!=PUSHED) && (prevState == PUSHED))
	{
		prevState = RELEASED;
		_delay_ms(10);
		return RELEASED_ACT;
	}
	return PUSH_ACT;
}
*/

#include "Button.h"

void Button_Init(Button_typedef *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
	button->ddr = ddr;
	button->pin = pin;
	button->pinNum = pinNum;
	button->prevState = RELEASED;
	*button->ddr &= ~(1 << button->pinNum);
}

int Button_GetState(Button_typedef *button)
{
	uint8_t curState = *button->pin & (1<<button->pinNum);
	if((curState == PUSHED) && (button->prevState == RELEASED))
	{
		button->prevState = PUSHED;
		_delay_ms(10); //chattering
		return PUSH_ACT;
	}
	else if((curState!=PUSHED) && (button->prevState == PUSHED))
	{
		button->prevState = RELEASED;
		_delay_ms(10);
		return RELEASED_ACT;
	}
	return PUSH_ACT;
}
/*
 * Listener.c
 *
 * Created: 2022-11-08 오후 3:18:16
 *  Author: kccistc
 */ 
#include "Listener.h"

//static Button_typedef modeButton; //Listener.c에서만 접근할 수 있음(static의 기능)
//static Button_typedef upButton;
static Button_typedef leftButton;
static Button_typedef rightButton;

void Listener_Init()
{
	//Button_Init(&modeButton, &DDRE, &PINE, 4);
	Button_Init(&rightButton, &DDRE, &PINE, 4);
	//Button_Init(&upButton, &DDRE, &PINE, 5);
	Button_Init(&leftButton, &DDRE, &PINE, 5);
}
void Listener()
{
	/* mode에서 left right으로(View단 추가)
	if(Button_GetState(&modeButton)  == RELEASED_ACT)
	{
		PORTA ^= 0x0f;
	}
	if(Button_GetState(&upButton)  == RELEASED_ACT)
	{
		PORTA ^= 0xf0;
	}
	*/
	if (Button_GetState(&rightButton) == RELEASED_ACT)
	{
		View_SetState(RIGHT_SHIFT);
	}
	if (Button_GetState(&leftButton) == RELEASED_ACT)
	{
		View_SetState(LEFT_SHIFT);
	}
}
/*
 * additional_lecture.c
 * road sign board
 * Created: 2022-11-08 오전 10:02:24
 * Author : kccistc
 */ 

#include "main.h"

/*1
typedef struct _gpio{
	volatile uint8_t *pin;
	volatile uint8_t *ddr;
	volatile uint8_t *port;
	}GPIO;
	
#define GPIOA *(GPIO *)0x39
#define GPIOB *(GPIO *)0x36
#define GPIOC *(GPIO *)0x33
*/

ISR(TIMER0_COMP_vect)
{
	incTick();
}

int main(void)
{
	Tick_Init();
	
    /* Replace with your application code */
	/*1GPIOA.ddr = 0xff;*/
	
	//DDRA = 0xff; //all outputs
	Led_Init();
	/*
	volatile uint8_t *pDDR;
	pDDR = &DDRA;
	*pDDR = 0xff;
	*((volatile ))
	*/
	
	//DDRE = 0x00; //all inputs //동일 함수 늘리기 싫어서 각 함수의 변수만을 따옴. struct _button으로 이어짐
	/*Listener로 넘기고 싶음
	Button_typedef modeButton;
	Button_Init(&modeButton, &DDRE, &PINE, 5);
	*/
	Listener_Init();
	
	sei(); //global interrupt 동작
    while (1) 
    {
		/*BUTTON_GetState2로 대체
		if((PINE & (1<<5)) == 0)
		{
			PORTA = 0xf0;
		}
		*/
		
		/*BUTTON_GetState로 대체
		if((PINE & (1<<4)) == 0)
		{
			PORTA = 0x0f;
		}
		*/
		/*동일 함수 늘리기 싫어서 각 함수의 변수만을 따옴. struct _button으로 이어짐		
		if(Button_GetState() == RELEASED_ACT)
		{
			PORTA ^= 0x0f;
		}
		if (Button_GetState2() == RELEASED_ACT)
		{
			PORTA ^= 0xf0;
		}
		*/
		
		/*Listener로 넘기고 싶음
		if(Button_GetState(&modeButton)  == RELEASED_ACT)
		{
			PORTA ^= 0x0f;
		}
		*/
		Listener();
		View();
    }
}


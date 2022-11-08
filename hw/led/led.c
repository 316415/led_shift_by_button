/*
 * led.c
 *
 * Created: 2022-11-08 오후 3:51:14
 *  Author: kccistc
 */ 

#include "led.h"

int ledState = 0x01;
int led_value = 0;

void Led_Init()
{
	LED_DDR = 0xff;
}
void Led_LeftShift()
{
	ledState = 0x80;
	LED_PORT = ledState >> led_value;
	led_value++;
	if(led_value == 8) led_value = 0;
}
void Led_RightShift()
{
	ledState = 0x01;
	LED_PORT = ledState << led_value;
	led_value++;
	if(led_value == 8) led_value = 0;
}
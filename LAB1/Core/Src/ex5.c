/*
 * ex5.c
 *
 *  Created on: Nov 14, 2024
 *      Author: quyng
 */



#include "ex4.h"
#include "ex3.h"
#include "display_7SEG.h"
#include "software_timer.h"

#define TIME_7SEG 250
#define TIME_DOT 1000
#define TIME_LED_BLINKY 1000

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

int hour = 15, minute = 58, second = 50;

void updateClockBuffer()
{
	led_buffer[0] = (hour / 10) % 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = (minute / 10) % 10;
	led_buffer[3] = minute % 10;
}
void update7SEG_ex5(int index )
{
	switch (index) {
		case 0:
			display7SEG(led_buffer[0]);
			enable_seg(0);
			break;
		case 1:
			display7SEG(led_buffer[1]);
			enable_seg(1);
			break;
		case 2:
			display7SEG(led_buffer[2]);
			enable_seg(2);
			break;
		case 3:
			display7SEG(led_buffer[3]);
			enable_seg(3);
			break;
		default:
			break;
	}
}
void run5()
{
	if (timer1_flag ==1 )
	{
		update7SEG_ex5(index_led);
		index_led++ ;

		if (index_led > 3 )
		{
			index_led = 0;
		}

		settimer1(250);
	}

	if (timer2_flag ==1)
	{
		++second;
		if (second >= 60)
		{
			second = 0;
			++minute;
		}
		if (minute >= 60)
		{
			minute = 0;
			++hour;
		}
		if (hour >= 24)
		{
			hour = 0;
		}
		updateClockBuffer();

		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		settimer2(1000);
	}

	if (timer3_flag ==1 )
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		settimer3(100);
	}
}


void init5()
{


	updateClockBuffer();
	settimer1(250);
	settimer2(1000);
	settimer3(1000);

}

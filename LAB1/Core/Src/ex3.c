/*
 * ex3.c
 *
 *  Created on: Nov 14, 2024
 *      Author: quyng
 */



#include "ex3.h"
#include "display_7SEG.h"
#include "software_timer.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG 1

#define TIMER_7SEG 3
#define TIME_7SEG 20

#define TIMER_DOT 4
#define TIME_DOT 1000

#define TIMER_LED_BLINKY 1
#define TIME_LED_BLINKY 1000


const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {11, 7, 8, 9};
void run3()
{

	if (timer1_flag ==1 )
	{
		update7SEG(index_led);
		++index_led;
		if (index_led >= 4)
		{
			index_led = 0;
		}

		settimer1(500);

	}

	if (timer2_flag == 1)
	{
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		settimer2(1000);
	}

	if (timer3_flag == 1 )
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		settimer3(1000);
	}
}

void update7SEG(int idx)
{
	switch (idx) {
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

/*
 * ex4.c
 *
 *  Created on: Nov 14, 2024
 *      Author: quyng
 */



#include "ex4.h"
#include "ex3.h"
#include "display_7SEG.h"
#include "software_timer.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG 1


#define TIME_7SEG 250


#define TIME_DOT 1000


#define TIME_LED_BLINKY 1000
int index_led_ex4 = 0 ;
int led_buffer_ex4[4] = { 6 , 7, 8, 9};
void run4()
{

	if (timer1_flag ==1 )
	{
		update7SEG_ex4(index_led_ex4);
		++index_led_ex4;
		if (index_led_ex4 >= 4)
		{
			index_led_ex4 = 0;
		}

		settimer1(TIME_7SEG);

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

void update7SEG_ex4(int idx)
{
	switch (idx) {
		case 0:
			display7SEG(led_buffer_ex4[0]);
			enable_seg(0);
			break;
		case 1:
			display7SEG(led_buffer_ex4[1]);
			enable_seg(1);
			break;
		case 2:
			display7SEG(led_buffer_ex4[2]);
			enable_seg(2);
			break;
		case 3:
			display7SEG(led_buffer_ex4[3]);
			enable_seg(3);
			break;
		default:
			break;
	}
}

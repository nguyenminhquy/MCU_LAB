/*
 * ex4.c
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */


#include "ex5.h"
#include "main.h"
#include "software_timer.h"
#include "7seg.h"


int index_led_5 = 0;
int led_buffer_5[4] ;
int hour = 15, minute = 50, second = 10;

void update7SEG_ex5(int idx)
{
	switch (idx) {
		case 0:
			display7SEG(led_buffer_5[0]);
			enable_seg(0);
			break;
		case 1:
			display7SEG(led_buffer_5[1]);
			enable_seg(1);
			break;
		case 2:
			display7SEG(led_buffer_5[2]);
			enable_seg(2);
			break;
		case 3:
			display7SEG(led_buffer_5[3]);
			enable_seg(3);
			break;
		default:
			break;
	}
}
void updateClockBuffer_ex5()
{
	led_buffer_5[0] = (hour / 10) % 10;
	led_buffer_5[1] = hour % 10;
	led_buffer_5[2] = (minute / 10) % 10;
	led_buffer_5[3] = minute % 10;
}
void run5()
{
    if(timer1_flag ==1 )
    {

    	setTimer1(1000);
    	HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);

    }
    if(timer2_flag == 1 )
    {
    	setTimer2(100);
    		update7SEG_ex5(index_led_5);
    		index_led_5++ ;
    		if(index_led_5>4 )
    		{
    			index_led_5= 0 ;
    		}
    }
    if(timer3_flag ==1 )
    {
    	setTimer3(500);
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
    			updateClockBuffer_ex5();

    	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
    }
}

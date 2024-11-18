/*
 * ex4.c
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */


#include "ex4.h"
#include "main.h"
#include "software_timer.h"
#include "7seg.h"


int index_led_4 = 0;
int led_buffer_4[4] = {6, 7, 8, 9};

void update7SEG_ex4(int idx)
{
	switch (idx) {
		case 0:
			display7SEG(led_buffer_4[0]);
			enable_seg(0);
			break;
		case 1:
			display7SEG(led_buffer_4[1]);
			enable_seg(1);
			break;
		case 2:
			display7SEG(led_buffer_4[2]);
			enable_seg(2);
			break;
		case 3:
			display7SEG(led_buffer_4[3]);
			enable_seg(3);
			break;
		default:
			break;
	}
}
void run4()
{
    if(timer1_flag ==1 )
    {

    	setTimer1(1000);
    	HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);

    }
    if(timer2_flag == 1 )
    {
    	setTimer2(250);
    		update7SEG(index_led_4);
    		index_led_4++ ;
    		if(index_led_4>4 )
    		{
    			index_led_4= 0 ;
    		}
    }
    if(timer3_flag ==1 )
    {
    	setTimer3(1000);
    	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
    }
}

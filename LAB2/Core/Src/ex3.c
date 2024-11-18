/*
 * ex3.h
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */


#include "ex3.h"
#include "main.h"
#include "software_timer.h"
#include "7seg.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {6, 7, 8, 9};
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
int state_3  = 0 ; // 0  den o  1 den 1
void run3()
{
    if(timer1_flag ==1 )
    {

    	setTimer1(1000);
    	HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);

    }
    if(timer2_flag == 1 )
    {
    	setTimer2(500);
    		update7SEG(index_led);
    		index_led++ ;
    		if(index_led>4 )
    		{
    			index_led= 0 ;
    		}
    }
    if(timer3_flag ==1 )
    {
    	setTimer3(1000);
    	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
    }



}

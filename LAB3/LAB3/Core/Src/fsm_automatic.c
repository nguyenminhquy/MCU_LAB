/*
 * fsm_automatic.c
 *
 *  Created on: Nov 17, 2024
 *      Author: quyng
 */



#include "fsm_automatic.h"
#include "main.h"
#include "software_timer.h"
#include "7seg.h"
#include "led.h"
#include "global.h"
#include "main.h"


void fsm_automatic_run1()
{

	if (timer1_counter % 100 == 0){

			int remaining_time = timer1_counter / 100;
			updatebuffer1(remaining_time);


		}

	    if(timer2_flag ==1 )
	    {
	        setTimer2(300);
	        display7SEG(led_buffer_1[index_led_1]);
		    enable_seg_0_1(index_led_1);
			index_led_1++;
			if (index_led_1 > 1) {
		    index_led_1 = 0;
		  }

	    }
		switch(LED_STATE1)
		{
		case INIT_STATE:
			setup1();
			setTimer1(RED_DURATION*1000);
			LED_STATE1= AUTO_RED;
			break ;
		case AUTO_RED:
			red_led1();
			if(timer1_flag ==1)
			{
				setTimer1(GREEN_DURATION*1000);
			    LED_STATE1= AUTO_GREEN;
			}
			break ;
		case AUTO_GREEN:
			green_led1();
			if(timer1_flag ==1 )
			{
				setTimer1(YELLOW_DURATION*1000);
				LED_STATE1 = AUTO_YELLOW;
			}
			break;
		case AUTO_YELLOW:
			yellow_led1();
			if(timer1_flag ==1 )
			{
				setTimer1(RED_DURATION*1000);
				LED_STATE1 = AUTO_RED;
			}
			break;

		}



}
void fsm_automatic_run2()
{

	if (timer3_counter % 100 == 0){

		int remaining_time = timer3_counter / 100;
		updatebuffer2(remaining_time);


	}

    if(timer4_flag ==1 )
    {
        setTimer4(300);
        display7SEG_2(led_buffer_2[index_led_2]);
	    enable_seg_2_3(index_led_2);
		index_led_2++;
		if (index_led_2 > 1) {
	    index_led_2 = 0;
	  }

    }
	switch(LED_STATE2)
	{
	case INIT_STATE:
		setup2();
		setTimer3(GREEN_DURATION*1000);
		LED_STATE2= AUTO_GREEN;
		break ;
	case AUTO_RED:
		red_led2();
		if(timer3_flag ==1)
		{
			setTimer3(GREEN_DURATION*1000);
		    LED_STATE2= AUTO_GREEN;
		}
		break ;
	case AUTO_GREEN:
		green_led2();
		if(timer3_flag ==1 )
		{
			setTimer3(YELLOW_DURATION*1000);
			LED_STATE2 = AUTO_YELLOW;
		}
		break;
	case AUTO_YELLOW:
		yellow_led2();
		if(timer3_flag ==1 )
		{
			setTimer3(RED_DURATION*1000);
			LED_STATE2 = AUTO_RED;
		}
		break;

	}



}

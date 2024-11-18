/*
 * fsm_manual.c
 *
 *  Created on: Nov 18, 2024
 *      Author: quyng
 */


#include "fsm_manual.h"
#include "fsm_automatic.h"
#include "main.h"
#include "global.h"
#include "software_timer.h"
#include "led.h"
#include "button.h"
#include "7seg.h"



int tempDuration = 0;

void change_mode(int mode )
{
	setup1();
	setup2();
	MODE = mode;
	setTimer7(10);
}

void displayDuration(int mode, int duration) {
    led_buffer_1[0] = 0;            // LED 0 hiển thị chế độ (mode)
    led_buffer_1[1] = mode ;
    led_buffer_2[1] = duration % 10;   // LED 2 hiển thị hàng đơn vị của duration
    led_buffer_2[0] = duration / 10;   // LED 3 hiển thị hàng chục của duration
    if(timer5_flag ==1 )
    {
    	setTimer5(300);
    	display7SEG(led_buffer_1[index_led_1]);
    	enable_seg_0_1(index_led_1);
        index_led_1++;
    	if (index_led_1 > 1)
        {
        index_led_1 = 0;
        }
    }
    if(timer6_flag ==1 )
    {
    	setTimer6(300);
    	display7SEG_2(led_buffer_2[index_led_2]);
    	enable_seg_2_3(index_led_2);
        index_led_2++;
    	if (index_led_2 > 1)
        {
        index_led_2 = 0;
        }
    }

}


void fsm_manual_run()
{
	switch(MODE)
	{
	    case INIT_MODE:
	    	 init1();
	    	 init2();
	    	 led_buffer_1[0] = 0;
	    	 led_buffer_1[1] = 0;
	    	 led_buffer_2[1] = 0;
	    	 led_buffer_2[0] = 0;
	    	    if(timer5_flag ==1 )
	    	    {
	    	    	setTimer5(300);
	    	    	display7SEG(led_buffer_1[index_led_1]);
	    	    	enable_seg_0_1(index_led_1);
	    	        index_led_1++;
	    	    	if (index_led_1 > 1)
	    	        {
	    	        index_led_1 = 0;
	    	        }
	    	    }
	    	    if(timer6_flag ==1 )
	    	    {
	    	    	setTimer6(300);
	    	    	display7SEG_2(led_buffer_2[index_led_2]);
	    	    	enable_seg_2_3(index_led_2);
	    	        index_led_2++;
	    	    	if (index_led_2 > 1)
	    	        {
	    	        index_led_2 = 0;
	    	        }
	    	    }
	    	    if (isButtonPressed(0) == 1){
	    	    	tempDuration = RED_DURATION;

	    	    	change_mode(MODE_1);


	    	    }
	    	    break;
	    case MODE_1:
	    	fsm_automatic_run1();
	    	fsm_automatic_run2();
	    	 if (isButtonPressed(0) == 1){
	    		 tempDuration = RED_DURATION;
	    		  change_mode(MODE_2);
	    	 }

	    	 break ;

	    case MODE_2:// red
	    	displayDuration(2, tempDuration);


	    	if(isButtonPressed(0)==1)
	    	{
	    		tempDuration = YELLOW_DURATION;
	    		change_mode(MODE_3);
	    	}

	    	if(timer7_flag ==1)
	    	{
	    		setTimer7(500);
	    		HAL_GPIO_TogglePin(RED_LED2_GPIO_Port, RED_LED2_Pin);
	    	    HAL_GPIO_TogglePin(RED_LED1_GPIO_Port, RED_LED1_Pin);
	    	}
			if (isButtonPressed(1) == 1){

				change_mode(RED_CONFIG);


			}
			if (isButtonPressed(2) == 1){
				change_mode(RED_CONFIRM);
			}
	    	break ;

	    case MODE_3://yellow
	    	displayDuration(3, tempDuration);

	    	if(isButtonPressed(0)==1)
	    	{
	    		tempDuration = GREEN_DURATION;
	    		change_mode(MODE_4);
	    	}

	    	if(timer7_flag ==1)
	    	{
	    		setTimer7(500);
	    		HAL_GPIO_TogglePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin);
	    	    HAL_GPIO_TogglePin(YELLOW_LED1_GPIO_Port, YELLOW_LED1_Pin);
	    	}
			if (isButtonPressed(1) == 1){
				change_mode(YELLOW_CONFIG);

			}
			if (isButtonPressed(2) == 1){
				change_mode(YELLOW_CONFIRM);
			}
	    	break ;
	    case MODE_4://green
	    	displayDuration(4, tempDuration);
	    	if(isButtonPressed(0)==1)
	    	{
	    		tempDuration = RED_DURATION;
	    		change_mode(INIT_MODE);
	    	}

	    	if(timer7_flag ==1)
	    	{
	    		setTimer7(500);
	    		HAL_GPIO_TogglePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin);
	    	    HAL_GPIO_TogglePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin);
	    	}
			if (isButtonPressed(1) == 1){
				change_mode(GREEN_CONFIG);

			}
			if (isButtonPressed(2) == 1){
				change_mode(GREEN_CONFIRM);
			}
	    	break ;



	    case RED_CONFIRM:
	    	RED_DURATION = tempDuration;
	    	change_mode(MODE_2);
	    	break ;
	    case RED_CONFIG:
	    	tempDuration++;
	    	tempDuration %= 100;
	    	change_mode(MODE_2);
	    	break;
	    case YELLOW_CONFIG:
	    	tempDuration++;
	        tempDuration %= 100;
	    	change_mode(MODE_3);
	        break;
	    case YELLOW_CONFIRM:
			YELLOW_DURATION = tempDuration;
			change_mode(MODE_3);
			break ;
	    case GREEN_CONFIRM:
	    	GREEN_DURATION = tempDuration;
	    	change_mode(MODE_4);
	    	break;
	    case GREEN_CONFIG:
	    	tempDuration++;
	        tempDuration %= 100;
	    	change_mode(MODE_4);
	        break;
		default:
			 break;


	}


}


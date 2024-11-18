/*
 * ex2.c
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */



#include "ex3.h"
#include "main.h"
#include "software_timer.h"
#include "7seg.h"

int state_2  = 0 ; // 0  den o  1 den 1
void run2()
{
    if(timer1_flag ==1 )
    {

    	setTimer1(1000);
    	HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);

    }
    if(timer2_flag == 1 )
    {
    	setTimer2(500);
    	switch(state_2)
    	{
    	case 0 :
    		display7SEG(1);
    		enable_seg(0);
    		state_2 = 1 ;
    		break ;

    	case 1 :
    		display7SEG(2);
    		enable_seg(1);
    		state_2 = 2 ;
    		break ;
    	case 2:
    		display7SEG(3);
    		enable_seg(2);
    		state_2 = 3 ;
    		break ;
    	case 3:
    		display7SEG(0);
    		enable_seg(3);
    		state_2 = 0 ;
    		break ;

    	}
    }
    if(timer3_flag ==1 )
    {
    	setTimer3(1000);
    	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);



    }



}

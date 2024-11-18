/*
 * ex1.c
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */


#include "ex1.h"
#include "main.h"
#include "software_timer.h"
#include "7seg.h"

int state  = 0 ; // 0  den o  1 den 1
void run1()
{
    if(timer1_flag ==1 )
    {

    	setTimer1(1000);
    	HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);

    }
    if(timer2_flag == 1 )
    {
    	setTimer2(500);
    	switch(state)
    	{
    	case 0 :
    		display7SEG(1);
    		enable_seg(0);
    		state = 1 ;
    		break ;

    	case 1 :
    		display7SEG(2);
    		enable_seg(1);
    		state = 0 ;
    		break ;
    	}


    }



}

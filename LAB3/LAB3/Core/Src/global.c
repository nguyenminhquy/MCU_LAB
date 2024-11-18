/*
 * global.c
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */
#include "global.h"
#include "main.h"

 int index_led_1 = 0; //0  1
 int index_led_2 = 0;  // 0 1

 int led_buffer_1[2]={0,0} ;
 int led_buffer_2[2]={0,0} ;

 int counter_way2 = 0 ;
 int counter_way1  = 0 ;

 int LED_STATE1 = INIT_STATE ;
 int LED_STATE2 = INIT_STATE ;

 int MODE = INIT_MODE ;


 int RED_DURATION   =   5;
 int YELLOW_DURATION =  2;
 int GREEN_DURATION =   3;

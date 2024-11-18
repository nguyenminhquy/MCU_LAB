/*
 * ex2.c
 *
 *  Created on: Nov 14, 2024
 *      Author: quyng
 */


#include "ex2.h"
#include "display_7SEG.h"
#include "software_timer.h"


#define LED_ON  0
#define LED_OFF 1
#define ENABLE_SEG  0
#define DISABLE_SEG 1
#define TIME_7SEG 500
#define TIME_LED_BLINKY 1000

typedef enum
{
	INIT,
	LED1,
	LED2,
	LED3,
	LED4
}  STATE2;

 STATE2  state2  = INIT ;

void init2()
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET
	HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET); // Hoặc GPIO_PIN_RESET


}
void run2()
{
	if(timer2_flag ==1 )
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		settimer2(1000);
	}
    if(timer3_flag ==1 )
    {
    	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
    	settimer3(1000);
    }

	switch(state2)
	{
	case INIT :
		if(1)
		{
			state2 = LED1 ;
			settimer1(500);
		}
		break ;
	case LED1:
		display7SEG(1);
		enable_seg(0);
		if(timer1_flag ==1 )
		{
			state2 = LED2 ;
			settimer1(500);
		}

		break ;
	case LED2:
		display7SEG(2);
		enable_seg(1);
		if(timer1_flag ==1 )
		{
			state2 = LED3 ;
			settimer1(500);
		}

		break ;
	case LED3:
		display7SEG(3);
		enable_seg(2);
		if(timer1_flag ==1 )
		{
			state2 = LED4 ;
			settimer1(500);
		}

		break ;
	case LED4:
		display7SEG(0);
		enable_seg(3);
		if(timer1_flag ==1 )
		{
			state2 = LED1 ;
			settimer1(500);
		}

		break ;






	}






}




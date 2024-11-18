/*
 * led.c
 *
 *  Created on: Nov 17, 2024
 *      Author: quyng
 */


#include "led.h"
#include "software_timer.h"
#include "global.h"
#include "7seg.h"
#include "main.h"

void setup1()
{
	    HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, GPIO_PIN_SET);   // Tắt đèn đỏ Lane 1
	    HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, GPIO_PIN_SET); // Tắt đèn xanh Lane 1
	    HAL_GPIO_WritePin(YELLOW_LED1_GPIO_Port, YELLOW_LED1_Pin, GPIO_PIN_SET); // Tắt đè
}
void init1()
{
    HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, GPIO_PIN_RESET);   // Tắt đèn đỏ Lane 1
    HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, GPIO_PIN_RESET); // Tắt đèn xanh Lane 1
    HAL_GPIO_WritePin(YELLOW_LED1_GPIO_Port, YELLOW_LED1_Pin, GPIO_PIN_RESET); // Tắt đè
}
void init2()
{
    HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, GPIO_PIN_RESET);   // Tắt đèn đỏ Lane 1
    HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, GPIO_PIN_RESET); // Tắt đèn xanh Lane 1
    HAL_GPIO_WritePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin, GPIO_PIN_RESET); // Tắt đè
}

void setup2()
{
	    HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, GPIO_PIN_SET);   // Tắt đèn đỏ Lane 2
	    HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, GPIO_PIN_SET); // Tắt đèn xanh Lane 2
	    HAL_GPIO_WritePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin, GPIO_PIN_SET); // Tắt đèn vàng Lane 2
}
void red_led1() {
    HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);   // Bật đèn đỏ Lane 1
    HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET); // Tắt đèn xanh Lane 1
    HAL_GPIO_WritePin(YELLOW_LED1_GPIO_Port, YELLOW_LED1_Pin, SET); // Tắt đèn vàng Lane 1

}

void green_led1() {
    HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, SET);     // Tắt đèn đỏ Lane 1
    HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, RESET); // Bật đèn xanh Lane 1
    HAL_GPIO_WritePin(YELLOW_LED1_GPIO_Port, YELLOW_LED1_Pin, SET); // Tắt đèn vàng Lane 1

}

void yellow_led1() {
    HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, SET);     // Tắt đèn đỏ Lane 1
    HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET); // Tắt đèn xanh Lane 1
    HAL_GPIO_WritePin(YELLOW_LED1_GPIO_Port, YELLOW_LED1_Pin, RESET); // Bật đèn vàng Lane 1

}

void red_led2() {
    HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, RESET);   // Bật đèn đỏ Lane 2
    HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET); // Tắt đèn xanh Lane 2
    HAL_GPIO_WritePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin, SET); // Tắt đèn vàng Lane 2
}

void green_led2() {
    HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);     // Tắt đèn đỏ Lane 2
    HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, RESET); // Bật đèn xanh Lane 2
    HAL_GPIO_WritePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin, SET); // Tắt đèn vàng Lane 2
}

void yellow_led2() {
    HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);     // Tắt đèn đỏ Lane 2
    HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET); // Tắt đèn xanh Lane 2
    HAL_GPIO_WritePin(YELLOW_LED2_GPIO_Port, YELLOW_LED2_Pin, RESET); // Bật đèn vàng Lane 2
}

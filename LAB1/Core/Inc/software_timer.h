/*
 * software_timer.h
 *
 *  Created on: Nov 14, 2024
 *      Author: quyng
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
extern int timer1_flag ;
extern int timer2_flag ;
extern int timer3_flag ;


void settimer1(int duration);
void settimer2(int duration);
void settimer3(int duration);

void timerrun();

#endif /* INC_SOFTWARE_TIMER_H_ */

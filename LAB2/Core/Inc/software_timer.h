/*
 * software_timer.h
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


// timer1
extern int timer1_flag ;
void setTimer1(int duration) ;

// timer2
extern int timer2_flag ;
void setTimer2(int duration) ;
// timer3
extern int timer3_flag ;
void setTimer3(int duration) ;






void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */

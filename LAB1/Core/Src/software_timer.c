/*
 * software_timer.c
 *
 *  Created on: Nov 14, 2024
 *      Author: quyng
 */


#include "software_timer.h"
#define TICK 10
int timer1_counter = 0 ;
int timer2_counter = 0 ;
int timer3_counter = 0 ;
int timer1_flag  = 0 ;
int timer2_flag  = 0 ;
int timer3_flag  = 0 ;

// settimer setting
void settimer1(int duration)
{
	timer1_counter = duration/ TICK ;
	timer1_flag    = 0 ;

}
void settimer2(int duration)
{
	timer2_counter = duration/ TICK ;
	timer2_flag    = 0 ;

}
void settimer3(int duration)
{
	timer3_counter = duration/ TICK ;
	timer3_flag    = 0 ;

}
// timner run
void timerrun()
{
	if(timer1_counter > 0 )
	{
		timer1_counter-- ;
		if(timer1_counter <= 0 )
		{
			timer1_flag = 1 ;
		}
	}
	if(timer2_counter > 0 )
	{
		timer2_counter-- ;
		if(timer2_counter <= 0 )
		{
			timer2_flag = 1 ;
		}
	}
	if(timer3_counter > 0 )
	{
		timer3_counter-- ;
		if(timer3_counter <= 0 )
		{
			timer3_flag = 1 ;
		}
	}
}


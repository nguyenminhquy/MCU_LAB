/*
 * global.h
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int counter_way2;
extern int counter_way1;
extern int index_led_1 ; //0  1
extern int index_led_2 ;  // 0 1

extern int led_buffer_1[2] ;
extern int led_buffer_2[2] ;
// DINH NGHIA CAC TRANG THAI TRONG AUTOMATIC
#define INIT_STATE        1
#define AUTO_GREEN        3
#define AUTO_RED          2
#define AUTO_YELLOW       4


extern int timer1_flag ;
extern int timer1_counter ;
extern int timer2_flag ;
extern int timer2_counter ;
extern int timer3_flag ;
extern int timer3_counter ;
extern int timer4_flag ;
extern int timer4_counter ;
extern int timer5_flag ;
extern int timer5_counter ;
extern int timer6_flag ;
extern int timer6_counter ;
extern int timer7_flag ;
extern int timer7_counter ;
extern int timer8_flag ;
extern int timer8_counter ;


extern int LED_STATE1 ;
extern int LED_STATE2 ;
extern int MODE ;
#define INIT_MODE  10
#define MODE_1 11
#define MODE_2 12
#define MODE_3 13
#define MODE_4 14
#define RED_CONFIG 15
#define YELLOW_CONFIG 16
#define GREEN_CONFIG 17
#define RED_CONFIRM 18
#define GREEN_CONFIRM 19
#define YELLOW_CONFIRM 20


extern int RED_DURATION;
extern int YELLOW_DURATION;
extern int GREEN_DURATION;
#endif /* INC_GLOBAL_H_ */

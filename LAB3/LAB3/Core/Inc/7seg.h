/*
 * 7seg.h
 *
 *  Created on: Nov 16, 2024
 *      Author: quyng
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_
void display7SEG(int num);
void display7SEG_2(int num);
void enable_seg_0_1(int num);
void enable_seg_2_3(int num);
void updatebuffer2(int duration);
void updatebuffer1(int duration);
void displaynumber1(int num );
#endif /* INC_7SEG_H_ */

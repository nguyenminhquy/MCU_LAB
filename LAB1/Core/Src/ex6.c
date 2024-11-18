/*
 * ex6.c
 *
 *  Created on: Nov 14, 2024
 *      Author: quyng
 */




#include "display_7SEG.h"
#include "software_timer.h"


int counter = 10;
int counter1= 11;
int led_buffer[4];
int display_index =0  ;
int display_index1 =0  ;
int count= 0 ;


void updateDisplay()
{

	led_buffer[0] = counter / 10;     // Chữ số hàng chục
    led_buffer[1] = counter  % 10;
    led_buffer[2] = counter / 10 ;
    led_buffer[3] = counter % 10 ;


}
void update7SEG_ex6(int display_index )
{
	switch (display_index) {
		case 0:
			display7SEG(led_buffer[0]);
			enable_seg(0);
			break ;
		case 1:

			break ;
		case 2 :
			display7SEG(led_buffer[2]);
			enable_seg(2);
			break;
		case 3 :

			break;

		default:
			break;
	}
}
void update_7led_unit(int display_index1)
{
	switch (display_index1) {
		case 0:

			break ;
		case 1:
			display7SEG(led_buffer[1]);
			enable_seg(1);
			break ;
		case 2 :

			break;
		case 3 :
			display7SEG(led_buffer[3]);
			enable_seg();
			break;

		default:
			break;
	}
}
void run6()
{
    if (timer1_flag == 1)
    {
    	updateDisplay();


        counter--;
        if (counter < 0 )
        {
            counter = 10;
        }

        settimer1(1000);
    }



    if(timer2_flag ==1)
    {

 	   update7SEG_ex6(display_index);

 	       	display_index++ ;
 	       	if (display_index > 4 )
 	       			{
 	       		display_index = 0;
 	       			}
 	       	settimer2(200);
    }
    if(timer3_flag == 1 )
    {
    	update_7led_unit(display_index1);

    	 	       	display_index1++ ;
    	 	       	if (display_index > 4 )
    	 	       			{
    	 	       		display_index1 = 0;
    	 	       			}
    	 	       	settimer3(50);
    }

}









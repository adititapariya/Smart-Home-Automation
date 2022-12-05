/*
 * led_blinking_withbutton.cpp
 *
 * Created: 28-06-2022 19:44:36
 * Author : hp
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRB = 0B00000001;
    /* Replace with your application code */
    while (1) 
    {
		if (PINB & 0B00010000)
		{
			PORTB = 0B00000001;}
	    else{
			PORTB = 0B00000000;}
    }s
}


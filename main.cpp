/*
 * led_blinking.cpp
 *
 * Created: 28-06-2022 16:52:49
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB=0XFF;
    while (1) 
    {
		PORTB=0XFF;
		_delay_ms(1000);
		PORTB=0X00;
		_delay_ms(1000);
		
    }
}


/*
 * led_sequence.c
 *
 * Created: 30-06-2022 22:07:11
 * Author : hp
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
     DDRB = (1<< PB0 | 1<< PB1 | 1<< PB2 | 1<< PB3);
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1<< PB0 | 1<< PB2);
		PORTB &= ~(1<< PB1 | 1<< PB3);
		_delay_ms(1000);
		PORTB &= ~(1<< PB0 | 1<< PB2);
		PORTB |= (1<< PB1 | 1<< PB3);
		_delay_ms(1000);
		
    }
}


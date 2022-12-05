/*
 * led_blink_operators.c
 *
 * Created: 30-06-2022 18:59:48
 * Author : hp
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= (1<<PB0);
	/* Replace with your application code */
	while (1)
	{
		PORTB |=(1<<PB0);
		_delay_ms(1000);
		PORTB &=~(1<<PB0);
		_delay_ms(1000);
	}
}




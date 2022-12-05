/*
 * led_pwn2.c
 *
 * Created: 10-07-2022 16:27:52
 * Author : hp
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}


int main ()
{
	unsigned char duty;
	
	PWM_init();
	while (1)
	{
		
			OCR0=64; 
			_delay_ms(10);
		
	}
}



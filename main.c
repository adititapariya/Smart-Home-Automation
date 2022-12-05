#include <avr/io.h>
#define F_CPU 800000000UL
#include <util/delay.h>

int main()
{
	DDRD=0b10000000;
	DDRB=0b00001000;
	TCCR0=0b00111101;
	TCCR2=0b00111001;
	while (1)
	{
		OCR0=200;
		OCR2=50;
		
	}
	return 0;
}
/*
 * GccApplication1.c
 *
 * Created: 11-07-2022 23:43:09
 * Author : hp
 */ 



#include <avr/io.h>
#define F_CPU 1000000UL		/* Define frequency here its 1MHz */
#include <util/delay.h>



void USART_Init( unsigned int baud )
{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}
void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}


int main(void)
{
	unsigned char duty;
	
	PWM_init();
	DDRB|=(1<<PB0 | 1<<PB1);
	

	USART_Init(25);
	char a;
	while (1)
while (1)
{
	if (USART_Receive()=='T')
	{
		duty=64;
		OCR0=duty;
		PORTB|=(1<<PB1);
		
	}
	if (USART_Receive()=='i')
	{
		
		duty+=10;
		OCR0=duty;
		
	}
	if(USART_Receive()=='d')
	{
		
		duty-=10;
		OCR0=duty;
	}
	if(USART_Receive()=='F')
	{
		duty=0;
		OCR0=duty;
		PORTB &=~(1<<PB1);
	}
	
	
	
	
	
}
}

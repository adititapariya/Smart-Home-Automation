/*
 * Bluetooth.c
 *
 * Created: 07-07-2022 21:48:50
 * Author : hp
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL		/* Define frequency here its 1MHz */




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

int main(void)
{
	DDRB|=(1<<PB0);
	USART_Init(25);
	while (1)
	{
		if(USART_Receive()=='T')
		{
			PORTB|=(1<<PB0);
		}
		else if(USART_Receive()=='F')
		{
			PORTB&=~(1<<PB0);
		}
		
	}
}




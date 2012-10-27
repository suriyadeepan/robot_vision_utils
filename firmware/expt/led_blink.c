#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>



void main()
{
	DDRB=0xff;

	while(1)
	{
		PORTB=0xff;
		_delay_ms(900);
		PORTB=0x00;
		_delay_ms(900);
	}



}

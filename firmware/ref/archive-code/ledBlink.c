#include <avr/io.h>

#define F_CPU 1000000UL

#include <util/delay.h>










int main()
{


	DDRD=0xff;

	while(1)
	{
		PORTD=0x00;
		_delay_ms(900);
		PORTD=0xff;
		_delay_ms(900);
	
	}


}


#include <avr/io.h>
#include <util/delay_basic.h>
#include <util/delay.h>


#define F_CPU 1000000UL

//typedef unsigned char uchar;




int main()
{

	
	
	DDRB = 0xff;

	

	while(1)
	{

		PORTB=0xff;
		_delay_ms(4000);
		PORTB=0x00;
		_delay_ms(4000);

	}


}

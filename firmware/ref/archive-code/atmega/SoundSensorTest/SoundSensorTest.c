
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA=0x00;
	DDRD=0xFF;

	while(1)
	{
		if( PINA & 0x80)
		{
			PORTD=0xff;
			//_delay_ms(900);
		}

		else
		PORTD=0x00;

		//else
		//PORTD=0x00;


	}


}

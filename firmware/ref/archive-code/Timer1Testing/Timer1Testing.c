
#include <avr/io.h>

int count=1;

void init_timer1()
{
	TCCR1B=0x19;
	TCNT1=0;
	TCCR1A=0xa2;
	TIMSK=0x00;
	sei();
	OCR1A=0x0000;

}

int main()
{
	DDRD=0xff;

	init_timer1();

	while(1)
	{
				

		if(OCR1A==20000)
		{
			OCR1A=0x0000;
			count=1;
		}
		else
		{
			OCR1A=(100*count);
			_delay_ms(10);
			count++;
		}

	}

}


	}
}

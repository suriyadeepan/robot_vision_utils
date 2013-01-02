#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "SevenSegment.h"
//#include "SevenSegmentDisplay.c"

int num=0;
unsigned int count=0;

void init_timer0()
{
	
	TCCR0=0x03;
	// set prescalar as 64

	TIMSK|=(1<<TOIE0);
	// for enabling overflow interrupt

	TCNT0=0;
	// init counter

	
}

ISR(TIMER0_OVF_vect)
{
	if(count==61)
	{
		num++;
		count=0;

	}

	else
	count++;


}

int main()
{

		DDRA=0xfc;
		DDRD=0xff;
		DDRB=0x0f;

		PORTB=0x00;	
		
		
		int tempNum=0;

		init_timer0();

		sei();

	while(1)
	{

		uchar control=0x08;
		
		int x=1000;

		if(PINA & 0x01)
		{
			num++;
		}


		if(PINA & 0x02)
		{
			num--;
		}

		if(num<0)
		num=9999;

		if(num>9999)
		num=0;
		
		
		tempNum=num;

		while(x>=1)
		{
			PORTB=control;
			printDigit(tempNum/x);
			_delay_ms(5);
			tempNum%=x;
			x/=10;
			control=control>>1;

		}


					
		

	}

}


			

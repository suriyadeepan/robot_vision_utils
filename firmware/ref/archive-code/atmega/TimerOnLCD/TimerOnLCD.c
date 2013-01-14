#define F_CPU 1000000UL 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include"lcd_16.h"

//#include <inttypes.h>
//#include"lcd_16.c"

unsigned int count=0;

int sec=0;
int min=0;
int hr=0;

char s[2];
char m[2];
char h[2];


void init_timer0()
{
	
	TCCR0=0x03;
	// set prescalar as 64

	TIMSK|=(1<<TOIE0);
	// for enabling overflow interrupt

	TCNT0=0;
	// init counter

	
}

void init_timer1()
{
	TCCR1B=0x03;
	TCNT1=0;
	TCCR1A=0x00;
	TIMSK=0b00000100;
	

}

ISR(TIMER1_OVF_vect)
{
	if(count==10)
	{
		sec++;
		count=0;

	}

	else
	count++;


}



int main()
{
	lcd_init(LCD_DISP_ON);
	lcd_puts("00:00:00");
	
	init_timer1();	

	sei();

	while(1)
	{

		//_delay_ms(130);

// should be done inside ISR
//			sec++;

	// printing seconds
		lcd_gotoxy(6,0);
		//iota(sec,s,2);
		//lcd_puts((char*)sec);
		sprintf(s,"%2d",sec);
		lcd_puts(s);

		if(sec>=59)
		{
			sec=0;
			min++;
		}


	// printing minutes
		lcd_gotoxy(3,0);
		//iota(min,m,2);
		sprintf(m,"%2d",min);
		lcd_puts(m);
		

		if(min>=59)
		{
			min=0;
			hr++;
		}


		// printing hours
		lcd_gotoxy(0,0);
		//iota(hr,h,2);
		sprintf(h,"%2d",hr);
		lcd_puts(h);

		if(hr>=59)
		{
			min=0;
			hr=0;
			sec=0;
		}


	}

}

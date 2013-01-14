#define F_CPU 1000000UL 

#include <avr/io.h>

#include <util/delay.h>

#include"lcd_16.h"

//#include <inttypes.h>
//#include"lcd_16.c"

int sec=0;
int min=0;
int hr=0;

char s[2];
char m[2];
char h[2];


int main()
{
	lcd_init(LCD_DISP_ON);
	lcd_puts("00:00:00");

	while(1)
	{

		_delay_ms(130);

		sec++;

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

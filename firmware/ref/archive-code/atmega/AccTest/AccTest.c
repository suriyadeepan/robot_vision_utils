#define F_CPU 1000000UL

#include <avr/io.h>


#include <util/delay.h>
#include "lcd_16.h"





typedef unsigned int uint;
typedef unsigned char uchar;


void adc_init()
{
	ADMUX=(1<<REFS0);
	// to set AREF => "01"...


	ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1);
	// enable ADC...
	// enable interrupt...
	// setting prescaler as 64 ==> "110"...
}

uint adc_read(uchar ch)
{

	//uchar ch=0x00;

	ADMUX|=ch;

	ADCSRA|=0x40;

	//wait for conversion...
	while(!(ADCSRA & 0x10));

	ADCSRA|=(1<<ADIF);

	return ADC;





}

char s[4];

int main()
{
	
	lcd_init(LCD_DISP_ON);
	lcd_gotoxy(0,0);
	lcd_puts("x:     y:     ");
	lcd_gotoxy(0,1);
	lcd_puts("z:     ");
	adc_init();



	while(1)
	{
		uint x=adc_read(0);
		uint y=adc_read(1);
		uint z=adc_read(2);
		
		lcd_gotoxy(2,0);
		sprintf(s,"%3d",x);
		lcd_puts(s);

		lcd_gotoxy(9,0);
		sprintf(s,"%3d",y);
		lcd_puts(s);

		lcd_gotoxy(2,1);
		sprintf(s,"%3d",z);
		lcd_puts(s);



		_delay_ms(800);

	}


}

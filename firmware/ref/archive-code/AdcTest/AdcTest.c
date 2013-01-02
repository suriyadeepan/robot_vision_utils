//#define FCPU 

#include <avr/io.h>
#include <util/delay.h>


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

int main()
{
	

	DDRD=0xff;

	

	adc_init();



	while(1)
	{
		uint val1=adc_read(0);


		//uchar temp=val1/100;

		//PORTD=temp;				

		//temp/=100;


		if(temp<8)
		PORTD=(0x01)<<temp;

		else
		PORTD=0xff;

	
		_delay_ms(200);

	}


}

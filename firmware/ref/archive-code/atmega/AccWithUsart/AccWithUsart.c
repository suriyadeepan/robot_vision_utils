#define F_CPU 16000000UL

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

void USARTInit(uint16_t ubrr_value)
{





   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);
   UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);


   UCSRB=(1<<RXEN)|(1<<TXEN);
   UCSRA|=(1<<RXC);


}

unsigned char USARTReadChar()
{


   while(!(UCSRA & (1<<RXC)));



   return UDR;
}

void USARTWriteChar(unsigned char data)
{

   while(!(UCSRA & (1<<UDRE)));
 

   UDR=data;
}


char cX[3],cY[3],cZ[3];

void USART_write_word(char var,char* buf)
{
	USARTWriteChar(var);
	USARTWriteChar(':');

	for(uchar i=0;i<3;i++)
	USARTWriteChar(buf[i]);

}



int main()
{
	

	adc_init();
	USARTInit(103);  
/*
		uint x0=adc_read(0);
		uint y0=adc_read(1);
		uint z0=adc_read(2);
*/
		uint x1=0;
			uint y1=0;
			uint z1=0;
		


	while(1)
	{
	
		uint x=adc_read(0)-x1;
		uint y=adc_read(1)-y1;
		uint z=adc_read(2)-z1;
		

		sprintf(cX,"%3d",x);
		// writing to USART...
		USART_write_word('x',cX);
		USARTWriteChar(' ');

		sprintf(cY,"%3d",y);
		// writing to USART...
		USART_write_word('y',cY);
		USARTWriteChar(' ');


		sprintf(cZ,"%3d",z);
		// writing to USART...
		USART_write_word('z',cZ);
		USARTWriteChar(13);
		USARTWriteChar(10);

		


		_delay_ms(500);

	}


}

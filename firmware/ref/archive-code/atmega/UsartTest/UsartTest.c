#include <avr/io.h>
#define F_CPU 16000000UL

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


int main()
{


	



   USARTInit(103);  




   while(1)
   {



	USARTWriteChar(USARTReadChar());
	
		

	}

}


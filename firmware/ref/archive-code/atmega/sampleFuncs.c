#include<avr/io.h>
//#include<sample.h>
#define F_CPU 1000000UL

/*
void assignPortB(unsigned char value)
{
	PORTB=value;
	

}*/

void setIO()
{

	DDRB=0xff;

}

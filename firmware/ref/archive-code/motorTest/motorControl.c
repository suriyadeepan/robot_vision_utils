
#include <avr/io.h>

void moveStraigt()
{

	PORTC=0b00001001;


}

void stop()
{

	PORTC=0b00001000; 


}

void leftTurn()
{
	PORTC=0b00000001; 

}

void rightTurn()
{
	PORTC=0b00001000;

}


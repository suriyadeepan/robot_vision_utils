#include <avr/io.h>
#include "SevenSegment.h"

void printDigit(int count)
{		
		switch(count)
		{
			case 0:
			PORTD=0xfc;
			break;

			case 1:
			PORTD=0b01100000;
			break;

			case 2:
			PORTD=0xda;
			break;


			case 3:
			PORTD=0xf2;
			break;

			case 4:
			PORTD=0b01100110;
			break;

			case 5:
			PORTD=0b10110110;
			break;

			case 6:
			PORTD=0b10111110;
			break;

			case 7:
			PORTD=0b11100000;
			break;


			case 8:
			PORTD=0b11111110;
			break;

			case 9:
			PORTD=0b11110110;
			break;

			default:
			PORTD=0x02;
			break;

		}	// end of switch case

}// end of printDigit() method

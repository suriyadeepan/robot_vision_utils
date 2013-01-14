#include <avr/io.h>
#include <util/delay.h>


int main()
{


		DDRD=0xff;
		DDRB=0xff;

		int count;

		PORTB=0xff;

	while(1)
	{

		//PORTC=0xff;

	
		for(count=0;count<10;count++)
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

		}	
			_delay_ms(900);
		}	
				



	}


}

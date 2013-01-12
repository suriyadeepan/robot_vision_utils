#include <avr/io.h>
//#include <util/delay.h>

//typedef unsigned char uchar;



int main()
{

	DDRC=0x00;
	DDRD=0xff;

	while(1)
	{

		PORTD=PINA&0x30;
		
		/*
		if((PINA&0b00010000)==1)
		PORTD=0xff;

		else
		PORTD=0x00;

		*/
	

		uchar leftIR=PINA&0b00010000; //PA4
		uchar rightIR=PINA&0b00100000; //PA5


		if(leftIR==1 && rightIR ==1)
		{
			moveStraight();

		}

		else if(leftIR==0 && rightIR ==0)
		{
			stop();
			_delay_ms(900);
			rightTurn();
						
		}

		else if(leftIR==1 && rightIR ==0)
		{
			stop();
			_delay_ms(900);
			rightTurn();
						
		}

		else if(leftIR==0 && rightIR ==1)
		{
			stop();
			_delay_ms(900);
			leftTurn();
						
		}


	}// end of while(1)
	

}// end of main()
	

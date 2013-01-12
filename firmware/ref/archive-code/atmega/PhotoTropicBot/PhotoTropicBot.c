#include <avr/io.h>

int main()
{

	while(1)
	{
		
		if(leftSensor==1 && rightSensor==1)
		moveStraight();

		else if(leftSensor==0 && rightSensor==0)
		stop();

		else if(leftSensor==0 && rightSensor==1)
		rightTurn();

		else
		leftTurn();


	}



}

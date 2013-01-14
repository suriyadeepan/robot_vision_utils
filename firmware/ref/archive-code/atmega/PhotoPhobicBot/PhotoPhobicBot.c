#include<avr/io.h>

int main()
{

	while(1)
	{
		if(leftSensor==1 && rightSensor==1)
		stop();

		else if(leftSensor==1 && rightSensor==0)
		rightTurn();

		else if(leftSensor==0 && rightSensor==1)
		leftTurn();

		else
		moveStraight();
		


	}


}

#include <avr/io.h>


int main()
{

while(1)
{
	if(leftIR==0 && rightIR==0)
	{
		moveStraight();

	}

	else if(leftIR==1 && rightIR==0)
	{
		rightTurn();

	}

	else if(leftIR==0 && rightIR==1)
	{
		leftTurn();

	}

	else
	stop();

}


}

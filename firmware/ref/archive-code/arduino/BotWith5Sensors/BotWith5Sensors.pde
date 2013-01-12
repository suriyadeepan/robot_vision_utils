void setup()
{
  for(int i=0;i<5;i++)
  pinMode(14+i,INPUT);
  
  analogWrite(5,0);
  //Right Motor
  
  analogWrite(10,0);
  //Left Motor
  
  
}

void turnLeft()
{
  analogWrite(10,0);
  analogWrite(5,200);

  
}


void turnRight()
{
  
  analogWrite(10,200);
  analogWrite(5,0);
  
  
    
}


void goStraight()
{
  analogWrite(10,230);
  analogWrite(5,230);
  
}


void loop()
{
 if(digitalRead(16==1))
  {
    //check for left or right turn
    
    if((digitalRead(15)==1)||(digitalRead(18)==0))
    {
       
        rightTurn();

      
    }

if((digitalRead(17)==1)||(digitalRead(14)==0))
    {
       
        leftTurn();
    }
    
    
  }
  
  else if(digitalRead(16)==0)
  {
    if((digitalRead(17)==1)||(digitalRead(14)==0))
    {
       
      leftTurn();
    }
    
    
    if((digitalRead(15)==1)||(digitalRead(18)==0))
    {
       
        rightTurn();
    }
    
    
if((digitalRead(15)==0)&&(digitalRead(18)==1)&&(digitalRead(17)==0)&&(digitalRead(14)==0))
    {
       
       goStraight();
    }
    
    
  }

/*turnLeft();
delay(5000);
turnRight();
delay(5000);
goStraight();
delay(5000);*/

  
}

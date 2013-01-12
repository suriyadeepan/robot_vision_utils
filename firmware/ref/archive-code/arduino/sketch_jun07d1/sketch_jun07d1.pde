
int i=0;

void setup()
{
  pinMode(4,INPUT);
  
  pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
      pinMode(13,OUTPUT);
  
}

void loop()
{

  if(digitalRead(4)==1 && i==0)
  {
    digitalWrite(11,1);
    i++;
  }
  
  else if(digitalRead(4)==1 && i==1)
  {
    digitalWrite(11,0);
    digitalWrite(12,1);
    i++;
  }
  
  else if(digitalRead(4)==1 && i==2)
  {
    digitalWrite(12,0);
    digitalWrite(13,1);
    i++;
  }
  
  else
  digitalWrite(13,0);
  
}




void setup()
{
  pinMode(4,INPUT);
  
  pinMode(11,OUTPUT);
 
  
}

void loop()
{
 
  if(digitalRead(4)==1)
  {
    digitalWrite(11,1);
 
  }
  
  
  else
  digitalWrite(11,0);
  
}

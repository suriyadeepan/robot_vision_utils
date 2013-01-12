void setup()
{
  
}

int i;

void loop()
{
  i=analogRead(3);
  
  if(i>500)
  {
  analogWrite(5,220);
  analogWrite(6,0);
      analogWrite(3,0);
  }
  
  if(i<500 && i>250)
  {
  analogWrite(6,220);
  analogWrite(5,0);
    analogWrite(3,0);
  }
   
   
    if(i<250)
  {
  analogWrite(3,220);
  analogWrite(5,0);
    analogWrite(6,0);
  }
}

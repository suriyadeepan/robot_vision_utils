void setup()
{
  analogWrite(6,0);
  analogWrite(11,0);
}

void loop()
{
  analogWrite(6,0);
    analogWrite(11,200);
  delay(7000);
  
  analogWrite(11,0);
  analogWrite(6,200);
  delay(7000);
 
}

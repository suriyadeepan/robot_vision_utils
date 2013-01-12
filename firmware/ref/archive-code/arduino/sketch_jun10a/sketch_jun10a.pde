void setup()
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  
}
void loop()
{
  
  Serial.print(analogRead(14));
  Serial.println(analogRead(15));
  if(analogRead(14)>analogRead(15))
{
  digitalWrite(11,1);
  digitalWrite(12,0);
  
}

else
{
  
  digitalWrite(11,0);
  digitalWrite(12,1);
  
}
}
  
  

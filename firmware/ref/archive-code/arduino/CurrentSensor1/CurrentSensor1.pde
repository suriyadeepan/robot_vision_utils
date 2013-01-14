void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
  
  //switch on supply
  digitalWrite(5,1);
  
 Serial.println((analogRead(14)*5)/1023);
 
 delay(2000);
 Serial.println((analogRead(14)*5)/1023);
 
 digitalWrite(5,0);
 delay(2500);
  
  
  
}

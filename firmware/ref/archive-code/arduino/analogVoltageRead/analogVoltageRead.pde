void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  
  int val=analogRead(14);
  
//  if(val>0&&val<1000)
  Serial.println(val);
  delay(100);
    
}

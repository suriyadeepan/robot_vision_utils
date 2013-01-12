void setup()
{
   pinMode(7,INPUT);
   digitalWrite(7,1);
   Serial.begin(300); 
  
}

int i=0;
void loop()
{


  
if(digitalRead(7)==0)
{
  while(digitalRead(7)==0);
  i++;
//  delay(100);
   Serial.println(i);
 
}
  
 
  
  
}

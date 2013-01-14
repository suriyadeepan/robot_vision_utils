void setup()
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
}

void loop()
{
  for(int i=0;i<10;i++)
{  digitalWrite(11,HIGH);
  delay(150);
   digitalWrite(11,0);
   delay(150);
}


  for(int i=0;i<10;i++)
{  digitalWrite(12,HIGH);
  delay(150);
   digitalWrite(12,0);
   delay(150);
}


  for(int i=0;i<10;i++)
{  digitalWrite(13,HIGH);
  delay(150);
   digitalWrite(13,0);
   delay(150);
}



}
  

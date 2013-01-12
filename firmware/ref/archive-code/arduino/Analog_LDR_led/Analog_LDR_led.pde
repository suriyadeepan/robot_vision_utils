void setup()
{
  pinMode(12,OUTPUT);
  
}

int i;
void loop()
{
  i=analogRead(3);
  
  if(i>300)
  digitalWrite(12,1);
  
  else
  digitalWrite(12,0);
  
 
}

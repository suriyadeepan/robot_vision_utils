  boolean a;
  int i=0;
void setup()
{
        pinMode(12,OUTPUT);

            
}





void loop()
{
  if(i%2==0)
  a=1; 
 
  else
  a=0;
  
  
  
  digitalWrite(12,a);
  delay(2000);
  i++;
    
  
  
  
}

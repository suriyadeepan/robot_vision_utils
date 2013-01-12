  boolean a=0;

void setup()
{
        pinMode(12,OUTPUT);

            
}


boolean change(boolean n)
{
  if(n==1)
  n=0;
  
  else
  n=1;
}



void loop()
{
  
  a=change(a);
  Serial.println(a);
  
  
//  digitalWrite(12,a);
  //delay(2000);
  
    
  
  
  
}

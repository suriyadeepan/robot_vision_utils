void setup()
{
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  
}


void loop()
{
  for(int i=0;i<4;i++)
  {
int a=i%2;
 int b=(i/2)%2;  
   
   digitalWrite(0,a);
    digitalWrite(1,b);
    
    if(digitalRead(10)==1)
    {
      digitalWrite(11,1);
      

      while(digitalRead(10)==1);
      Serial.println(i);
    }
    
    digitalWrite(11,0);
    
      
    

   
  
  }
  
  
}
  
  
  
  

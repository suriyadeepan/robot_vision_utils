
void setup()
{
   pinMode(7,INPUT);
   pinMode(12,OUTPUT);
   digitalWrite(7,1); 
  
}

int flag=0;

void loop()
{
  
  if(digitalRead(7)==0)
  {
  if(flag==1)
  {
  //    while(digitalRead(7)==0);
    digitalWrite(12,1);
      while(digitalRead(7)==0);
    flag=0;
  }
  
  else if(flag==0)
  {
//  while(digitalRead(7)==0);
  digitalWrite(12,0);
  while(digitalRead(7)==0);
  flag=1;
  }
   
  }
    

  
}

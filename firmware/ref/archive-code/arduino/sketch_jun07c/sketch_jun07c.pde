


void setup()
{
  pinMode(11,OUTPUT);
    
  
  
  pinMode(8,INPUT);
  digitalWrite(8,1);
}
  
  


void loop()
{
  
  int flag=0;
  

  if(digitalRead(8)==0)
  {
    while(digitalRead(8)==0);
    
    digitalWrite(11,1);
    

       
       flag=1;
    
  
  }
  
   
  
    
    if(flag==1 && digitalRead(8)==0)
    {
    while(digitalRead(8)==0);
    digitalWrite(11,0);
    }
  
  
 



} 

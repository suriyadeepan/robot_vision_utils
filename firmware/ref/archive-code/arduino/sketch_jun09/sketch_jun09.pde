void setup()
{
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,INPUT);
pinMode(11,OUTPUT);
}

int i=0;
void loop()
{
if(i>3)
i=0;


  
int  quo=i/2;
int   rem=i%2;
boolean a=0,b=0;

  if(quo==0)
  {
    b=0;
    a=rem;
  }
  
  else
  {
    b=1;
    a=rem;
  }
   
   digitalWrite(8,b);
    digitalWrite(9,a);
    

    
    if(digitalRead(10)==1)
    digitalWrite(11,1);
    
    else
    digitalWrite(11,0);
    
        delay(2000);
   
  
  i++;
}

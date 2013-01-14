void setup()
{
   pinMode(7,INPUT);
   pinMode(12,OUTPUT);
   digitalWrite(7,1); 
  
}

boolean switchCheck()
{
  boolean temp;
     if(digitalRead(7)==0)
  {


  //    while(digitalRead(7)==0);
    digitalWrite(12,1);
      while(digitalRead(7)==0);

  } 
}




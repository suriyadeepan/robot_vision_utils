int remote()
{
  int i=0,arr[12],val=0;
 
  
  if(pulseIn(15,0)>2000)
  {
    for(i=0;i<12;i++)
    {
      arr[i]=pulseIn(15,0);
      
    }
    
    for(i=0;i<12;i++)
    {
      if(arr[i]>1000)
      {
        val=val+(1<<i);
      }
    }
    
      Serial.println(val);
  }
  

  
return  val;

}


void setup()
{
  Serial.begin(9600);
  pinMode(15,INPUT);
/*  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);  */
}

void loop()
{
  int checkVal=remote();
  
  if(checkVal)
  Serial.println(checkVal);
  
  
  
  
  
  
}
  



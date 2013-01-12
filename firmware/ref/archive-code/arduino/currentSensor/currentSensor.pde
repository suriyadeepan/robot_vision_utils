void setup()
{
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}


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
    
//      Serial.println(val);
  }
  

  
return  val;

}

void loop()
{
  
if(remote()==128)
digitalWrite(10,1);

else if(remote()==129)
digitalWrite(10,0);

Serial.println((analogRead(14)*5)/1023);

}

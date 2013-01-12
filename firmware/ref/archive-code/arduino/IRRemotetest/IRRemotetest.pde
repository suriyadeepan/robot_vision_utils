


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
    
 
  }
  

  
return  val;

}

void setup()
{
  pinMode(12,OUTPUT);
  pinMode(15,INPUT);
}

void loop()
{
  int val=remote();
  
  if(val)
  {

  digitalWrite(12,1);
  }
  
  else
  digitalWrite(12,0);

  

// Up --> 244
// Down --> 245
// Left --> 180
// Right --> 179
// Off --> 149
// Right1 --> 224
// Left1 --> 2979

  
}



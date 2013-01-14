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
  analogWrite(5,0);

  analogWrite(11,0);
  
  pinMode(15,INPUT);
  
    pinMode(16,INPUT);
  pinMode(18,INPUT);
}

void loop()
{
  int val=remote();
  
  if(val)
  {
      if(val==244)
      {
        analogWrite(5,200);
        analogWrite(10,200);
        analogWrite(6,0);
        analogWrite(11,0);
        
      }
      
      else if(val==245)
      {
        analogWrite(6,200);
        analogWrite(11,200);        
                analogWrite(5,0);
        analogWrite(10,0);
      }
      
      else if(val==180)
      {

        
        analogWrite(6,0);
        analogWrite(11,0);
        
        analogWrite(5,0);
        analogWrite(10,200);
        
      }
      
      else if(val==179)
      {
        
                analogWrite(5,200);
        analogWrite(10,0);
        
                analogWrite(6,0);
        analogWrite(11,0);
        
      }        
      
      
      else if(val==2979)
      {
        
                analogWrite(6,200);
        analogWrite(10,200);
        
                analogWrite(5,0);
        analogWrite(11,0);
        
      }        
      
      
      else if(val==224)
      {
        
                analogWrite(5,200);
        analogWrite(11,200);
        
                analogWrite(6,0);
        analogWrite(10,0);
        
      }              
        
    
    else if(val==149)
    {
        analogWrite(5,0);
        analogWrite(10,0);      
              analogWrite(6,0);
        analogWrite(11,0);      
      
      
    }
  }
    
    
    
  }
  
  
  
  

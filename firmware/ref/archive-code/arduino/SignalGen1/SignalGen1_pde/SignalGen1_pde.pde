void setup()
{
  
  pinMode(14,OUTPUT);
  
}

void transmit(int val)
{
  int arr[12],i=0;
  while(val>0)
  {
    arr[i]=val%2;
    val/=2;
    i++;
  }
  
  for(i;i<12;i++)
  arr[i]=0;
  
  pulse(96);
  
  for(i=0;i<12;i++)
  {
    if(arr[i])
    pulse(48);
    
    else
    pulse(24);
  }
  
}

void pulse(int dur)
{
  for(int j=0;j<dur;j++)
  {
    digitalWrite(14,1);
    delayMicroseconds(12);
    digitalWrite(14,0);
    delayMicroseconds(12);
  }
  
  delayMicroseconds(600);
}

void loop()
{

  transmit(149);

  
  delay(2000);
  
  
  


 
}
    

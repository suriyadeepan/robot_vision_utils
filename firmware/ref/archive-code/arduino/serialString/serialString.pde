void setup()
{
  Serial.begin(9600);
}

char str[10];
int i;

void loop()
{
  int j=0;
  
  while((i=Serial.read())!=-1)
  {
    
      str[j]=char(i);
      j++;
      
      delay(5);
    //but why
  }
  
  
  if(j!=0)
  Serial.println(str);
  
  
}

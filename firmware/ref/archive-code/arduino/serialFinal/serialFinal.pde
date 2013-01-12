void setup()
{
  Serial.begin(300);
}

int i;
int data;

void loop()
{
  data=0;
  
while((i=Serial.read())!=-1)
  {
    if(i<58)  // Numerical
    {
    i=i-48;
    data=(data*10)+i;
    Serial.print(i);
    Serial.print(" ");
    Serial.println(data);
    }
    
    else  // Char
    {
      
      
    }

  }
  
  if(data!=0)    
  {Serial.print(" Final ");
  Serial.println(data);
  }

analogWrite(3,data);
delay(5000);

  

  
}

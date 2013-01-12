void setup()
{
  Serial.begin(300);
}

int i;
int s;

void loop()
{
  
  if((i=Serial.read())!=-1)
  {
    s=int(i);;
    Serial.print(s);
    
    
//    delay(500);
  }
 else
Serial.println(""); 
}

void setup()
{
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  
}

void loop()
{
  //00
  digitalWrite(0,0);
    digitalWrite(1,0);
    delay(3000);
  
    //01
  digitalWrite(0,0);
    digitalWrite(1,1);
        delay(3000);
  
  
    //10
  digitalWrite(0,1);
    digitalWrite(1,0);
        delay(3000);
  
  
    //11
  digitalWrite(0,1);
    digitalWrite(1,1);
        delay(3000);
  
}
  
  
  
  

//hardware interrupts are available only in pins 1 and 2

void setup()
{
  pinMode(2,INPUT);
  pinMode(5,INPUT);
  pinMode(10,INPUT);
  attachInterrupt(1,follow,RISING);
    analogWrite(11,0);
  analogWrite(6,0);
}

void follow()
{
  digitalWrite(5,0);
  while(digitalRead(2)==1)
  {
    digitalWrite(10,1);

  }
}

void loop()
{
  
  digitalWrite(5,1);
  digitalWrite(10,0);

  
}





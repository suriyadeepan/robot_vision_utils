void setup()
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  
}

void loop()
{
  digitalWrite(3,1);
  delay(500);
    digitalWrite(3,0);
    digitalWrite(5,1);
  delay(500);
    digitalWrite(5,0);
    digitalWrite(6,1);
  delay(500);
  digitalWrite(6,0);
  
}

  

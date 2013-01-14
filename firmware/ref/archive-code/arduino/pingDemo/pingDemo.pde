void setup()
{
 
   Serial.begin(9600);
   
  
}

void loop()
{
  long duration,inches;
   pinMode(7,OUTPUT);
   digitalWrite(7,0);
  delayMicroseconds(2);
  digitalWrite(7,1);
  delayMicroseconds(5);
  digitalWrite(7,0);
  pinMode(7,INPUT);
  duration = pulseIn(7,1);
  
  Serial.println(duration);
  delay(100);
  
}

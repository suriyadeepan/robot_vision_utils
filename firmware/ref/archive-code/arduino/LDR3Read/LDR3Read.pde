void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  Serial.print(analogRead(14));
  Serial.print("   ");
  Serial.print(analogRead(15));
    Serial.print("   ");
  Serial.print(analogRead(16));
    Serial.println("   ");
    delay(1000);
  
  
  
}



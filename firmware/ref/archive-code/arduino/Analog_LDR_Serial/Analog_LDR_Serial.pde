void setup()
{
  Serial.begin(300);
}

int i;
void loop()
{
  i=analogRead(3);
  Serial.println(i);
  delay(50);
}

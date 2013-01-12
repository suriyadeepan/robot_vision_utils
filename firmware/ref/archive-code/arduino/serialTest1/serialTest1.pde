void setup()
{
  Serial.begin(9600);
  
}

int i=1;

void loop()
{
  Serial.print("Line  ");
  Serial.println(i);
  i++;  
  delay(500);

}

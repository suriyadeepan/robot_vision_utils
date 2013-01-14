void setup()
{
  DDRD=B11111111;
  PORTD=B00000000;
  delay(1000);
}

void loop()
{
  
  PORTD=B11000000;
  delay(1000);
  
  PORTD=B00000110;
  delay(1000);  
  PORTD=B10100000;
    delay(1000);
  PORTD=B10110000;
         delay(1000);
  PORTD=B10011001;
    delay(1000);
  PORTD=B10010000;
    delay(1000);
  PORTD=B10000010;
    delay(1000);
       //
}

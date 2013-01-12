#include <LiquidCrystal.h>
LiquidCrystal lcd(4,7,8,9,12,13);
void setup()
{
  lcd.begin(16,2);
  lcd.print("HELLO");
}
int i;
void loop()
{
  for(i=1;i<16;i++)
  {
lcd.setCursor(i,1);
lcd.print("tery");
delay(1000);
lcd.clear();
delay(1000);
  }
}
  

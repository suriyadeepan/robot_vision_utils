#include <LiquidCrystal.h>
LiquidCrystal lcd(4,7,8,9,12,13);
void setup()
{
  lcd.begin(16,2);
  lcd.print("Hello");
 
}

void loop()
{

  delay(2000);
  lcd.scrollDisplayLeft();
  delay(2000);
  
  
  
}

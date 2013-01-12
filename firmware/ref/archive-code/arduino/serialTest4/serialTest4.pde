void setup()
{
   pinMode(2,INPUT);

   Serial.begin(115200); 
  
}

int i=0;
void loop()
{


  
if(digitalRead(2)==1)
{

  i++;
  
  
//  delay(100);
   Serial.println(i);
 
}
  
 
  
  
}

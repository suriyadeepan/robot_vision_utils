void setup()
{
  Serial.begin(300);
}

int i;
char temp;
void loop()
{
   if((i=Serial.read())!=-1)
   {
     
      temp=char(i);
     
   }
   
   switch(temp)
   {
     case 'R':
       analogWrite(5,220);
       analogWrite(3,0);
       analogWrite(6,0);              
       break;
       
     case 'G':
       analogWrite(6,220);

       analogWrite(5,0);
       analogWrite(3,0);       
       break;
       
     case 'B':
       analogWrite(3,220);
       analogWrite(6,0);
       analogWrite(5,0);
       break;
       
       
   }
   
   delay(250);
  
}

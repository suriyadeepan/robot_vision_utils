void setup()
{
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  int val1=analogRead(14);
  int val2=analogRead(15);
  int val3=analogRead(16);
  
  
   Serial.print(analogRead(14));
  Serial.print("   ");
  Serial.print(analogRead(15));
    Serial.print("   ");
  Serial.print(analogRead(16));
    Serial.println("   ");
    delay(1000);
  
  
  
  int avg=(val1+val2+val3)/3;
  
  if(avg>970)
  {
  //greatest of three numbs

  
  if(val1<val2 && val1<val3)
  {

   
       digitalWrite(11,1); 
    digitalWrite(12,0);     
    digitalWrite(13,0); 
  }
  
  else if(val1>val2 && val2<val3)
  {

   
         digitalWrite(11,0); 
    digitalWrite(12,1);     
    digitalWrite(13,0); 
  }

else
  {

             digitalWrite(11,0); 
    digitalWrite(12,0);     
    digitalWrite(13,1); 
  }  }
  


  }
  

  

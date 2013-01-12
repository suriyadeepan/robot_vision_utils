void setup()
{
  Serial.begin(9600);
}

char str[10];
int i;

void loop()
{
  int j=0;
  
  while((i=Serial.read())!=-1)
  {
    
      str[j]=char(i);
      j++;
      
      delay(5);
    //but why
  }
  
  
  if(j!=0)
  {
    Serial.println(str);
  


  for(int k=0;k<strlen(str);k++)
  {
    char code;
    
      if(str[k]>64 && str[k]<96)
      {
          code=str[k];
           
      }
      
    int intensity=0;
    
    int arr[4];
           
   for(int a=0;a<3;a++)
   {
    arr[a]=str[k+a+1]-48; 
//    Serial.println(arr[a]);
    intensity=(intensity*10)+arr[a];
   }
   


  if(intensity>0 && intensity<255)
  {
  switch(code)
  {
     case 'R':
      analogWrite(5,intensity);
       analogWrite(3,0);
       analogWrite(6,0);      
      Serial.println(intensity);
      delay(5000);
       break;
       
     case 'B':
       analogWrite(3,intensity);
       analogWrite(5,0);
       analogWrite(6,0);       
       Serial.println(intensity);
             delay(5000);
       break;
       
     case 'G':
       analogWrite(6,intensity);
       analogWrite(3,0);       
       analogWrite(5,0);
       Serial.println(intensity);
             delay(5000);
         break;
      
  }}
   
  }
  } 
  
}

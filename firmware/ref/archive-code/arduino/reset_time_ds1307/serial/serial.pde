void setup()
{
  Serial.begin(9600);
}

int i;
int data;

void loop()
{

  
while((i=Serial.read())!=-1)
  {
    Serial.println(i);
    delay(10);
  }
}


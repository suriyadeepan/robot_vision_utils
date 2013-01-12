void setup()
{


            pinMode(11,OUTPUT);
            pinMode(12,OUTPUT);
            pinMode(13,OUTPUT);
}

boolean change(boolean n)
{
  if(n==1)
  n=0;
  
  else
  n=1;
}



void loop()
{
  
boolean a=0,b=0,c=0;
  
for(int k=0;k<2;k++)
{
for(int j=0;j<2;j++)
{
for(int i=0;i<2;i++)
{
//System.out.println(a+""+b+""+c);
digitalWrite(11,a);
digitalWrite(12,b);
digitalWrite(13,c);

delay(1000);

c=change(c);
}
			
b=change(b);
}
a=change(a);
}
}

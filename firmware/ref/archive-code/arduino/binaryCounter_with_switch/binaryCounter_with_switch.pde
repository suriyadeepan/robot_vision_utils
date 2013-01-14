void setup()
{


            pinMode(11,OUTPUT);
            pinMode(12,OUTPUT);
            pinMode(13,OUTPUT);
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

//c=change(c);
if(c==0)
c=1;

else
c=0;
}
			
//b=change(b);

if(b==0)
b=1;

else
b=0;

}
//a=change(a);


if(a==0)
a=1;

else
a=0;
}
}

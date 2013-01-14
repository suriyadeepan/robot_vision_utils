void setup()
{
  pinMode(7,INPUT);
  digitalWrite(7,1);
  
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  

}



int a=0,b=0,c=0;
int num=0;
void loop()
{
  if(num>7)
  num=0;  

 
 
  //Conversion algorithm
 
 int quo=num/2;
	int rem=num%2;
	
	if(quo==0)
	{
	
		c=b=0;
		a=rem;
	}
	
	
	
	
	if(quo==1)
	{
		c=0;
		b=1;
		a=rem;
	}
	
	if(quo==2)
	{
		c=1;
                b=0;
		a=rem;
	}
	
	if(quo==3)
	{
		c=1;
                b=1;
		a=rem;
	}

//Increment
num++;
 
 
 //show
 
 digitalWrite(11,boolean(c));
 digitalWrite(12,boolean(b));
 digitalWrite(13,boolean(a));
 
 delay(2000);
 
 
  
}

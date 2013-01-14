void setup()
{
  pinMode(7,INPUT);
  pinMode(8,INPUT);

  digitalWrite(7,1);
    digitalWrite(8,1);

  
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  

}

//9791010963

int a=0,b=0,c=0;
int num=0;
void loop()
{
  if(num>7)
  num=0;  
  
  if(num<0)
  num=7;

 
 
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


 
 
 //show
 
 digitalWrite(11,boolean(c));
 digitalWrite(12,boolean(b));
 digitalWrite(13,boolean(a));
 
 

 delay(500);

 
 
  //Increment
  
//    while(digitalRead(7)==1);
    while((digitalRead(8)==1)&&(digitalRead(7)==1));
    
    if(digitalRead(7)==0)
    num++;

  
  
  //decrement
  if(digitalRead(8)==0)
  {
   
//     while(digitalRead(8)==0);
    num--; 
  }
 
 
  
}

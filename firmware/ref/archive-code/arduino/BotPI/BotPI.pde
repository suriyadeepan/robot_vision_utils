int avg=110;
int left=0,right=0;
int kon=8;
int weights[5]={-18,-5,0,5,18};
int error=0;
int sensorVal[5];
int q[50];
int I,Imax=200,Imin=50 ;
int count=0;




void setup()
{
  pinMode(14,INPUT);
  for(int i=0;i<4;i++)
  pinMode(i+16,INPUT);
  
  analogWrite(5,0);


  analogWrite(10,0);
  
}




void integral()
{
   if(count<50)
   {
     q[count]=error;
     count++;
   }
   
   else
   {
     for(int i=0;i<50;i++)
     q[i]=q[i+1];
     
     q[49]=error;
     
     I=0;
   
   
   for(int i=0;i<50;i++)
   {
     if(q[i]>0)
     I=I+q[i];
     else
     I=I-q[i];
   }
   
   if(I>Imax)
   avg=avg-3;
   
   else if(I<Imin)
   avg=avg+8;
   
   
   
   
   if(avg>180)
   avg=180;
   
   else if(avg<60)
   avg=60;
   
   }
}
     
     
       

void sense()
{
  // read all senser values (digital) and store them in an array
  
  sensorVal[0]=digitalRead(14);
  
  for(int i=0;i<4;i++)
  sensorVal[i+1]=digitalRead(16+i);
  
}

void proportional()
{
  // error value proportional to sensor value and weights is calculated
  
  error =0;
  
  for(int i=0;i<5;i++)
  error+=sensorVal[i]*weights[i];
  
}


void motor()
{
  // calculate motor speeds (left and right) from the error value 
  left = avg-(error*kon);
  right=avg+(error*kon);
  
  if(left>255)
  left=255;
  
  else if(left<40)
    left = 40;
    
    if(right>255)
    right=255;
    
    else if(right<40)
    right=40;
    
    analogWrite(5,left);
    analogWrite(10,right);
}

void loop()
{
  sense();
  proportional();
  integral();
  motor();
}
    
    

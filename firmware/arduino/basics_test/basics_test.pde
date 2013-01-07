
void setup()
{
     Serial.begin(9600); 
     
     // set pins connected to motors 
     //  as output
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(18, OUTPUT);
    
    delay(3000);
    
    while (Serial.read() > 0)
    delay(1);
      

     
}


char received[5];
char cmd[3];



void loop()
{
  

  
    received[0] = Serial.read ();
    
    // get the string of size '5' in
    //  in a char array
    if(received[0] == '$' ) 
    {

    received[1] = Serial.read() ;
    received[2] = Serial.read() ;
    received[3] = Serial.read() ;
    received[4] = Serial.read() ;

    }
  
  // check if its in the right format
  if(received[0] == '$' && received[4] == '~')
  {
     cmd[0]=received[1]; 
     cmd[1]=received[2];
     cmd[2]=received[3];
     
    
    
  

// FORWARD
if ( compareStrs(cmd,"fwd")) 
{

 Serial.println("FORWARD");
 forward();
 delay(300);

}

// BACKWARD
else if (compareStrs(cmd,"bwd"))
{

 Serial.println("BACKWARD");
 backward();
 delay(300);


}

// LEFT
else if (compareStrs(cmd,"lft"))
{

Serial.println("LEFT");
 left();
 delay(300);

  
}

// RIGHT
else if (compareStrs(cmd,"rgt"))
{
  Serial.println("RIGHT");
 right();
 delay(300);

}

// Default
else
{
   Serial.println("default"); 
    stop_all();
    delay(300);

}



 
  } // end of if

// a small delay
delay(100);  

stop_all();
  
}// end of loop() method



boolean compareStrs(char str1[],char str2[])
{
  for(int i=0;i<3;i++)
  {
     if(!(str1[i] == str2[i])) 
     {
       return false;
             
     }
    
  }
  
  return true;
  
}


// methods for motor direction control

void stop_all()
{

digitalWrite(15, 1 );
digitalWrite(16,1 );

digitalWrite(17, 1 );
digitalWrite(18,1 );
}

void rmotor_forward()
{

digitalWrite(15, 1 );
digitalWrite(16,0 );

}

void rmotor_backward()
{

digitalWrite(15, 0 );
digitalWrite(16,1 );

}

void lmotor_forward()
{

digitalWrite(17, 1 );
digitalWrite(18,0 );

}

void lmotor_backward()
{

digitalWrite(17, 0 );
digitalWrite(18, 1 );

}

void forward()
{
lmotor_forward();
rmotor_forward();

}

void backward()
{

lmotor_backward();
rmotor_backward();

}

void right()
{
lmotor_forward();
rmotor_backward();

}

void left()
{
lmotor_backward();
rmotor_forward();

}



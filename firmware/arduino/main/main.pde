
char cmd[5];

void setup ()
{
Serial.begin(9600);

}

void loop ()
{

    cmd[0] = Serial.read ();
    
    if(cmd[0] == '$' ) 
    {

  cmd[1] = Serial.read() ;
  cmd[2] = Serial.read() ;
  cmd[3] = Serial.read() ;
  cmd[4] = Serial.read() ;

    }
  
  


if ( strncmp ( cmd, "$LMF", 5 ) == 0 ) {

//forward ();

}
else if ( strncmp ( cmd, "$LMB", 5 ) == 0 ){

//backward ();

}



}

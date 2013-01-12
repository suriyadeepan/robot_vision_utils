




#define LED3 11    // pin of LED3
#define LED2 12   // pin of LED2
#define LED1 13   // pin of LED1

int x1=0;   // state of LED1
int x2=0;   // state of LED2
int x3=0;   // state of LED3

//there are auxiliary variables
int new_x1=0;  // used to store new LED1 state
int new_x2=0;  // used to store new LED2 state
int new_x3=0;  // used to stpre new LED3 state

void setup(){
  
  pinMode(LED1,OUTPUT);    //set all pin in OUTPUT mode
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  
}


void loop(){
  
  delay(1000);   // wait 1s before to begin every cicle
                 // this is useful because if there isnt any
                 // delay we will not see anything
                
  if  (!x3) new_x3=1; // boolean function of the state of third LED  
  else new_x3=0;      //if it's not verified x3 is 0
   if( (x2 && !x3) || (!x2 && x3)) new_x2=1; //same thing for second state
  else new_x2=0;
  if( (!x1 && x2 && x3) || (x1 && !x3) || ( x1 && !x2)) new_x1=1; //same thing for the first state
  else new_x1=0;

  
  x1=new_x1;  //now new value can be stored in the state variables
  x2=new_x2;  
  x3=new_x3;  
  
  //turn ON or turn OFF  LED 1 2 3
  if(x1==1) digitalWrite(11,HIGH);
  else digitalWrite(LED1,LOW);
  if(x2==1) digitalWrite(12,HIGH);
  else digitalWrite(LED2,LOW);
  if(x3==1) digitalWrite(13,HIGH);
  else digitalWrite(LED3,LOW);
  
} 


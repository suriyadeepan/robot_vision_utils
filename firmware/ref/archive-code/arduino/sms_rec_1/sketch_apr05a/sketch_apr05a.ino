// gsm sms receive program [control for particular phone-number only]

#include <string.h>                                      /* for calling string functions */
#include <math.h>
unsigned int flag_0,                                     /* flag_0 to maintain status of program's process */
             flag_1,                                     /* flag_0 to maintain status of program's process */
             temp,                                       /* temporary for pointing and counting program's process */
             serial_rx_data,                             /* serial receive data [transmitted by gsm modem] */
             count = 0;                          /* phone-number flag for validity */

char cmd_buffer[250],                                    /* to store at commands buffer */
     new_sms_indication[15],                             /* to store 12 bytes of new sms incoming indication */
     phone_number[14], data[50], add[10];                                   /* to store phone-number [this number only can control led] */

void setup()
{
  pinMode(11, OUTPUT);                                   // led used for turn on/off by sms
  digitalWrite(11, LOW);                                 // turn off the led as default
  pinMode(12, OUTPUT);                                   // led used for indication when new sms incoming
  digitalWrite(12, LOW);                                 // new sms incoming indication led off
  pinMode(13, OUTPUT);                                   // led used for valid indication of user 
  digitalWrite(13, LOW);                                 // valid indication of user led off
  Serial.begin(9600);                                    // enabling uart for gsm modem interfacing
  delay(500);                                            // calling delay
  Serial.print("AT\r\n");                                // sending at command to detected gsm modem connected and its ready
  delay(500);                                            // calling delay
  Serial.print("ATE0\r\n");                              // turn-off echo character [0=disable, 1=enable]
  delay(500);                                            // calling delay
  Serial.print("at+cmgf=1\r\n");                         // setting sms format as text [1=text, 0=pdu]
  delay(500);                                            // calling delay
  Serial.print("at+cnmi=1,1,0,0,0\r\n");                 // setting new sms message indications as mode=1, mt=1, bm=0, ds=0, bfr=0 [ref: at cmds datasheet]
  delay(500);                                            // calling delay
  flag_0 = 0;                                            // flag_0 setted to 0 as initial
  flag_1 = 0;                                            // flag_1 setted to 0 as initial
  temp = 0;                                              // temp setted to 0 as initial
  strcpy(new_sms_indication, "+CMTI: \"SM\",");          // storing new sms incoming indication for comparing when gsm modem receive sms
  strcpy(phone_number, "+919445677997");                 // storing phone-number [this number only can control led]
}

void recs()
{
  for(int temp = 0 ; temp < 245; temp ++ )
  {
    serial_rx_data = Serial.read();
    delay(10);
    cmd_buffer[temp] = serial_rx_data;
  }
  Serial.write(cmd_buffer);
  while(1);
  delay(100);
}

void loop()
{
  
 if(Serial.available() > 0)
 {
  digitalWrite(13,1);
  for(int temp = 0 ; temp < 18; temp ++ )
  {
    serial_rx_data = Serial.read();
    delay(10);
    cmd_buffer[temp] = serial_rx_data;
    if(cmd_buffer[temp] == new_sms_indication[flag_0])
    {
        flag_0 ++;
        digitalWrite(12,1); delay(100); digitalWrite(12,0);delay(100);
    }
  }
    if(flag_0==12)
    {
        temp = 14;
        count = 0;
        for(; cmd_buffer[temp] >= '0' && cmd_buffer[temp] <= '9'; count ++, temp++ ) 
           add[count] = cmd_buffer[temp];
        add[count] = '\0';
        flag_1 = 1;
        flag_0 = 0;
        strcpy(new_sms_indication,"+CMTI: \"SM\",");
    } 
  }
   if(flag_1==1)
  {
   
    Serial.print("AT+CMGR=");
    for(int count = 0 ; add[count]!='\0'; count++)
      Serial.write(add[count]);
    digitalWrite(13,0);
    Serial.print("\r\n");
    //Serial.print(13);
    delay(50);
    flag_1=2;
  }
  if(flag_1==2)
  {
    int count = 0, ch = 0;
    recs();
    digitalWrite(11,1);
    Serial.write(cmd_buffer); 
    for(temp = 0 ; cmd_buffer[temp]!='+'; temp++);
      if(cmd_buffer[temp++] == '+') ;
    
    for(; cmd_buffer[temp]!='\r'; temp ++);
      temp++;
    for(; cmd_buffer[temp] != 'O' && cmd_buffer[temp+1] != 'K';temp ++)
      data[ch++] = cmd_buffer[temp];
    Serial.println("____");
    Serial.write(data); 
    flag_1=3;
  }
  if(flag_1==3)
  {
      flag_0 = flag_1 = count = temp = 0;
  }
  delay(100);
 }


// tested ok


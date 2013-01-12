// gsm call program

#include <string.h>                                     /* for calling string functions */

unsigned int buffer_index,                              /* for at command buffer pointing */
             serial_rx_data,                            /* serial receive data [transmitted by gsm modem] */
             call_flag,                                 /* call processing flag */
             temp_0,                                    /* temporary 0 for pointing and counting */
             temp_1;                                    /* temporary 1 for pointing and counting */

char cmd_buffer[250],                                   /* to store at commands buffer */
     phone_number[14],                                  /* to store phone-number */
     call_status_0[16],                                 /* unattended [no answer] call for comparing when call unattended */
     call_status_1[16];                                 /* busy [reject] call for comparing when call unattended */

void setup()
{
  pinMode(7, INPUT);                                    // make a call switch 7
  digitalWrite(7, HIGH);                                // make a call high on switch 7
  pinMode(8, INPUT);                                    // cancel current call switch 8
  digitalWrite(8, HIGH);                                // cancel current call high on switch 8

  pinMode(11, OUTPUT);                                  // make a call led indicator
  digitalWrite(11, LOW);                                // make a call led indicator turn-off
  pinMode(12, OUTPUT);                                  // unattended [no answer] or busy [reject] call led indicator
  digitalWrite(12, LOW);                                // unattended [no answer] or busy [reject] call led indicator turn-off
  pinMode(13, OUTPUT);                                  // cancelling or busy [reject] call led indicator
  digitalWrite(13, LOW);                                // call cancelling or busy [reject] call indicator led turn-off

  Serial.begin(9600);                                   // enabling uart for gsm modem interfacing
  delay(500);                                           // calling delay

  Serial.print("at\r\n");                               // sending at command to detected gsm modem connected and its ready
  delay(500);                                           // calling delay

  strcpy(phone_number, "+919944257202\0");              // desired phone-number to call
  strcpy(call_status_0, "NO CARRIER\0");                // storing NO CARRIER\0 to call_status_0 buffer for comparing 
  strcpy(call_status_1, "BUSY\0");                      // storing BUSY\0 to call_status_1 buffer for comparing
  call_flag = 0;                                        // initialize call_flag to 0
  temp_0 = 0;                                           // initialize temp_0 to 0
  temp_1 = 0;                                           // initialize temp_1 to 0
}

void loop()
{
  if(digitalRead(7) == 0 && call_flag == 0)                                                    // reading make a call input switch 7 and call-flag status
  {
    Serial.print("atd");                                                                       // sending at command to make a cal [syntax: atd<phone-number><Enter><Line-Feed>]
    for(buffer_index = 0; phone_number[buffer_index] != '\0'; buffer_index++)                  // strat sending at command of make a call
      Serial.print(phone_number[buffer_index], BYTE);                                          // sending phone-number digit by digit
    Serial.print(";\r\n");                                                                     // sending remaining of at command
    call_flag = 1;                                                                             // write 1 to call_flag for indicate make call is in process
    temp_0 = 0;                                                                                // reset to 0 of temp_0 for counting and pointing
    temp_1 = 0;                                                                                // reset to 0 of temp_1 for counting and pointing
    digitalWrite(11, HIGH);                                                                    // make a call led on
    digitalWrite(12, LOW);                                                                     // unattended [no answer] or busy [reject] call led off 
    digitalWrite(13, LOW);                                                                     // cancelling or busy [reject] call led off
    while(digitalRead(7) == 0);                                                                // waits for make a call input switch 7 release
  }

  if(digitalRead(8) == 0 && call_flag == 1)                                                    // reading cancel current call input switch 8 and call-flag status
  {
    Serial.print("ath\r\n");                                                                   // sending at command to cancel current call [syntax: ath<Enter><Line-Feed>]
    call_flag = 0;                                                                             // write 1 to call_flag for indicate make call is not in process
    digitalWrite(13, HIGH);                                                                    // cancelling or busy [reject] call led on
    delay(800);                                                                                // calling delay
    digitalWrite(13, LOW);                                                                     // cancelling or busy [reject] call led off
    digitalWrite(11, LOW);                                                                     // make a call led off

    while(digitalRead(8) == 0);                                                                // waits for cancel current call input switch 8 release
  }
  
  if(Serial.available() > 0)                                                                   // checking for new received byte from gsm modem
  {
    if(call_flag == 1)                                                                         // checking for make call is in process
    {
      serial_rx_data = Serial.read();                                                          // reads the received byte from gsm modem
      
      if(serial_rx_data == call_status_0[temp_0])                                              // checking for unattended call status received from modem
      {
        temp_0++;                                                                              // increment, if unattended call status receving
        serial_rx_data = 0;                                                                    // reset to 0 of serial_rx_data for next byte process
      }
      
      if(temp_0 == 10)                                                                         // checking for unattended call detected
      {
        digitalWrite(12, HIGH);                                                                // unattended [no answer] or busy [reject] call led on
        digitalWrite(11, LOW);                                                                 // make a call led off
        temp_0 = 0;                                                                            // reset to 0 of temp_0 for next processs
        temp_1 = 0;                                                                            // reset to 0 of temp_1 for next processs
        call_flag = 0;                                                                         // reset to 0 of call_flag for next processs
      }
      
      if(serial_rx_data == call_status_1[temp_1])                                              // checking for busy [reject] call status receving
      {
        temp_1++;                                                                              // increment, if busy [reject] call status receving
        serial_rx_data = 0;                                                                    // reset to 0 of serial_rx_data for next byte process
      }
      
      if(temp_1 == 4)                                                                          // checking for busy [reject] call detected
      {
        digitalWrite(12, HIGH);                                                                // unattended [no answer] or busy [reject] call led on
        digitalWrite(13, HIGH);                                                                // cancelling or busy [reject] call led on
        digitalWrite(11, LOW);                                                                 // make a call led off
        temp_0 = 0;                                                                            // reset to 0 of temp_0 for next processs
        temp_1 = 0;                                                                            // reset to 0 of temp_1 for next processs
        call_flag = 0;                                                                         // reset to 0 of call_flag for next processs
      }
    }
  }

  delay(10);                                                                                   // calling mini delay
}

/*

Pin 7      make a call
Pin 8      cancel current calling

Pin 11     make a call in process indicator
Pin 12     call unattended [no answer] or busy [reject] indicator
Pin 13     call cancelling or busy [reject] call indicator

status indicators
-----------------
unattended call      12 led on
busy                 13 and 12 leds on
cancel call          13 led blink one time
make call            11 led on still unattended [no answer] then led off

*/

// tested ok

             // calling mini delay
}

/*

Pin 
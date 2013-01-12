// gsm sms send program

#include <string.h>                                     /* for calling string functions */

unsigned int ldr_value,                                 /* for reading LDR value */
             buffer_index;                              /* for at command buffer pointing */

char  cmd_buffer[250],                                  /* to store at commands buffer */
      phone_number[14];                                 /* to store phone-number */

void setup()
{
  pinMode(11, OUTPUT);                                  // sms sending led indicator
  digitalWrite(11, LOW);                                // sms sending led indicator turn-off
  pinMode(7, INPUT);                                    // sms send input switch 7
  digitalWrite(7, HIGH);                                // making default high on switch 7
  Serial.begin(9600);                                   // enabling uart for gsm modem interfacing
  delay(500);                                           // calling delay
  Serial.print("at\r\n");                               // sending at command to detected gsm modem connected and its ready
  delay(500);                                           // calling delay
  Serial.print("ate0\r\n");                             // turn-off echo character [0=disable, 1=enable]
  delay(500);                                           // calling delay
  Serial.print("at+cmgf=1\r\n");                        // setting sms format as text [1=text, 0=pdu]
  delay(500);                                           // calling delay
  ldr_value = 0;                                        // initialize ldr value to zero
  strcpy(phone_number, "+918122273055\0");              // desired phone-number to sms receive
}

void loop()
{
  if(digitalRead(7) == 0)                               // reading sms send input switch 7
  {
    ldr_value = analogRead(A3);                         // reading current ldr value
    Serial.print("at+cmgs=\"");                         // storing at command to send sms [syntax: at+cmgs="phone-number" <Enter> "your message" <Ctrl+Z>
    for(buffer_index = 0; phone_number[buffer_index] != '\0'; buffer_index++)            // strat sending at command of send sms
    Serial.write(phone_number[buffer_index]);                                    // sending byte by byte
    Serial.print("\"\r");                               // sending Enter character
    delay(4000);                                        // calling big delay, its needed to gsm process time
    Serial.print("HI");
    Serial.print((char)0x1A);                           // sending Ctrl+Z as ascii character 
    while(digitalRead(7) == 0);                         // waits for sms send input switch 7 release
  }

  delay(100);                                           // calling delay
}

// tested ok



// gsm sms receive program [control for particular phone-number only]

#include <string.h>                                      /* for calling string functions */

unsigned int flag_0,                                     /* flag_0 to maintain status of program's process */
             flag_1,                                     /* flag_0 to maintain status of program's process */
             temp,                                       /* temporary for pointing and counting program's process */
             length,                                     /* length of received data counting program's process */
             serial_rx_data,                             /* serial receive data [transmitted by gsm modem] */
             phone_number_flag;                          /* phone-number flag for validity */

char cmd_buffer[250],                                    /* to store at commands buffer */
     new_sms_indication[20],                             /* to store 12 bytes of new sms incoming indication */
     phone_number[14];                                   /* to store phone-number [this number only can control led] */

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
  Serial.print("at\r\n");                                // sending at command to detected gsm modem connected and its ready
  delay(500);                                            // calling delay
  Serial.print("ate0\r\n");                              // turn-off echo character [0=disable, 1=enable]
  delay(500);                                            // calling delay
  Serial.print("at+cmgf=1\r\n");                         // setting sms format as text [1=text, 0=pdu]
  delay(500);                                            // calling delay
  Serial.print("at+cnmi=1,1,0,0,0\r\n");                 // setting new sms message indications as mode=1, mt=1, bm=0, ds=0, bfr=0 [ref: at cmds datasheet]
  delay(500);                                            // calling delay
  flag_0 = 0;                                            // flag_0 setted to 0 as initial
  flag_1 = 0;                                            // flag_1 setted to 0 as initial
  length = 0;                                            // length setted to 0 as initial
  temp = 0;                                              // temp setted to 0 as initial
  phone_number_flag = 0;                                 // phone_number_flag setted to 0 as initial
  strcpy(new_sms_indication, "+CMTI: \"SM\",");          // storing new sms incoming indication for comparing when gsm modem receive sms
  strcpy(phone_number, "+919445677997");                 // storing phone-number [this number only can control led]
}

void loop()
{
  if(Serial.available() > 0)                             // checking for byte received or not from gsm modem
  {
    serial_rx_data = Serial.read();                      // reads the received byte from gsm modem
    
    // checking for 12 bytes of new sms incoming indication from gsm modem [ i.e. +CMTI: "SM", ]
    if(flag_1 == 0)                                      // checking for new sms incoming indication not received 
    {
      if(serial_rx_data == new_sms_indication[flag_0])   // checking each character from gsm with new sms incoming indication
        flag_0++;                                        // incrementing if both are equal
      
      if(flag_0 == 12)                                   // checking for 12 bytes
      {
        flag_1 = 1;                                      // write 1 to flag_1 for new sms incoming indication has received  
        digitalWrite(12, HIGH);                          // new sms incoming indication led on
      }
    }
    
    // receiving remaining bytes of new new sms incoming
    if(flag_1 == 1)                                      // checking for new sms incoming indication is received
    {
      if(serial_rx_data >= '0' && serial_rx_data <= '9') // extracting memory address of new sms incoming
        cmd_buffer[length++] = serial_rx_data;           // storing memory address digits to command buffer
      if(serial_rx_data == '\r' && length > 0)           // checking for end of memory address and minimum is one digit
      {
        cmd_buffer[length++] = serial_rx_data;           // storing Enter character to end of memory address
        cmd_buffer[length] = '\0';                       // teriminating at command buffer
        flag_1 = 2;                                      // write 2 to flag_1 for complet new sms incoming indication has received
      }
    }
    
    // sending at command to read the last new sms received
    if(flag_1 == 2)                                      // checking for complet new sms incoming indication has received
    {
      delay(1000);                                       // calling delay
      digitalWrite(12, LOW);                             // new sms incoming indication led off
      Serial.print("at+cmgr=");                          // sending at command to read read last received new sms
      
      for(temp = 0; cmd_buffer[temp] != '\r'; temp++)    // sending memory address of last received new sms
        Serial.write(cmd_buffer[temp]);            // sending each digits of memory address
      
      Serial.print("\r\n");                              // sending Enter character to end and execute the at command
      flag_1 = 3;                                        // write 3 to flag_1 for sms read at command is issued
    }
    
    // reading sms
    if(flag_1 == 3)                                      // checking for sms read at command is issued
    {
      flag_0 = 0;                                        // write 0 to flag_0 for initial value to buffer pointer
      strcpy(new_sms_indication, "+CMGR: ");             // store +CMGR: to new sms indication buffer for future checking
      flag_1 = 4;                                        // write 4 to flag_1 for read sms started
      goto lnk_t;                                        // goto lnk_t for next byte from gsm modem
    }
    
    // reading sms continued
    if(flag_1 == 4)                                      // checking for read sms started
    {
      if(serial_rx_data == new_sms_indication[flag_0])   // checking for the starting of read sms with comparing of gsm serial data and new sms indicator buffer 
        flag_0++;                                        // increment if both data are same
      
      if(flag_0 == 7)                                    // checking for continues 7 bytes are same 
      {
        flag_1 = 5;                                      // write 5 to flag_1 for read sms is executing
        flag_0 = 0;                                      // write 0 to flag_0 for buffer pointing
        length = 0;                                      // write 0 to length for length couting of bytes
        temp = 0;                                        // write 0 to temp
        goto lnk_t;                                      // goto lnk_t for next byte from gsm modem
      }
    }

    if(flag_1 == 5)                                      // checking for read sms is executing
    {
      if(serial_rx_data == '+' && temp == 0)             // checking for start of phone-number
      {
        flag_1 = 6;                                      // write 6 to flag_1 for start of phone-number
        cmd_buffer[temp++] = serial_rx_data;             // store phone-number to command-buffer
        goto lnk_t;                                      // goto lnk_t for next byte from gsm modem
      }
    }
    
    if(flag_1 == 6)                                      // checking for start of phone-number
    {
      if(serial_rx_data >= '0' && serial_rx_data <= '9' && temp > 0)      // extracting next 12 digits of phone-number
      {
        cmd_buffer[temp++] = serial_rx_data;             // storing phone-number to command-buffer
        
        if(temp == 13)                                   // checking for end of phone-number 
        {
          cmd_buffer[temp++] = '\0';                     // teriminating command-buffer
          temp = 0;                                      // write 0 to temp for re-initialize
          goto lnk_t;                                    // goto lnk_t for next byte from gsm modem
        }
      }

      if(serial_rx_data == '\r' && temp == 0)            // checking for sms read at command's end
      {
        flag_1 = 7;                                      // write 7 to flag_1 for start of phone-number
        digitalWrite(13, LOW);                           // valid indication of user led off

        for(temp = 0, flag_0 = 0; cmd_buffer[temp] != '\0'; temp++)        // comparing valid user phone-number with new in-coming sms's phone-number 
          if(cmd_buffer[temp] == phone_number[temp])                       // checking each digits of phone-number
            flag_0++;                                                      // increment if valid phone-number is detected

        if(flag_0 == 13)                                 // checking for 13 digits of phone-number of valid user led control
        {
          digitalWrite(13, HIGH);                        // valid indication of user led on
          phone_number_flag = 1;                         // write 1 to phone_number_flag for valid led control enabled
        }
        else
        {
          digitalWrite(13, LOW);                         // valid indication of user led off
          phone_number_flag = 0;                         // write 0 to phone_number_flag for valid led control disabled
        }
        
        flag_0 = 0;                                      // write 0 to flag_0 for sms message checking process
        goto lnk_t;                                      // goto lnk_t for next byte from gsm mode
      }
    }

    // reading sms message
    if(flag_1 == 7)                                      // checking for sms message process
    {
      cmd_buffer[length++] = serial_rx_data;             // reading byte of sms message to command buffer and length couting 
      
      if(serial_rx_data == '\r' && flag_0 == 0)          // checking for sms read at command's end
      {
        flag_0 = 1;                                      // write 1 to flag_0 for detection of end at command 
        goto lnk_t;                                      // goto lnk_t for next byte from gsm mode
      }

      if(serial_rx_data == 'O' && flag_0 == 1)           // checking for sms read at command's end
      {
        flag_0 = 2;                                      // write 2 to flag_0 for detection of end at command continued
        goto lnk_t;                                      // goto lnk_t for next byte from gsm mode
      }

      if(serial_rx_data == 'K' && flag_0 == 2)           // checking for sms read at command's end continued
      {
        flag_1 = 8;                                      // write 7 to flag_1 for detection of end at command executed and sms message read completeds
        cmd_buffer[length] = '\0';                       // teriminating at command buffer
        goto lnk_t;                                      // goto lnk_t for next byte from gsm mode
      }
    }

    // driving led according to sms received 
    if(flag_1 == 8)                                      // checking for detection of end at command executed and sms message read completed // if(flag_1 == 7)
    {
      for(temp = 0, flag_0 = 0; cmd_buffer[temp] != '\0'; temp++)    // checking for each character of sms
      {
        // checking for led turn-on and checking valid user phone-number enabled
        if(cmd_buffer[temp] == 'L' && cmd_buffer[temp + 1] == 'E' &&  cmd_buffer[temp + 2] == 'D' && cmd_buffer[temp + 3] == ' ' && cmd_buffer[temp + 4] == 'O' && cmd_buffer[temp + 5] == 'N' && phone_number_flag == 1)
        {
          flag_0 = 2;                                    // write 2 to flag_0 for turn-on led
          break;                                         // condition checking discarding
        }

        // checking for led turn-off and checking valid user phone-number enabled
        if(cmd_buffer[temp] == 'L' && cmd_buffer[temp + 1] == 'E' &&  cmd_buffer[temp + 2] == 'D' && cmd_buffer[temp + 3] == ' ' && cmd_buffer[temp + 4] == 'O' && cmd_buffer[temp + 5] == 'F' && cmd_buffer[temp + 6] == 'F' && phone_number_flag == 1)
        {
          flag_0 = 3;                                    // write 3 to flag_0 for turn-off led
          break;                                         // condition checking discarding
        }
      }
      
      // led status checking and drive it
      if(flag_0 == 2)                                    // checking for led turn-on
      {
        digitalWrite(11, HIGH);                          // led turn-on
        goto lnk_s;                                      // goto lnk_s for next sms process
      }
      
      if(flag_0 == 3)                                    // checking for led turn-off
      {
        digitalWrite(11, LOW);                           // led turn-off
        goto lnk_s;                                      // goto lnk_s for next sms process
      }
      
      // next sms process
      lnk_s:
      flag_0 = 0;                                        // flag_0 setted to 0 as initial
      flag_1 = 0;                                        // flag_1 setted to 0 as initial
      length = 0;                                        // length setted to 0 as initial
      temp = 0;                                          // temp setted to 0 as initial
      phone_number_flag = 0;                             // phone_number_flag setted to 0 as initial
      strcpy(new_sms_indication, "+CMTI: \"SM\",");      // storing new sms incoming indication for comparing when gsm modem receive sms
    }

    lnk_t: ;                                             // goto for next byte of gsm modem
  }
 
  delay(50);                                             // calling mini delay
}

// tested ok


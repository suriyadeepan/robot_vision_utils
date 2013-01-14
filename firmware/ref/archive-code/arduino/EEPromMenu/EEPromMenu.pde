//header files
#include <EEPROM.h>

//global variables
int addr = 0;
int address = 0;
int num=0;
byte value;

//Set baud rate
void setup()
{
  Serial.begin(9600);
}


//store analog value of ldr and store it in a variable val
//write the value into eeprom byte by byte
// when byte 512 is reached, go back to 0.
void loop()
{
  if(Serial.read()!=-1)
 { num=Serial.read()-48;
  


  
while(num==1 && Serial.read()==-1)
{
 
  int val = analogRead(3) / 4;
  
  
  EEPROM.write(addr, val);
  
Serial.println(val);
  addr = addr + 1;
  if (addr == 512)
    addr = 0;
    
    delay(500);
    

}

while(num==2 && Serial.read()==-1)
{
    value = EEPROM.read(address);
  
  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();
  
  // advance to the next address of the EEPROM
  address = address + 1;
  
  // there are only 512 bytes of EEPROM, from 0 to 511, so if we're
  // on address 512, wrap around to address 0
  if (address == 512)
    address = 0;
    
  delay(500);
  


  
}

 }f }



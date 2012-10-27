#include<stdio.h>


int main()
{
  
  while(1){
    
    image = acquire_image();
    command = process_image(image);
    send_command(command);

  }

}

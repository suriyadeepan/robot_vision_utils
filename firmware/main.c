/****************************** 
 * Program : Firmware for uC  *
 * Author  : Selvakumar       *
 * Date    : 28/10/2012       * 
 ******************************/
#include "athena.h"

int USART_receive()
{
  int num;
  printf("\nEnter a number ");
  scanf("%d",&num);
  return num;
}

int main()
{
  int command;

/* uncomment init() when it is defined 
  init();
*/
  
  while(1){
    command = USART_receive();
    if(command > 0){
      
      if(command <= LOCO_CONT_END){
	command = command - (LOCO_CONT_BEGIN+1);
	loco_control[command]();
	continue;
      }
      else if (command <= CAM_CONT_END){
	command = command - (CAM_CONT_BEGIN+1);
	cam_control[command]();
	continue;
      }
      else if(command <= ARM_CONT_END){
	command = command - (ARM_CONT_BEGIN+1);
	arm_control[command]();
	continue;
      }

    }/* if command > 0 */

  }/* end of while */

}


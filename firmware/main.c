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

/* array of function pointers        *
 * datatype (*fp[])(argument list);  *
 */

/* TODO: will be moved to athena.c soon */
int (*loco_control[])() = {  loco_forward,
			     loco_backward,
			     loco_turn_right,
			     loco_turn_left,
			     loco_turn_around 
                          };


int (*arm_control[])() = {  arm_contract, 
			    arm_dilate,
			    arm_up,
			    arm_down
                          };



int (*cam_control[])() = {  cam_look_up,
			    cam_look_down,
			    cam_look_left,
			    cam_look_right
                          };


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


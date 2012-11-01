/****************************** 
 * Program : Firmware for uC  *
 * Author  : Selvakumar       *
 * Date    : 28/10/2012       * 
 ******************************/
#include "athena.h"
#define F_CPU 1200000UL

int USART_receive()
{

#ifdef DEBUG_PC
  int num;
  printf("\nEnter a number ");
  scanf("%d",&num);
  return num;

#endif /* DEBUG_PC */
}

int main()
{
  int command;

/* uncomment init() when it is defined 
  init();
*/
  
  while(1){
       
#ifdef DEBUG_PC
    /* used when compiling for testing in PC, it is uncommon, but I use */
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

   }
#endif  /* DEBUG_PC */

  }/* end of while */

}


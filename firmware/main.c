/************************************************ 
 * Program : Firmware for uC  			*
 * File	   : main.c           			*
 * Author  : Selvakumar       			*
 * Blog    : making-of-athena.blogspot.in       *
 * Date    : 28/10/2012       			* 
 ************************************************/
#include "athena.h"
#define F_CPU 1200000UL

#ifdef FOR_PC
receive ()
{
  int num;
  printf ( "\nEnter a number " ) ;
  scanf ( "%d" , &num ) ;
  return num ;
}
#endif /* FOR_PC */

int main ()
{
  int command ;

/* uncomment init() when it is defined 
  init();
*/
  
  while ( 1 ) {
       
#ifdef FOR_PC
    /* used when compiling for testing in PC, it is uncommon, but I use */
   command = receive ();
   if ( command > 0 ) {
      
      if ( command <= LOCO_CONT_END ) {
	command = command - ( LOCO_CONT_BEGIN + 1 ) ;
	loco_control [ command ] () ;
	continue ;
      }
      else if ( command <= CAM_CONT_END ) {
	command = command - ( CAM_CONT_BEGIN + 1 ) ;
	cam_control [ command ] ();
	continue;
      }
      else if ( command <= ARM_CONT_END ) {
	command = command - (ARM_CONT_BEGIN+1) ;
	arm_control [ command ] () ;
	continue ;
      }

   }
#endif  /* FOR_PC */

  }/* end of while */

}


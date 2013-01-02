/************************************************ 
 * Program : Firmware for uC                    *
 * File	   : athena.c                           *
 * Author  : Selvakumar                         *
 * Blog    : making-of-athena.blogspot.in       *
 * Date    : 28/10/2012                         * 
 ************************************************/

#include "athena.h"


/* Interrupt handlers */
#ifdef FOR_uC
ISR( USART_RXC_vect )
{
  unsigned char command = UDR;
  if ( command > 0 ) {
      
      if ( command <= LOCO_CONT_END ) {
	command = command - ( LOCO_CONT_BEGIN + 1 ) ;
	loco_control[command]() ;
	continue ;
      }
      else if ( command <= CAM_CONT_END ) {
	command = command - ( CAM_CONT_BEGIN + 1 ) ;
	cam_control[command]() ;
	continue ;
      }
      else if ( command <= ARM_CONT_END ) {
	command = command - ( ARM_CONT_BEGIN + 1 ) ;
	arm_control[command]() ;
	continue ;
      }

   }/* if command > 0    */

}
#endif /* FOR_uC */

/* USART - functions */
#ifdef FOR_uC
int USART_init ( int baud )
{
#define _ BVAL /* we can use '_' instead of 'BVAL'  */
  UCSRB |= _(RXEN) | _(TXEN); /* enable RX and TX */
  UCSRB |= _(RXCIE) /* enable RXC interrupt */
  
  UCSRC |= _(URSEL); /* write to UCSRC */
  UCSRC |= _(USBS);  /* use 2 STOP bits */
  UCSRC |= _(UCSZ0) | _(UCSZ1) /* use 8 DATA bit mode */ 

  int baud_prescale = F_CPU / ( 16 * baud ) - 1;
  UBRRL = baud_prescale & 0x00FF;
  UBRRH = RSHIFT( baud_prescale, 8 ) & 0x00FF;

  return 0 ;  
#undef  _ /* '_' is no more valid */
}
#endif /* FOR_uC */





/* other utility functions */
int loco_forward ()    {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_backward ()   {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_turn_right () {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_turn_left ()  {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_turn_around (){  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }

int cam_look_up ()    {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int cam_look_down ()  {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int cam_look_right () {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int cam_look_left ()  {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }

int arm_contract ()   {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int arm_dilate ()     {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int arm_up ()         {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int arm_down ()       {  DBG_PRINT("__FUNCTION__ =  %s\n",__FUNCTION__);      }

/* array of function pointers               *
 * datatype ( *fp [] ) ( argument list ) ;  *
 */
Fp_Control loco_control [] = {  loco_forward,
			        loco_backward,
			        loco_turn_right,
			        loco_turn_left,
			        loco_turn_around 
                              };


Fp_Control arm_control [] = {  arm_contract, 
			       arm_dilate,
			       arm_up,
			       arm_down
                            };


Fp_Control cam_control [] = {  cam_look_up,
		 	       cam_look_down,
			       cam_look_right,
			       cam_look_left
                            };


/****************************** 
 * Program : Firmware for uC  *
 * Author  : Selvakumar       *
 * Date    : 28/10/2012       * 
 ******************************/

#include "athena.h"

/* other utility functions */
int loco_forward()    {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_backward()   {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_turn_right() {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_turn_left()  {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int loco_turn_around(){  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }

int cam_look_up()    {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int cam_look_down()  {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int cam_look_right() {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int cam_look_left()  {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }

int arm_contract()   {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int arm_dilate()     {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int arm_up()         {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }
int arm_down()       {  printf("__FUNCTION__ =  %s\n",__FUNCTION__);      }



/* array of function pointers        *
 * datatype (*fp[])(argument list);  *
 */
Fp_Control loco_control[] = {  loco_forward,
			       loco_backward,
			       loco_turn_right,
			       loco_turn_left,
			       loco_turn_around 
                            };


Fp_Control arm_control[] = {  arm_contract, 
			      arm_dilate,
			      arm_up,
			      arm_down
                           };


Fp_Control cam_control[]= {  cam_look_up,
			     cam_look_down,
			     cam_look_right,
			     cam_look_left
                          };


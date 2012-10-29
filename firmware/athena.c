/****************************** 
 * Program : Firmware for uC  *
 * Author  : Selvakumar       *
 * Date    : 28/10/2012       * 
 ******************************/

#include "athena.h"

/* other utility functions */
int loco_forward()    {  printf("\n %d",LOCO_FORWARD);      }
int loco_backward()   {  printf("\n %d",LOCO_BACKWARD);     }
int loco_turn_right() {  printf("\n %d",LOCO_TURN_RIGHT);   }
int loco_turn_left()  {  printf("\n %d",LOCO_TURN_LEFT);    }
int loco_turn_around(){  printf("\n %d",LOCO_TURN_AROUND);  }

int cam_look_up()    {  printf("\n %d",CAM_LOOK_UP);     }
int cam_look_down()  {  printf("\n %d",CAM_LOOK_DOWN);   }
int cam_look_right() {  printf("\n %d",CAM_LOOK_RIGHT);  }
int cam_look_left()  {  printf("\n %d",CAM_LOOK_LEFT);   }

int arm_contract()   {  printf("\n %d",ARM_CONTRACT);   }
int arm_dilate()     {  printf("\n %d",ARM_DILATE);     }
int arm_up()         {  printf("\n %d",ARM_UP);         }
int arm_down()       {  printf("\n %d",ARM_DOWN);       }

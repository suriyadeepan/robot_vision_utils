/****************************** 
 * Program : Firmware for uC  *
 * Author  : Selvakumar       *
 * Date    : 28/10/2012       * 
 ******************************/

/* compiled for testing in pc. so needed to be commented

#include<avr/io.h>
#include<util/dealy.h>

*/

#include<stdio.h>

/*  LOCOMOTION OPERATIONS */
#define LOCO_FORWARD      01
#define LOCO_BACKWARD     02
#define LOCO_TURN_RIGHT   03
#define LOCO_TURN_LEFT    04
#define LOCO_TURN_AROUND  05
/*  CAMERA HANDLING */
#define CAM_LOOK_UP       11
#define CAM_LOOK_DOWN     12
#define CAM_LOOK_RIGHT    13
#define CAM_LOOK_LEFT     14
/* ARM CONTROL */
#define ARM_CONTRACT      21
#define ARM_DILATE        22
#define ARM_UP            23
#define ARM_DOWN          24

/* function prototypes with similar signatures atleast for each category */
/*locomotion - category */
int loco_forward();
int loco_backward();
int loco_turn_right();
int loco_turn_left();
int loco_turn_around();

/*camera - category */
int cam_look_up();
int cam_look_down();
int cam_look_right();
int cam_look_left();

/*arm - category */
int arm_contract();
int arm_dilate();
int arm_up();
int arm_down();

/* array of function pointers        *
 * datatype (*fp[])(argument list);  *
 */
int (*loco_control[])() = { loco_forward,
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


int (*cam_control[])() = { cam_look_up,
			    cam_look_down,
			    cam_look_left,
			    cam_look_right
                          };


/* other utility functions */

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
      
      if(command <= 10){
	command = command - 1;
	loco_control[command]();
	continue;
      }
      else if (command <= 20){
	command = command - 11;
	cam_control[command]();
	continue;
      }
      else if(command <= 30){
	command = command -21;
	arm_control[command]();
	continue;
      }

    }/* if command > 0 */

  }/* end of while */

}


int loco_forward()
{
  printf("\n %d",LOCO_FORWARD);
  
}

int loco_backward()
{
  printf("\n %d",LOCO_BACKWARD);
  
}

int loco_turn_right()
{
  printf("\n %d",LOCO_TURN_RIGHT);
  
}

int loco_turn_left()
{
  printf("\n %d",LOCO_TURN_LEFT);
  
}

int loco_turn_around()
{
  printf("\n %d",LOCO_TURN_AROUND);
  
}

int cam_look_up()
{
  printf("\n %d",CAM_LOOK_UP);
  
}

int cam_look_down()
{
  printf("\n %d",CAM_LOOK_DOWN);
  
}

int cam_look_right()
{
  printf("\n %d",CAM_LOOK_RIGHT);
  
}

int cam_look_left()
{
  printf("\n %d",CAM_LOOK_LEFT);
  
}

int arm_contract()
{
  printf("\n %d",ARM_CONTRACT);
  

}

int arm_dilate()
{
  printf("\n %d",ARM_DILATE);
  
}

int arm_up()
{
  printf("\n %d",ARM_UP);
  
}

int arm_down()
{
  printf("\n %d",ARM_DOWN);
  
}

/****************************** 
 * Program : Firmware for uC  *
 * Author  : Selvakumar       *
 * Date    : 28/10/2012       * 
 ******************************/


#ifndef _ATHENA_H_
#define _ATHENA_H_


/* compiled for testing in pc. so needed to be commented

#include<avr/io.h>
#include<util/dealy.h>

*/

#include<stdio.h>

#define LOCO_CONT_BEGIN 00                               /* 00 */
#define LOCO_CONT_LEN   10
#define LOCO_CONT_END   LOCO_CONT_BEGIN + LOCO_CONT_LEN  /* 10 */

#define CAM_CONT_BEGIN  LOCO_CONT_END                    /* 10 */
#define CAM_CONT_LEN    10
#define CAM_CONT_END    CAM_CONT_BEGIN + CAM_CONT_LEN    /* 20 */

#define ARM_CONT_BEGIN  CAM_CONT_END                     /* 20 */
#define ARM_CONT_LEN    10
#define ARM_CONT_END    ARM_CONT_BEGIN + ARM_CONT_LEN    /* 30 */

/************************************************************
 * Actual operations                                        *
 * they are used as indices for                             *
 * <category>_<opertion>_<dirction> function pointer array  *
 ************************************************************/

/*  LOCOMOTION OPERATIONS */
#define LOCO_FORWARD      LOCO_CONT_BEGIN +  01
#define LOCO_BACKWARD     LOCO_CONT_BEGIN +  02
#define LOCO_TURN_RIGHT   LOCO_CONT_BEGIN +  03
#define LOCO_TURN_LEFT    LOCO_CONT_BEGIN +  04
#define LOCO_TURN_AROUND  LOCO_CONT_BEGIN +  05
/*  CAMERA HANDLING */
#define CAM_LOOK_UP       CAM_CONT_BEGIN + 01
#define CAM_LOOK_DOWN     CAM_CONT_BEGIN + 02
#define CAM_LOOK_RIGHT    CAM_CONT_BEGIN + 03
#define CAM_LOOK_LEFT     CAM_CONT_BEGIN + 04
/* ARM CONTROL */
#define ARM_CONTRACT      ARM_CONT_BEGIN + 01
#define ARM_DILATE        ARM_CONT_BEGIN + 02
#define ARM_UP            ARM_CONT_BEGIN + 03
#define ARM_DOWN          ARM_CONT_BEGIN + 04

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

int USART_receive();

typedef int (*Fp_Control)();

Fp_Control loco_control[LOCO_CONT_LEN];
Fp_Control cam_control[CAM_CONT_LEN];
Fp_Control arm_control[ARM_CONT_LEN];


#endif /* _ATHENA_H_ */

/************************************************ 
 * Program : Firmware for uC                    *
 * File	   : athena.h                           *
 * Author  : Selvakumar                         *
 * Blog    : making-of-athena.blogspot.in       *
 * Date    : 28/10/2012                         * 
 ************************************************/


#ifndef _ATHENA_H_
#define _ATHENA_H_

/* un/comment the following #defines for debugging purpose*/
//#define FOR_PC 1 
//#define FOR_uC 1

/* uncomment the following #includes if compiled for uC */
#ifdef FOR_uC
#include<avr/io.h>
#include<util/delay.h>
#endif /* FOR_uC */

/* uncomment the following #includes if compiled for PC */
#ifdef FOR_PC
#include<stdio.h>
#endif /* FOR_PC */

#define LOCO_CONT_BEGIN 00 + 1                           /* 00 */
#define LOCO_CONT_LEN   10
#define LOCO_CONT_END   LOCO_CONT_BEGIN + LOCO_CONT_LEN  /* 10 */

#define CAM_CONT_BEGIN  LOCO_CONT_END + 1                /* 10 */
#define CAM_CONT_LEN    10
#define CAM_CONT_END    CAM_CONT_BEGIN + CAM_CONT_LEN    /* 20 */

#define ARM_CONT_BEGIN  CAM_CONT_END + 1                 /* 20 */
#define ARM_CONT_LEN    10
#define ARM_CONT_END    ARM_CONT_BEGIN + ARM_CONT_LEN    /* 30 */

/************************************************************
 * Actual operations                                        *
 * they are used as indices for                             *
 * <category>_<opertion>_<direction> function pointer array  *
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

/* macros for debugging in PC */
#ifdef FOR_PC
#define DBG_PRINT(format, args...) printf(format, ##args)
#else
#define DBG_PRINT(format, args...) 
#endif /* FOR_PC*/

/* macros for debugging in uC */
#ifdef FOR_uC
#define DBG_WRITE(val) USART_Write(val)
#else
#define DBG_WRITE(val) 
#endif /* FOR_PC*/

/* shifts the binary content of 'val' by 'bits' to the left */
#define LSHIFT(val, bits) ((val) << (bits))
/* shifts the binary content of 'val' by 'bits' to the right */
#define RSHIFT(val, bits) ((val) >> (bits))

/***************************************************
 * gives the bit-value of the arguement 'x'        *
 * e.g: for x = 0, BVAL(x) --> 1                   *
 *          x = 1, BVAL(x) --> 2                   *
 *          x = 2, BVAL(x) --> 4                   *
 ***************************************************/
#define BVAL(x) (1 << (x)) /* shifts 1 x bits to the left */

/* Interrupt handlers                           *
 * defined in athena.c file.                    *
 *    +ISR(USART_RXC_vect);                     *
 */

/* USART - functions */
int USART_init ( int baud )  ;


/* function prototypes with similar signatures atleast for each category */
/*locomotion - category */
int loco_forward ()    ;
int loco_backward ()   ;
int loco_turn_right () ;
int loco_turn_left ()  ;
int loco_turn_around ();

/*camera - category */
int cam_look_up ()    ; 
int cam_look_down ()  ;
int cam_look_right () ;
int cam_look_left ()  ;

/*arm - category */
int arm_contract () ;
int arm_dilate ()   ;
int arm_up ()       ;
int arm_down ()     ;

int USART_receive () ;
int USART_write ( int val ) ;

typedef int ( *Fp_Control ) ( );

Fp_Control loco_control[ LOCO_CONT_LEN ] ;
Fp_Control cam_control[ CAM_CONT_LEN  ] ;
Fp_Control arm_control[ ARM_CONT_LEN  ] ;



#endif /* _ATHENA_H_ */

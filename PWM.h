
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
  
#ifndef PWM_H
#define	PWM_H

#include <xc.h>

void initPWM1();
uint16_t setDutyCyclePWM1(uint16_t DC);
uint16_t nudgeDutyCyclePWM1(uint16_t duty_current, uint16_t duty_change);

#endif


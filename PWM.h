
/*
 * Senior Design Project 8-Bit Motor Controller Prototype
 * DC motor control via H-bridge / PWM 
 * Written for PIC16F877A
 * File:   PWM.h
 * Author: wilson
 *
 * Created on April 19, 2021, 11:25 PM
 */
  
#ifndef PWM_H
#define	PWM_H

#include <xc.h>

    void initPWM1();
    uint16_t setDutyCyclePWM1(uint16_t DC);
    uint16_t nudgeDutyCyclePWM1(uint16_t duty_current, uint16_t duty_change);

#endif


/*
 * Senior Design Project 8-Bit Motor Controller Prototype
 * DC motor control via H-bridge / PWM 
 * Written for PIC16F877A
 * File:   PWM.c
 * Author: wilson
 *
 * Created on April 19, 2021, 11:04 PM
 */

#include <xc.h>
#include <stdint.h>
#include "config.h"
#include "PWM.h"

#define _XTAL_FREQ 4000000

void initPWM1()
{
  
  TRISD0 = 0;           // set output pins direction
  TRISD1 = 0;
  RD0 = 0;              // initially set to clockwise
  RD1 = 1;
  CCP1M3 = 1;           // CCP module config
  CCP1M2 = 1;
  TRISC2 = 0;           // CCP1 PWM output pin
  PR2 = 124;            // PWM frequency 2kHz
  T2CKPS0 = 1;          // PS for TMR2 1:4 ratio
  T2CKPS1 = 0;
  TMR2ON = 1;           // start CCP1 PWM
}

uint16_t setDutyCyclePWM1(uint16_t DC)
{
    CCP1Y = DC & 1;
    CCP1X = DC & 2;
    CCPR1L = DC >> 2;
    __delay_ms(100);

    return DC;
}

uint16_t nudgeDutyCyclePWM1(uint16_t duty_current, uint16_t duty_change)
{
    uint16_t DC = 0;
    if (duty_current + duty_change > 1024)
        DC = 500;
    if (duty_current + duty_change < 0)
        DC = 0;
    else
    {
        DC = duty_current + duty_change;
        CCP1Y = DC & 1;
        CCP1X = DC & 2;
        CCPR1L = DC >> 2;   
    }
    __delay_ms(100);

    return DC;
}
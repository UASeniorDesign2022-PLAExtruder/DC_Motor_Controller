/*
 * Senior Design Project 8-Bit Motor Controller Prototype
 * DC motor control via H-bridge / PWM 
 * Written for PIC16F877A
 * File:   main.c
 * Author: wilson
 *
 * Created on April 18, 2021, 4:47 PM
 */

#include <xc.h>
#include <stdint.h>
#include "config.h"

#define _XTAL_FREQ 4000000

#define DUTY_CYCLE_REVERSE      RB0   //  reverse direction
#define DUTY_CYCLE_ZERO         RB1   //    0% duty
#define DUTY_CYCLE_DOWN         RB2   //   -5% duty
#define DUTY_CYCLE_HALF         RB3   //  ~50% duty
#define DUTY_CYCLE_UP           RB4   //   +5% duty

/*********************** Function Declarations ************************/

void initPWM1();
uint16_t setDutyCyclePWM1(uint16_t DC);
uint16_t nudgeDutyCyclePWM1(uint16_t duty_current, uint16_t duty_change);

/***************************** Main Loop ******************************/

int main(void)
{  
  TRISB = 0x1F;         // RB0-RB4 as inputs
  
  initPWM1();
  uint16_t duty_cycle = 0;
  duty_cycle = setDutyCyclePWM1(0);
  
  while(1)
  {

    if (DUTY_CYCLE_ZERO)
        duty_cycle = setDutyCyclePWM1(0);

    if (DUTY_CYCLE_REVERSE)
    {
        RD0 = ~RD0;
        RD1 = ~RD1;
        __delay_ms(500);
    }

    if (DUTY_CYCLE_DOWN)
        duty_cycle = nudgeDutyCyclePWM1(duty_cycle, -25);

    if (DUTY_CYCLE_HALF)
        duty_cycle = setDutyCyclePWM1(350);

    if (DUTY_CYCLE_UP)
        duty_cycle = nudgeDutyCyclePWM1(duty_cycle, 25);

    __delay_ms(10);
  }

  return 1;
}

/*********************** Function Definitions *************************/

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

/*************************** End of File ******************************/

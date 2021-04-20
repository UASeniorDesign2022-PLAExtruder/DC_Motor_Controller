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
#include "PWM.h"

#define _XTAL_FREQ 4000000

/************************** Pin Definitions ***************************/

#define DUTY_CYCLE_REVERSE      RB0   //    reverse direction
#define DUTY_CYCLE_ZERO         RB1   //    0% duty
#define DUTY_CYCLE_DOWN         RB2   //   -5% duty
#define DUTY_CYCLE_HALF         RB3   //  ~50% duty
#define DUTY_CYCLE_UP           RB4   //   +5% duty

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

/*************************** End of File ******************************/


/*
 * Senior Design Project 8-Bit Motor Controller Prototype
 * DC motor control via H-bridge / PWM 
 * Written for PIC16F877A
 * File:   config.h
 * Author: wilson
 *
 * Created on April 19, 2021, 11:25 PM
 */
  
#ifndef CONFIG_H
#define	CONFIG_H

    #include <xc.h>

    // PIC16F877A configuration bits
    // #pragma config statements should precede project file includes
    // use project enums instead of #define for ON and OFF

    #pragma config FOSC = XT    // oscillator selection bits (XT oscillator)
    #pragma config WDTE = OFF   // WDT enable bit (disabled)
    #pragma config PWRTE = ON   // power-up timer enable bit (PWRT enabled)
    #pragma config BOREN = ON   // brown-out reset enable bit (BOR enabled)
    #pragma config LVP = OFF    // low-voltage (single-supply) in-circuit serial programming enable bit
                                // (RB3 is digital I/O, HV on MCLR must be used for programming)
    #pragma config CPD = OFF    // data EEPROM memory code protection bit (data EEPROM code protection off)
    #pragma config WRT = OFF    // flash program memory write enable bits 
                                // (write protection off, all program memory may be written to by EECON control)
    #pragma config CP = OFF     // flash program memory code protection bit (code protection off)

#endif

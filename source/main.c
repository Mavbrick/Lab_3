/*	Author: mbaut030
 *  Partner(s) Name: Maverick
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
i *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations /
 *         DDRD = 0x00; PORTD = 0xFF;
 *                 DDRB = 0xFE; PORTB = 0x01;
 *                     / Insert your solution below */
        unsigned char tmpD = 0x00;
        unsigned char tmpB = 0x00;
        unsigned char weight = 0x00;

    while (1) {
        tmpD = PIND;
        tmpB = PINB & 0x01;

        weight = (tmpD << 1) | tmpB;

        if (weight >= 70) {
                PORTB = 0x02;
        }
        else if (weight > 5 && weight < 70) {
                PORTB = 0x04;
        }
        else {
                PORTB = 0x00;
        }

    }
    return 1;
}

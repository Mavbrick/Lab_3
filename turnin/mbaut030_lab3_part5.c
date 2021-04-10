/*	Author: mbaut030
 *  Partner(s) Name: Maverick
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 5
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
    /* Insert DDR and PORT initializations */
          DDRD = 0x00; PORTD = 0xFF;
          DDRB = 0xFE; PORTB = 0x01;
    /* Insert your solution below */
        unsigned char tmpD = 0x00;
        unsigned char tmpB = 0x00;
	unsigned short weight = 0x00;

    while (1) {
	tmpB = PINB;
	tmpD = PIND;
	weight = 0x00;
	weight = (tmpD << 1) | (tmpB & 0x01);

	if(weight >= 0x046) {
		PORTB = 0x02;
	}
	else if ((weight > 0x05) && (weight < 0x46)) {
		PORTB = 0x04;
	}
	else {
		PORTB = 0x00;
	}
    }
    return 1;
}

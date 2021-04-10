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
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
        unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
        unsigned char tmpC = 0x00;

    while (1) {
        tmpA = PINA;
	
	tmpB = 0x00;
	tmpC = 0x00;
	
	tmpB = (tmpA & 0xF0) >> 4; //UPPER A => LOWER B
	tmpC = (tmpA & 0x0F) << 4; //LOWER A => UPPER C
	
	PORTB = tmpB;
	PORTC = tmpC;
    }
    return 1;
}

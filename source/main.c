/*	Author: hshep002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */

	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;

	char PA0 = 0x00;
	char PA1 = 0x00;
	char PB0 = 0x00;
    /* Insert your solution below */
    while (1) {
	PA0 = PINA & 0x01;
	PA1 = PINA & 0x02;
	if(!PA1 && PA0)
	{
		PB0 = 0x01;
	}
	else
	{
		PB0 = 0x00;
	}
	PORTB = PB0;

    }
    return 1;
}

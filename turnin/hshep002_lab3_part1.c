/*	Author: hshep002
 *  Partner(s) Name: Harris Shepard
 *	Lab Section: 23
 *	Assignment: Lab 3  Exercise 1
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

	//idk this might be initializatino?
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char num_ones = 0x00;
	unsigned char cur_bit = 0x01;

    /* Insert your solution below */
   while (1) {
		num_ones = 0x00;
		cur_bit = 0x01;
		for(int i = 0; i< 8; i++)
		{
			num_ones += (PINA&cur_bit) ? 1 : 0;
			num_ones += (PINB&cur_bit) ? 1 : 0;
			cur_bit = cur_bit *2;
		}
		PORTC = num_ones;

    }
    return 1;
}

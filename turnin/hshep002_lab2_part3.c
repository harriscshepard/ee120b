/*	Author: hshep002
 *  Partner(s) Name: Harris Shepard
 *	Lab Section: 23
 *	Assignment: Lab 2  Exercise 3
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char cntavail = 0x00;
	unsigned char tempC = 0x00;

    /* Insert your solution below */
   while (1) {
	cntavail = !(PINA & 0x01)+!(PINA & 0x02)+!(PINA & 0x04)+!(PINA & 0x08);
	tempC = PORTC & 0x70; //A6-A4

	//writes only to C7 and C3-C0
	PORTC = (cntavail) ? (tempC + cntavail):(0x80 + tempC + cntavail); //set C7 if !cntavail

    }
    return 1;
}

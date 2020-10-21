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

	//idk this might be initializatino?
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;

	unsigned char input = 0x00;
	unsigned char cntavail = 0x00;
//	unsigned char pA1 = 0x00;
//	unsigned char pB0 = 0x00;
    /* Insert your solution below */
   while (1) {
//	pA0 = PINA & 0x01;
//	pA1 = PINA & 0x02;
	for(unsigned char i = 0x00; i < 4; i++)
	{
		if(i & PINA) //if the space is taken
		{
			//do nothing
		}	
		else
		{
			cntavail = cntavail + 1;//increment available spaces by 1
		}
	}	
	PORTC = cntavail;

    }
    return 1;
}

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
	DDRB = 0x00;
	PORTB = 0xFF;


	DDRC = 0xFF;
	PORTC = 0x00;
	unsigned char num_ones = 0x00;
//	unsigned char pA1 = 0x00;
//	unsigned char pB0 = 0x00;
    /* Insert your solution below */
   while (1) {
	num_ones = 0x00;
//	pA0 = PINA & 0x01;
//	pA1 = PINA & 0x02;
//	lab3 counting 1's in ports
	for(unsigned char i = 0x00; i < 8; i++)
	{
		if(i & PINA) //if the space is taken
		{
			num_ones = num_ones + 1;
		}
	}
	for(unsigned char i = 0x00; i < 8; i++)
        {
                if(i & PINB) //if the space is taken
                {
                        num_ones = num_ones + 1;
                }
        }

	PORTC = num_ones;

    }
    return 1;
}

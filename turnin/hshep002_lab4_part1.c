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

enum States {zeroth_led_on,first_led_on_wait,first_led_on,zeroth_led_on_wait} State;

void Tick()
{
	switch(State) { //transitions
		case zeroth_led_on:
			if(PA0) {State = first_led_on_wait;}
			else	{State = zeroth_led_on;}
			break;
		case first_led_on_wait:
			if(PA0)	{State = first_led_on_wait;}//wait
			else	{State = first_led_on;}
			break;
		case first_led_on:
			if(PA0) {State = zeroth_led_on_wait;}
			else	{State = first_led_on;}
			break;
		case zeroth_led_on_wait:
			if(PA0)	{State = zeroth_led_on_wait;}//wait
			else	{State = zeroth_led_on;}
			break;
		default:
			State = zeroth_led_on;
			break;
	}
	switch(State) { //state actions
		case zeroth_led_on:
		case zeroth_led_on_wait:
			PB0 = 1;
			PB1 = 0;
			break;
		case first_led_on:	
		case first_led_on_wait:
			PB0 = 0;	
			PB1 = 1;
			break;
	}
}



int main(void) {
    /* Insert DDR and PORT initializations */

	//idk this might be initializatino?
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0x00;
	PORTB = 0xFF;


	DDRC = 0xFF;
	PORTC = 0x00;

	PB0 = 1;
	PB1 = 0;
	State = zeroth_led_on;

	unsigned char fuelLevel = 0x00;
	unsigned char pa4 = 0x00;// for exercise 3
	 unsigned char pa5 = 0x00;  
	 unsigned char pa6 = 0x00;  
//	unsigned char pA1 = 0x00;
//	unsigned char pB0 = 0x00;
    /* Insert your solution below */
   while (1) {
//	pA0 = PINA & 0x01;
//	pA1 = PINA & 0x02;
	
	Tick();	

    }
    return 1;
}

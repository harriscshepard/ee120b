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

enum States {idle,start_increment,start_decrement,reset} State;

void Tick()
{
	switch(State) { //transitions
		case idle:
			if(PA0&&PA1)	{State = reset;} //edge case both buttons pressed at once
			else if(PA0)	{State = start_increment;}
			else if(PA1)	{State = start_decrement;}
			else		{State = idle;}
			break;
		case start_increment:
			if(PA0&&PA1)	{State = reset;}
			else if(PA0)	{State = start_increment;} //wait
			else		{State = idle;	//finish incrementing
					if(PORTC < 9) {PORTC = PORTC + 1;}
					}
			break;
		case start_decrement:
			if(PA0&&PA1) 	{State = reset;}
			else if(PA1)	{State = start_decrement;} //wait
			else		{State = idle; //finish decrementing
					if(PORTC>1) {PORTC = PORTC - 1;}
					}
			break;
		case reset:
			if(PA0||PA1)	{State = reset;}//wait
			else		{State = idle;
					PORTC = 0;
					}
			break;
		default:
			State = idle;
			break;

			
		
	}
	switch(State) { //state actions?
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
	PORTC = 0x07;
	State = idle;

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

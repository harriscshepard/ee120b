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

enum States {locked,wait_hash_pushed,hashed_pushed,wait_y_pushed,unlocked} State;

void Tick()
{
	switch(State) { //transitions
		case locked:
			if(PA2&&!PA0&&!PA1)	{State = wait_hash_pushed;} //pa2 (hash is pushed) but other buttons are not
			else		{State = locked;}
			break;
		case wait_hash_pushed:
			if(PA0||PA1)	{State = locked;} //push wrong
			else if(PA2)	{State = wait_hash_pushed;} //waiting for hash to be released
			else		{State = hash_pushed;}	//wait, no input
					
			break;
		case hash_pushed:
			if(PA0||PA2) 	{State = locked;} //pushed wrong iether x = pa0 or # = pas2
			else if(PA1)	{State = wait_y_pushed;} //correct input y
			else		{State = hash_pushed;} //wait
			break;
		case wait_y_pushed:
			if(PA0||PA2)	{State = locked;}//wrong input, simultaneous key press = locked
			else if(PA1)	{State = wait_y_pushed;} //wait until y released
			else		{State = unlocked;//y is released
					PB0 = 1; //unlocks the door
					}
			break;
		case unlocked:
			if(PA7)		{State = locked;	//pa7 is the only input to consider if it is unlocked
					PB0 = 0; //locks the door
					}//note: only going from wait_y_pushed to unlocked AND going from unlocked to locked will change the variables PB0
			else		{State = unlocked;}
			break;
		default:
			State = locked;
			break;		
	}
	switch(State) { //state actions
		default:
			PORTC = State;
			break; //every action writes to portc?
	}
}



int main(void) {
    /* Insert DDR and PORT initializations */

	//idk this might be initializatino?
	DDRA = 0x00;//input
	PORTA = 0xFF;


	DDRB = 0xFF; //output
	PORTB = 0x00;


	DDRC = 0xFF;//output
	PORTC = 0x00;
	State = locked;	

//	unsigned char fuelLevel = 0x00;
//	unsigned char pa4 = 0x00;// for exercise 3
//	 unsigned char pa5 = 0x00;  
//	 unsigned char pa6 = 0x00;  
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

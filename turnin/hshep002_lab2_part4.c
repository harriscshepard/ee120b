/*	Author: hshep002
 *  Partner(s) Name: Harris Shepard
 *	Lab Section: 23
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) 
{
    /* Insert DDR and PORT initializations */

	//idk this might be initializatino?
	DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
 
	DDRD = 0xFF; PORTD = 0x00;

	   unsigned char total_msb = 0x00;
       unsigned char temp_a = 0x00;
       unsigned char temp_b = 0x00;
       unsigned char temp_c = 0x00;

       unsigned char is_overweight =0x00;
       unsigned char is_difference = 0x00;
    /* Insert your solution below */
   while (1) 
   {
       is_overweight =0x00;
       is_difference = 0x00;
       temp_a = (PINA | 0xC0)? 0x01 : 0x00; //checks 2 most msb
       temp_b = (PINB | 0xC0)? 0x01 : 0x00;
       temp_c = (PINC | 0xC0)? 0x01 : 0x00;
       if(!(temp_a+temp_b+temp_c))//addition is safe, no overflow, each input is <64
       {
           is_difference = 0x00;
           if(PINA+PINB+PINC>140)//if each input <63, their difference cannot be >80, only check their total
           {
               is_overweight = 0x01;
           }
           else
           {
                is_overweight = 0x00;
           }

       }
       else //addition is not safe, at least one input is >63
       {
            //check msb's again

            
            temp_a = (PINA | 0x80)? 0x01 :0x00;
            temp_b = (PINB | 0x80)? 0x01 :0x00;
            temp_c = (PINC | 0x80)? 0x01 :0x00;
            if(!(temp_a+temp_b+temp_c)) //each input x<128
            {
                is_overweight = 0x01;
                is_difference = 0x00;
            }
            else
            {

            }
       }
      
       out:
       
        
    }
    return 1;
}

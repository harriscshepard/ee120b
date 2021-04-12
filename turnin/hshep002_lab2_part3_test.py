""""
Author: hshep002
Partner(s) Name: Harris Shepard
Lab Section: 23
Assignment: Lab 2 Exercise 3 test
Exercise Description: [optional - include for your own benefit]

I acknowledge all content contained herein, excluding template or example
code, is my own original work.

Disclaimer: I haven't done any of these tests, I debug using gradescope
""""

tests = [ {'description': 'PINA: 0x00 => PORTC: 0x04',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTC',0x04)],
    },
    {'description': 'PINA: 0xFF => PORTC: 0xF0',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
    'expected': [('PORTC',0xF0)],
    },
    {'description': 'PINA: 0x0F => PORTC: 0x80',
    'steps': [ {'inputs': [('PINA',0x0F)], 'iterations': 5 } ],
    'expected': [('PORTC',0x80)],
    },
        {'description': 'PINA: 0xF0 => PORTC: 0x04',
    'steps': [ {'inputs': [('PINA',0xF0)], 'iterations': 5 } ],
    'expected': [('PORTC',0x04)],
    }
    ]
watch = ['PORTC']
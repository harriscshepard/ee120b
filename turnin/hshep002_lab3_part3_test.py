""""
Author: hshep002
Partner(s) Name: Harris Shepard
Lab Section: 23
Assignment: Lab 3 Exercise 3 test
Exercise Description: [optional - include for your own benefit]

I acknowledge all content contained herein, excluding template or example
code, is my own original work.

Disclaimer: I haven't done any of these tests, I debug using gradescope
""""

tests = [ {'description': 'PINA: 0x00 => PORTC: 0x40',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTC',0x40)],
    },
    {'description': 'PINA: 0x83 => PORTC: 0x70',
    'steps': [ {'inputs': [('PINA',0x83)], 'iterations': 5 } ],
    'expected': [('PORTC',0x70)],
    },
    {'description': 'PINA: 0xFF => PORTC: 0x3F',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
    'expected': [('PORTC',0x3F)],
    },
        {'description': 'PINA: 0x3F => PORTC: 0xBF',
    'steps': [ {'inputs': [('PINA',0x3F)], 'iterations': 5 } ],
    'expected': [('PORTC',0xBF)],
    }
    ]
watch = ['PORTC']
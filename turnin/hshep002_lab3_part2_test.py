""""
Author: hshep002
Partner(s) Name: Harris Shepard
Lab Section: 23
Assignment: Lab 3 Exercise 2 test
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
    {'description': 'PINA: 0x07 => PORTC: 0x3C',
    'steps': [ {'inputs': [('PINA',0x07)], 'iterations': 5 } ],
    'expected': [('PORTC',0x3C)],
    },
        {'description': 'PINA: 0x05 => PORTC: 0x38',
    'steps': [ {'inputs': [('PINA',0x05)], 'iterations': 5 } ],
    'expected': [('PORTC',0x38)],
    }
    ]
watch = ['PORTC']
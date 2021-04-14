""""
Author: hshep002
Partner(s) Name: Harris Shepard
Lab Section: 23
Assignment: Lab 3 Exercise 1 tests
Exercise Description: [optional - include for your own benefit]

I acknowledge all content contained herein, excluding template or example
code, is my own original work.

Disclaimer: I haven't done any of these tests, I debug using gradescope
""""

tests = [ {'description': 'PINA: 0x00, PINB: 0x00 => PORTC: 0x00',
    'steps': [ {'inputs': [('PINA',0x00),('PINB',0x00)], 'iterations': 5 } ],
    'expected': [('PORTC',0x00)],
    },
    {'description': 'PINA: 0xFF, PINB: 0xFF => PORTC: 0x10',
    'steps': [ {'inputs': [('PINA',0xFF),('PINB',0xFF)], 'iterations': 5 } ],
    'expected': [('PORTC',0x10)],
    },
    {'description': 'PINA: 0x0F, PINB: 0x0F => PORTC: 0x08',
    'steps': [ {'inputs': [('PINA',0x0F),('PINB',0x0F)], 'iterations': 5 } ],
    'expected': [('PORTC',0x08)],
    },
        {'description': 'PINA: 0x11, PINB: 0x11 => PORTC: 0x06',
    'steps': [ {'inputs': [('PINA',0x11),('PINB',0x11)], 'iterations': 5 } ],
    'expected': [('PORTC',0x06)],
    }
    ]
watch = ['PORTC']
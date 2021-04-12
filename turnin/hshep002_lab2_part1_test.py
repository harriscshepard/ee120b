""""
Author: hshep002
Partner(s) Name: Harris Shepard
Lab Section: 23
Assignment: Lab 2 Exercise 1 tests
Exercise Description: [optional - include for your own benefit]

I acknowledge all content contained herein, excluding template or example
code, is my own original work.

Disclaimer: I haven't done any of these tests, I debug using gradescope
""""

tests = [ {'description': 'PINA: 0x00 => PORTB: 0x00',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTB',0x00)],
    },
    {'description': 'PINA: 0x01 => PORTB: 0x01',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
    'expected': [('PORTB',0x01)],
    },
    {'description': 'PINA: 0x10 => PORTB: 0x00',
    'steps': [ {'inputs': [('PINA',0x10)], 'iterations': 5 } ],
    'expected': [('PORTB',0x00)],
    },
        {'description': 'PINA: 0x11 => PORTB: 0x01',
    'steps': [ {'inputs': [('PINA',0x11)], 'iterations': 5 } ],
    'expected': [('PORTB',0x00)],
    }
    ]
watch = ['PORTB']
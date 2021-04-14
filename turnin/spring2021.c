$/home/csmajs/hshep002/spring2021
$/usr/csshare/pkgs/cs120b-avrtools/createProject.sh
$ avr-gcc -mmcu=atmega1284 -Wall -o build/objects/main.elf source/main.c

hshep002@bolt.cs.ucr.edu
ssh wch136-24.cs.ucr.edu



$git remote add origin <URL>

make all
make pytest

//ssh wch136-21.cs.ucr.edu for cs166
// CS166 Code
mkdir /tmp/$LOGNAME
cd /tmp/$LOGNAME
mkdir test
mkdir test/data
mkdir sockets
export PGDATA=/tmp/$LOGNAME/test/data

//Start database server, create database, start interactive environment,
pg_ctl -o "-c unix_socket_directories=/tmp/$LOGNAME/sockets" -D $PGDATA -l /tmp/$LOGNAME/logfile start
createdb -h /tmp/$LOGNAME/sockets $hshep002_db


initDebugger

#include <avr/io.h>

int main(void){
	DDRB = 0xFF; // Configure port B's 8 pins as outputs
	PORTB = 0x00; // Initialize PORTB output to 0’s
	while(1){
		PORTB = 0x0F; // Writes port B's 8 pins with 00001111
	}
	return 1;
}

tests = [ {'description': 'PINA: 0x00 => PORTB: 0x02',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTB',0x02)],
    },
    {'description': 'PINA: 0x02 => PORTB: 0x02',
    'steps': [ {'inputs': [('PINA',0x02)], 'iterations': 5 } ],
    'expected': [('PORTB',0x02)],
    },
    {'description': 'PINA: 0x01 => PORTB: 0x01',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
    'expected': [('PORTB',0x01)],
    },
    ]
watch = ['main::tempA','PORTB']


int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    unsigned char tempA;
    /* Insert your solution below */
    while (1) {
        tempA = PINA;
        PORTB = (tempA & 0x01) ? 0x01 : 0x02;
    }
    return 1;
}



INITGDBDEBUGGER=$(PATHT)initDebugger.gdb
GDBTESTING=-batch -x $(GDBCOMMANDS) -x $(INITGDBDEBUGGER) -x $(GDBSCRIPT)
GDBDEBUGGING=-x $(GDBCOMMANDS) -x $(INITGDBDEBUGGER)
# Python testing
PYTESTRUNNER=$(PATHT)testRunner.py
PYTESTS=$(PATHT)tests.py
PYTESTCMD=runTests
PYTESTING=-batch -x $(PYTESTS) -x $(PYTESTRUNNER) -ex $(PYTESTCMD)
PYDEBUGGING=-x $(PYTESTS) -x $(PYTESTRUNNER)
# Programmer
PROGRAM=avrdude
PROGRAMMER=atmelice_isp
MEMORY=flash
#mem:op:file where op is (w)rite, (r)ead, (v)erify; performed in the order specified
VERBOSITY=#-v -v ... etc. to have more verbose output. Normal output is usually enough unless something goes wrong.
ADDVERBOSITY=$(info Add additional -v to the \"avrdude -c ...\" command above for more details on the error)
HIGH=hfuse
HDEFAULT=0x99
H120=0xD9
HTXT=hfuse.txt
JTAGEN=0x40
LOW=lfuse
LDEFAULT=0x42
L120=0xC2
HEX=h
RAW=m

.PHONY: defaultFuses verifyFuses fuses disableJTAG clean test program debug pytest pydebug
all: $(PATHB)main.hex

verifyFuses:
        $(PROGRAM) -c $(PROGRAMMER) -p $(MMCU) $(VERBOSITY) -U $(HIGH):r:-:$(HEX) -U $(LOW):r:-:$(HEX) || $(ADDVERBOSITY)

defaultFuses:
        $(PROGRAM) -c $(PROGRAMMER) -p $(MMCU) $(VERBOSITY) -U $(HIGH):w:$(HDEFAULT):$(RAW) -U $(LOW):w:$(LDEFAULT):$(RAW) || $(ADDVERBOSITY)

fuses:
        $(PROGRAM) -c $(PROGRAMMER) -p $(MMCU) $(VERBOSITY) -U $(HIGH):w:$(H120):$(RAW) -U $(LOW):w:$(L120):$(RAW) || $(ADDVERBOSITY)

# Disable just the JTAG fuse
disableJTAG:
        $(PROGRAM) -c $(PROGRAMMER) -p $(MMCU) $(VERBOSITY) -U $(HIGH):r:$(HTXT):$(HEX) || $(ADDVERBOSITY)
        @read -n 4 c < $(HTXT);echo -n "0x" > $(HTXT);echo "obase=16; $$(($$c | $(JTAGEN)))" | bc >> $(HTXT)
        $(PROGRAM) -c $(PROGRAMMER) -p $(MMCU) $(VERBOSITY) -U $(HIGH):w:$(HTXT):$(HEX)
        @rm -f $(HTXT)

program: $(PATHB)main.hex
                                          
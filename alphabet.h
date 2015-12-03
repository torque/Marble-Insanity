#pragma once

/*
 AAAA
F    B
F    B
 GGGG
E    C
E    C
 DDDD  DP
      ABCDEFG
A: 0b01110111
B: 0b01111111
C: 0b01001110
D: 0b01111110
E: 0b01001111
F: 0b01000111
G: 0b01011110
H: 0b00110111
I: 0b00110000
J: 0b00111000
L: 0b00001110
N: 0b01110110
O: 0b01111110
P: 0b01100111
R: 0b01110111
S: 0b01011011
T: 0b01110000
U: 0b00111110
Y: 0b00111011
Z: 0b01101101
0: 0b01111110
1: 0b00110000
2: 0b01101101
3: 0b01111001
4: 0b00110011
5: 0b01011011
6: 0b01011111
7: 0b01110000
8: 0b01111111
9: 0b01111011
*/

static inline uint8_t charToDisplay( unsigned char letter ) {
	switch( letter ) {
		case 'A': return 0b01110111;
		case 'B': return 0b01111111;
		case 'C': return 0b01001110;
		case 'D': return 0b01111110;
		case 'E': return 0b01001111;
		case 'F': return 0b01000111;
		case 'G': return 0b01011110;
		case 'H': return 0b00110111;
		case 'I': return 0b00110000;
		case 'J': return 0b00111000;
		// case 'K':
		case 'L': return 0b00001110;
		// case 'M':
		case 'N': return 0b01110110;
		case 'O': return 0b01111110;
		case 'P': return 0b01100111;
		// case 'Q':
		case 'R': return 0b01110111;
		case 'S': return 0b01011011;
		case 'T': return 0b01110000;
		case 'U': return 0b00111110;
		// case 'V':
		// case 'W':
		// case 'X':
		case 'Y': return 0b00111011;
		case 'Z': return 0b01101101;
		case 0:
		case '0': return 0b01111110;
		case 1:
		case '1': return 0b00110000;
		case 2:
		case '2': return 0b01101101;
		case 3:
		case '3': return 0b01111001;
		case 4:
		case '4': return 0b00110011;
		case 5:
		case '5': return 0b01011011;
		case 6:
		case '6': return 0b01011111;
		case 7:
		case '7': return 0b01110000;
		case 8:
		case '8': return 0b01111111;
		case 9:
		case '9': return 0b01111011;
		default:	return 0b00000000;
	}
}

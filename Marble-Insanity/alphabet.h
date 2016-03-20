#pragma once

static inline uint8_t charToDisplay( unsigned char letter ) {
	switch( letter ) {
		// binary integer literals are a gnu extension and are not part of
		// the C++ standard. Arduino IDE compiles with --std=gnu++11 by
		// default though, so usage here is fine. Alternately, it would be
		// trivial to convert these literals to hexadecimal.
		/*
		 AAAA
		F    B
		F    B
		 GGGG
		E    C
		E    C
		 DDDD  DP
		                    ABCDEFG
		*/
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

#include "Buzzer.hpp"
#include "notes.h"
#include "LoopTime.hpp"

Buzzer *Buzzer::buzzer = nullptr;

Buzzer::Buzzer( void ) {
	if ( Buzzer::buzzer ) return;
	Buzzer::buzzer = this;
}

// these are all very similar, except they will play different note patterns.
// THIS IS AN EXTREMELY USEFUL FUNCTION
void Buzzer::play( BuzzerJingle jingle ) {
	switch ( jingle ) {
		case Buzzer_CoinDetected: {
			break;
		}
		case Buzzer_Victory: {
			break;
		}
		case Buzzer_GameOver: {
			break;
		}
		default: {
			return;
		}
	}
	playing = true;
	startTime = LoopTime::time;
	return;
}

void Buzzer::update( void ) {
	unsigned long elapsedTime = LoopTime::time - startTime;
}

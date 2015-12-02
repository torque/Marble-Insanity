#include "Buzzer.hpp"
#include "notes.h"
#include "LoopTime.hpp"

// these are all very similar, except they will play different note patterns.
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

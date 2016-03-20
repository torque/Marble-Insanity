#include <Arduino.h>

#include "CoinSensor.hpp"
#include "LoopTime.hpp"
#include "Timer.hpp"

#define CoinSensorPin A0
#define CoinThreshold 75

void CoinSensor::waitForCoin( void ) {
	bool toggle = true;
	char add[4] = { 'A', 'D', 'D', ' ' };
	char coin[4] = { 'C', 'O', 'I', 'N' };
	Timer::timer->displayCharacters( add );
	unsigned long now = LoopTime::time;
	for ( ;; ) {
		LoopTime::update( );
		if ( LoopTime::time - now > 1000 ) {
			now = LoopTime::time;
			toggle = !toggle;
			if ( toggle )
				Timer::timer->displayCharacters( add );
			else
				Timer::timer->displayCharacters( coin );
		}
		int coinReading = analogRead( CoinSensorPin );
		if ( coinReading < CoinThreshold )
			break;
	}
	// Buzzer::buzzer->play( Buzzer_CoinDetected );
}

#include <Arduino.h>

#include "CoinSensor.hpp"
#include "LoopTime.hpp"
#include "Timer.hpp"

#define CoinSensorPin A0
#define CoinThreshold 75

void CoinSensor::waitForCoin( void ) {
	char coin[4] = { 'C', 'O', 'I', 'N' };
	Timer::timer->displayCharacters( coin );
	for ( ;; ) {
		LoopTime::update( );
		int coinReading = analogRead( CoinSensorPin );
		Serial.println( "value: " + String( coinReading ) );
		if ( coinReading < CoinThreshold )
			break;
	}
}

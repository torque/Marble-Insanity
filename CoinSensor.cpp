#include <Arduino.h>

#include "CoinSensor.hpp"

#define CoinSensorPin A0
#define CoinThreshold 75

CoinSensor::CoinSensor( Buzzer *buzzer ) {
	this->buzzer = buzzer;
}

void CoinSensor::waitForCoin( void ) {
	for ( ;; ) {
		int coinReading = analogRead( CoinSensorPin );
		Serial.println( "value: " + String( coinReading ) );
		if ( coinReading < 75 )
			break;
	}
}

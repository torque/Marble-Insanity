#include <Arduino.h>

#include "VictorySensor.hpp"

#define SensorPin A1
#define SensorThreshold 500

VictorySensor::VictorySensor( void ) {
	pinMode( SensorPin, INPUT );
}

bool VictorySensor::update( void ) {
	int value = analogRead( SensorPin );
	if ( value < SensorThreshold )
		return true;
	return false;
}

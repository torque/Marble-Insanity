#include <Arduino.h>

#include "LoopTime.hpp"

unsigned long LoopTime::time = 0;

void LoopTime::update( void ) {
	LoopTime::time = millis( );
}

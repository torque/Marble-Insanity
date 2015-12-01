#include "LoopTime.hpp"
#include "Buzzer.hpp"
#include "Timer.hpp"

Buzzer *buzzer;
Timer *timer;

void setup( void ) {
	buzzer = new Buzzer( );
	timer = new Timer( buzzer );
}

void loop( void ) {
	// coin check routine

	// gameplay routine
	LoopTime::update( );
	timer->startCountdown( );
	while ( timer->update( ) ) {
		// read joystick inputs, write servos, check victory condition
		LoopTime::update( );
	}
	// game over routine
}

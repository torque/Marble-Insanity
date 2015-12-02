#include "AttitudeControl.hpp"

#define LevelPitch (69-90)
#define LevelRoll (80-90)

AttitudeControl::AttitudeControl( AttitudeAngle angle, Nunchuck *nunchuck ) : type(angle) {
	servo = new Servo( );
	this->nunchuck = nunchuck;
	switch ( angle ) {
		case Pitch: {
			// frequency bounds determined empirically.
			servo->attach( angle, 620, 2200 );
			break;
		}
		case Roll: {
			servo->attach( angle, 700, 2350 );
			break;
		}
	}
}

void AttitudeControl::update( void ) {
	switch ( type ) {
		case Pitch: {
			servo->write( LevelPitch + nunchuck->pitchDegrees( ) );
			break;
		}
		case Roll: {
			servo->write( LevelRoll + nunchuck->rollDegrees( ) );
			break;
		}
	}
}

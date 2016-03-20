#pragma once

#include <Servo.h>

#include "Nunchuck.hpp"

class AttitudeControl {
	private:
		Servo *pitch;
		Servo *roll;
		Nunchuck *nunchuck;

	public:
		AttitudeControl( Nunchuck *nunchuck );
		void update( void );
		// level the platform
		void zero( void );
		// roll the ball back to the start
		void reset( void );
};

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
		void reset( void );
};

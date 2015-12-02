#pragma once

#include <Servo.h>

#include "Nunchuck.hpp"

typedef enum {
	Pitch = 9,
	Roll
} AttitudeAngle;

class AttitudeControl {
	private:
		Servo *servo;
		Nunchuck *nunchuck;
		AttitudeAngle type;
	public:
		AttitudeControl( AttitudeAngle angle, Nunchuck *nunchuck );
		void update( void );
};

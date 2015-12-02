#pragma once

class Nunchuck {
	private:
		uint8_t joyXZero, joyYZero;
		float joyXDegreeUp, joyXDegreeDown, joyYDegreeUp, joyYDegreeDown;
		void write( uint8_t registerAddress, uint8_t value );

	public:
		uint8_t joyX, joyY;

		Nunchuck( void );
		void calibrate( void );
		void updateJoystick( void );
		int pitchDegrees( void );
		int rollDegrees( void );
};

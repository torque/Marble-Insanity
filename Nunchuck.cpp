#include <Arduino.h>
#include <Wire.h>

#include "Nunchuck.hpp"

#define NunchuckAddress 0x52
#define zeroX 123
#define zeroY

void Nunchuck::write( uint8_t registerAddress, uint8_t value ) {
	Wire.beginTransmission( NunchuckAddress );
	Wire.write( registerAddress );
	Wire.write( value );
	Wire.endTransmission( );
}

Nunchuck::Nunchuck( void ) {
	Wire.begin( );
	// magic initialization bytes
	write( 0xF0, 0x55 );
	write( 0xFB, 0x00 );
}

#define ReasonablyCentered 5
#define ReasonablyMax 70
void Nunchuck::calibrate( void ) {
	// the first couple of values can be shoddy, so throw them out.
	uint8_t joyXMin, joyXMax, joyYMin, joyYMax;

	for ( int i = 0; i < 10; i++ ) {
		updateJoystick( );
		delay( 1 );
	}
	joyXMin = joyXZero = joyXMax = joyX;
	joyYMin = joyYZero = joyYMax = joyY;
	Serial.println( "Calibration starting. xZero: " + String(joyXZero) + ", yZero: " + String(joyYZero) );
	int loops = 0;
	// bitfield 0b0000LBRT
	//                8421
	char calibrateMessage[4] = { 'C', 'A', 'L', '0' };
	Timer::timer->displayCharacters( calibrateMessage );
	uint8_t loopCheck = 0;
	while ( loops < 3 ) {
		delay( 1 );
		LoopTime::update( );
		updateJoystick( );
		joyXMax = max( joyXMax, joyX );
		joyXMin = min( joyXMin, joyX );
		joyYMax = max( joyYMax, joyY );
		joyYMin = min( joyYMin, joyY );
		// top
		if ( (abs( joyX - joyXZero ) < ReasonablyCentered) && (joyY - joyYZero > ReasonablyMax) )
			loopCheck |= 0x1;
		// right
		else if ( (joyX - joyXZero > ReasonablyMax) && (abs( joyY - joyYZero ) < ReasonablyCentered) )
			loopCheck |= 0x2;
		// down
		else if ( (abs( joyX - joyXZero ) < ReasonablyCentered) && (joyY - joyYZero < -ReasonablyMax) )
			loopCheck |= 0x4;
		// left
		else if ( (joyX - joyXZero < -ReasonablyMax) && (abs( joyY - joyYZero ) < ReasonablyCentered) )
			loopCheck |= 0x8;

		if ( loopCheck == 0xF ) {
			calibrateMessage[3] = ++loops;
			Timer::timer->displayCharacters( calibrateMessage );
			loopCheck = 0;
		}
	}
	Serial.println( "Calibration finished. xZero: " + String(joyXZero) + ", yZero: " + String(joyYZero) );
	Serial.println( "                       xMin: " + String(joyXMin) + ",   yMin: " + String(joyYMin) );
	Serial.println( "                       xMax: " + String(joyXMax) + ",  yMax: " + String(joyYMax) );

#define MaxDegreesUp 60.0f
#define MaxDegreesDown 60.0f
	joyYDegreeUp = MaxDegreesUp/(joyYMax - joyYZero);
	joyYDegreeDown = MaxDegreesDown/(joyYMin - joyYZero);
	joyXDegreeUp = MaxDegreesUp/(joyXMax - joyXZero);
	joyXDegreeDown = MaxDegreesDown/(joyXMin - joyXZero);
#undef MaxDegreesUp
#undef MaxDegreesDown
}
#undef ReasonablyCentered
#undef ReasonablyMax

void Nunchuck::updateJoystick( void ) {
	uint8_t data[2] = { 127, 127 };
	Wire.requestFrom( NunchuckAddress, 2 );
	int i = 0;
	for ( ; i < 2 && Wire.available( ); i++ ) {
		data[i] = Wire.read( );
	}
	// if i is less than 2, the read has failed, so don't update.
	if ( i < 2 ) return;
	joyX = data[0];
	joyY = data[1];
	write( 0x00, 0x00 );
}

int Nunchuck::pitchDegrees( void ) {
	if ( joyY > joyYZero )
		return (joyYZero - joyY)*joyYDegreeUp;
	else
		return (joyY - joyYZero)*joyYDegreeDown;
}

int Nunchuck::rollDegrees( void ) {
	// roll is reversed
	if ( joyX > joyXZero )
		return (joyX - joyXZero)*joyXDegreeUp;
	else
		return (joyXZero - joyX)*joyXDegreeDown;
}

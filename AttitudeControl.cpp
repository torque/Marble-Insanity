#include <Arduino.h>
#include "AttitudeControl.hpp"

#define LevelPitch 72
#define LevelRoll 72

#define PitchPin 9
#define RollPin 10

AttitudeControl::AttitudeControl( Nunchuck *nunchuck ) {
	pitch = new Servo( );
	roll = new Servo( );
	this->nunchuck = nunchuck;
	// frequency bounds determined empirically.
	pitch->attach( PitchPin, 620, 2200 );
	roll->attach( RollPin, 700, 2350 );
}

void AttitudeControl::update( void ) {
	pitch->write( LevelPitch + nunchuck->pitchDegrees( ) );
	roll->write( LevelRoll + nunchuck->rollDegrees( ) );
}

void AttitudeControl::zero( void ) {
	// Serial.println( "Resetting servos" );
	pitch->write( LevelPitch );
	roll->write( LevelRoll );
}

void AttitudeControl::reset( void ) {
	pitch->write( LevelPitch + 60 );
	roll->write( LevelRoll - 60 );
	// somewhat arbitrary. there's no sensor to detect if the ball is at
	// the start.
	delay( 1000 );
	zero( );
}

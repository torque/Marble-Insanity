#include <Arduino.h>

#include "Timer.hpp"
#include "LoopTime.hpp"

#define RoundTime 60e3
#define SlavePin 7

SPISettings Timer::Max7221 = SPISettings( 10000000, MSBFIRST, SPI_MODE0 );

Timer::Timer( Buzzer *buzzer ) : startTime(0) {
	this->buzzer = buzzer;
	// initialize SPI
	pinMode( SlavePin, OUTPUT );
	digitalWrite( SlavePin, HIGH );
	// Pin 10, the uno slave mode select, should already be set to output
	// by the servo library.
	SPI.begin( );
	// Power on
	write( 0x0C, 0x01 );
	// Use the first four digits.
	write( 0x0B, 0x04 );
	// Set intensity lower to use less power.
	write( 0x0A, 0x04 );
	// Code B decode on all four digits.
	write( 0x09, 0x0F );
}

void Timer::reset( void ) {
	startTime = 0;
	// draw 60.00, or possibly ADD COIN
}

void Timer::startCountdown( ) {
	startTime = LoopTime::time;
	// draw 60.00
}

// shouldn't have to worry about overflow, because avr unsigned long is
// 4 bytes, so it takes millis around 50 days (4294967295 ms) to
// overflow.
bool Timer::update( ) {
	// drop down to four signed bytes, because the round is over when
	// timeRemaining is negative.
	long timeRemaining = (RoundTime + startTime - LoopTime::time);
	if ( timeRemaining < 0 ) {
		// Buzzer::buzzer->play( Buzzer_GameOver );
		// draw or blink 00.00
		Serial.println("TIME UP");
		return false;
	}
	displayTime( timeRemaining );
	return true;
}

void Timer::displayTime( long timeRemaining ) {
	// want to display seconds and centiseconds. XX.XX least significant
	// bit is first element. First digit on display is most significant
	// bit. Display is wired backwards to make rightmost digit be the
	// least significant.
	uint8_t components[4] = { 0 };
	for ( int i = 0; i < 4; i++ ) {
		timeRemaining /= 10;
		components[i] = timeRemaining % 10;
	}
	// most significant bit sets decimal point for B-Code.
	components[2] |= 0x80;
	// Serial.println( String(components[3]) + ", " + String(components[2]) + ", " + String(components[1]) + ", " + String(components[0]) );
	for ( int i = 0; i < 4; i++ )
		write( i + 1, components[i] );
}

void Timer::write( uint8_t registerAddress, uint8_t value ) {
	// Might be able to begin transaction much
	SPI.beginTransaction( Timer::Max7221 );
	digitalWrite( SlavePin, LOW );
	SPI.transfer( registerAddress );
	SPI.transfer( value );
	digitalWrite( SlavePin, HIGH );
	SPI.endTransaction( );
}

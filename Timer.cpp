#include <SPI.h>

#include "Timer.hpp"

#define RoundTime 60e3
#define SlavePin 7

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
		buzzer->gameOver( );
		// draw or blink 00.00
		return false;
	}
	displayTime( timeRemaining );
}

void Timer::displayTime( long timeRemaining ) {
	// munge numbers
}

void Timer::write( uint8_t address, uint8_t value ) {
	// Might be able to begin transaction much
	SPI.beginTransaction( Timer::Max7221 );
	digitalWrite( SlaveSelect, LOW );
	SPI.transfer( address );
	SPI.transfer( value );
	digitalWrite( SlaveSelect, HIGH );
	SPI.endTransaction( );
}

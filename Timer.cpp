#include <Arduino.h>

#include "Buzzer.hpp"
#include "Timer.hpp"
#include "LoopTime.hpp"
#include "alphabet.h"

#define RoundTime 60e3
#define SlavePin 7

SPISettings Timer::Max7221 = SPISettings( 10000000, MSBFIRST, SPI_MODE0 );
Timer *Timer::timer = nullptr;

Timer::Timer( void ) : startTime(0), bDecode(true) {
	// initialize SPI
	Timer::timer = this;
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
	// shut off b decoding, which appears to be on by default.
	setBDecode( false );
}

void Timer::blank( void ) {
	// blank the display forcefully
	setBDecode( false );
	for ( int i = 1; i < 5; i++ )
		write( i, 0x00 );
}

void Timer::reset( void ) {
	startTime = 0;
	// draw 60.00, or possibly ADD COIN
}

void Timer::startCountdown( ) {
	startTime = LoopTime::time;
	// turn B-Code decoding on.
	setBDecode( true );
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
	for ( int i = 0; i < 4; i++ )
		write( i + 1, components[i] );
}

void Timer::displayCharacters( char characters[4] ) {
	setBDecode( false );
	for ( int i = 0; i < 4; i++ ) {
		// display is backwards, so the first digit is the rightmost one.
		write( 4 - i, charToDisplay( characters[i] ) );
	}
}

void Timer::setBDecode( bool on ) {
	if ( on == bDecode ) return;
	bDecode = on;
	if ( on )
		write( 0x09, 0x0F );
	else
		write( 0x09, 0x00 );
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

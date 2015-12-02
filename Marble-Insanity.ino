#include "Nunchuck.hpp"
#include "AttitudeControl.hpp"
#include "LoopTime.hpp"
#include "Buzzer.hpp"
#include "Timer.hpp"

#define sleep delay
#define usleep delayMicroseconds
// #include "Buzzer.hpp"
// #include "Timer.hpp"

Nunchuck *nunchuck;
Buzzer *buzzer;
Timer *timer;
AttitudeControl *servos;

void setup( void ) {
	Serial.begin( 115200 );
	nunchuck = new Nunchuck( );
	// buzzer = new Buzzer( );
	timer = new Timer( buzzer );
	servos = new AttitudeControl( nunchuck );
	servos->reset( );
	nunchuck->calibrate( );
}

void loop( void ) {
	// coin check routine

	// gameplay routine
	LoopTime::update( );
	timer->startCountdown( );
	while ( timer->update( ) ) {
		// read joystick inputs, write servos, check victory condition
		nunchuck->updateJoystick( );
		servos->update( );
		// Serial.println( "pitch: " + String( nunchuck->pitchDegrees( ) ) + ", roll: " + String( nunchuck->rollDegrees( ) ) );
		sleep( 5 );
		LoopTime::update( );
	}

	servos->reset( );
	// game over routine
}

// void loop( void ) {
// 	nunchuck->updateJoystick( );
// 	// Serial.println( "x: " + String( nunchuck->joyX ) + ", y: " + String( nunchuck->joyY ) );
// 	// Serial.println( "pitch: " + String( nunchuck->pitchDegrees( ) ) + ", roll: " + String( nunchuck->rollDegrees( ) ) );
// 	sleep(500);
// }

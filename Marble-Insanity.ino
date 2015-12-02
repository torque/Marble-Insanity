#include "Nunchuck.hpp"
#include "AttitudeControl.hpp"
#include "LoopTime.hpp"
#define sleep delay
#define usleep delayMicroseconds
// #include "Buzzer.hpp"
// #include "Timer.hpp"

Nunchuck *nunchuck;
// Buzzer *buzzer;
// Timer *timer;
AttitudeControl *pitch;
AttitudeControl *roll;

void setup( void ) {
	Serial.begin( 115200 );
	nunchuck = new Nunchuck( );
	nunchuck->calibrate( );
	// buzzer = new Buzzer( );
	// timer = new Timer( buzzer );
	pitch = new AttitudeControl( Pitch, nunchuck );
	roll = new AttitudeControl( Roll, nunchuck );
}

void loop( void ) {
	// coin check routine

	// gameplay routine
	LoopTime::update( );
	// timer->startCountdown( );
	// while ( timer->update( ) ) {
		// read joystick inputs, write servos, check victory condition
		nunchuck->updateJoystick( );
		pitch->update( );
		roll->update( );
		LoopTime::update( );
		// Serial.println( "pitch: " + String( nunchuck->pitchDegrees( ) ) + ", roll: " + String( nunchuck->rollDegrees( ) ) );
		sleep( 1 );
	// }
	// game over routine
}

// void loop( void ) {
// 	nunchuck->updateJoystick( );
// 	// Serial.println( "x: " + String( nunchuck->joyX ) + ", y: " + String( nunchuck->joyY ) );
// 	// Serial.println( "pitch: " + String( nunchuck->pitchDegrees( ) ) + ", roll: " + String( nunchuck->rollDegrees( ) ) );
// 	sleep(500);
// }

#include "Nunchuck.hpp"
#include "AttitudeControl.hpp"
#include "CoinSensor.hpp"
#include "LoopTime.hpp"
#include "Buzzer.hpp"
#include "Timer.hpp"
#include "VictorySensor.hpp"

#define sleep delay
#define usleep delayMicroseconds
// #include "Buzzer.hpp"
// #include "Timer.hpp"

Nunchuck *nunchuck;
Buzzer *buzzer;
Timer *timer;
AttitudeControl *servos;
CoinSensor *coinSensor;
VictorySensor *victorySensor;

void setup( void ) {
	Serial.begin( 115200 );
	nunchuck = new Nunchuck( );
	// buzzer = new Buzzer( );
	coinSensor = new CoinSensor( );
	victorySensor = new VictorySensor( );
	timer = new Timer( );
	timer->blank( );
	servos = new AttitudeControl( nunchuck );
	servos->zero( );
	nunchuck->calibrate( );
}

void loop( void ) {
	// coin check routine
	coinSensor->waitForCoin( );
	// gameplay routine
	LoopTime::update( );
	timer->startCountdown( );
	while ( timer->update( ) ) {
		// read joystick inputs, write servos, check victory condition
		nunchuck->updateJoystick( );
		servos->update( );
		if ( victorySensor->update( ) ) {
			victory( );
			break;
		}
		// Serial.println( "pitch: " + String( nunchuck->pitchDegrees( ) ) + ", roll: " + String( nunchuck->rollDegrees( ) ) );
		sleep( 5 );
		LoopTime::update( );
	}

	servos->reset( );
	// game over routine
}

void victory( void ) {
	unsigned long startTime = LoopTime::time;
	bool displayOn = true;
	// run for 1 second
	while ( LoopTime::time - startTime < 5000 ) {
		LoopTime::update( );
		sleep( 1000 );
	}
}

// void loop( void ) {
// 	nunchuck->updateJoystick( );
// 	// Serial.println( "x: " + String( nunchuck->joyX ) + ", y: " + String( nunchuck->joyY ) );
// 	// Serial.println( "pitch: " + String( nunchuck->pitchDegrees( ) ) + ", roll: " + String( nunchuck->rollDegrees( ) ) );
// 	sleep(500);
// }

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
	nunchuck->waitForInput( );
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

	timer->reset( );
	servos->reset( );
	// game over routine
}

void victory( void ) {
	char goal[4] = { 'G', 'O', 'A', 'L' };
	timer->displayCharacters( goal );
	sleep( 5000 );
}

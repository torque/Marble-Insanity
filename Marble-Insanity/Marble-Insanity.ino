#include "Nunchuck.hpp"
#include "AttitudeControl.hpp"
#include "CoinSensor.hpp"
#include "LoopTime.hpp"
#include "Buzzer.hpp"
#include "Timer.hpp"
#include "VictorySensor.hpp"

#define sleep delay
#define usleep delayMicroseconds

Nunchuck *nunchuck;
Buzzer *buzzer;
Timer *timer;
AttitudeControl *servos;
CoinSensor *coinSensor;
VictorySensor *victorySensor;

void setup( void ) {
	nunchuck = new Nunchuck( );
	// buzzer = new Buzzer( );
	coinSensor = new CoinSensor( );
	victorySensor = new VictorySensor( );
	timer = new Timer( );
	timer->blank( );
	servos = new AttitudeControl( nunchuck );
	// Level table
	servos->zero( );
	// Calibrate nunchuck
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
		sleep( 5 );
		LoopTime::update( );
	}

	// game over routine
	timer->reset( );
	servos->reset( );
}

void victory( void ) {
	char goal[4] = { 'G', 'O', 'A', 'L' };
	timer->displayCharacters( goal );
	sleep( 5000 );
}

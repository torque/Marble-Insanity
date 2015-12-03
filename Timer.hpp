#pragma once

#include <SPI.h>

#include "Buzzer.hpp"

class Timer {
	private:
		static SPISettings Max7221;
		unsigned long startTime;
		void displayTime( long );
		void write( uint8_t registerAddress, uint8_t value );

	public:
		void reset( void );
		void startCountdown( void );
		// returns whether or not the round has ended.
		bool update( void );
};

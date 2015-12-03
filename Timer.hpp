#pragma once

#include <SPI.h>

class Timer {
	private:
		static SPISettings Max7221;
		bool bDecode;
		unsigned long startTime;
		void displayTime( long );
		void write( uint8_t registerAddress, uint8_t value );
		inline void setBDecode( bool on );

	public:
		static Timer *timer;

		Timer( void );
		void reset( void );
		void startCountdown( void );
		// returns whether or not the round has ended.
		bool update( void );
		void displayCharacters( char characters[4] );
};

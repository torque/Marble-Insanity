#pragma once

class Timer {
	private:
		static SPISettings Max7221( 10000000, MSBFIRST, SPI_MODE0 );
		Buzzer *buzzer;
		unsigned long startTime;
		void displayTime( long );
		void write( uint8_t address, uint8_t value );

	public:
		Timer( Buzzer *buzzer );
		void reset( void );
		void startCountdown( unsigned long );
		// returns whether or not the round has ended.
		bool update( unsigned long );
};

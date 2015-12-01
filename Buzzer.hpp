#pragma once

typedef enum {
	Buzzer_CoinDetected,
	Buzzer_Victory,
	Buzzer_GameOver
} BuzzerJingle;

class Buzzer {
	private:
		unsigned long startTime;
	public:
		bool playing = false;
		void play( BuzzerJingle );
		void update( void );
};

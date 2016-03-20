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
		static Buzzer *buzzer;
		bool playing = false;
		Buzzer( void );
		void play( BuzzerJingle );
		void update( void );
};

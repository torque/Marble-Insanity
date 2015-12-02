#pragma once

#include "Buzzer.hpp"

class CoinSensor {
	private:
		Buzzer *buzzer;
	public:
		CoinSensor( Buzzer *buzzer );
		void waitForCoin( void );
};

#ifndef DRYER_H
#define DRYER_H

#include "Machine.h"

class Dryer: public Machine
{	
	public:
		Dryer(int drumSize, MachineCommunication& com);
		virtual ~Dryer();
		int GetTemperature();

		
	private:
		int temperature;
		void TakeInAir();
		void Heat(int temperature);
};

#endif

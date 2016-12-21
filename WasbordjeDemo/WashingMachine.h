#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "Machine.h"

class WashingMachine: public Machine
{	
	public:
		WashingMachine(int drumSize);
		int getWaterlevel();
		int getTemperature();

		private:
		int waterlevel;
		int temperature;
		void TakeWater(int waterlevel);
		void Sink();
		void Heat(int temperature);
};

#endif

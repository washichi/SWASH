#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "Machine.h"

class WashingMachine: public Machine
{	
	public:
		WashingMachine(int drumSize);
    	~WashingMachine();
    bool Start(char program);
		int GetWaterlevel();
		int GetTemperature();

		private:
    int temperature;
		int waterlevel;		
		bool TempControl(int temp);
    bool Program();
		void TakeWater(int waterlevel);
		void Sink();
		void Heat(int temperature);
};

#endif

#ifndef STEAMMACHINE_H
#define STEAMMACHINE_H

#include "Machine.h"

class SteamMachine: public Machine
{	
	public:
		SteamMachine(int drumSize, MachineCommunication& com);
		virtual ~SteamMachine();
		int GetPressure();
		int getTemperature();


		
	private:
		int temperature;
		int pressure;
		void ProduceSteam();
		void Heat(int temperature);
};

#endif

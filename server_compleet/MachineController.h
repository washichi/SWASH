#pragma once

#include "Machine.h"

class MachineController{
	public:
		MachineController();
		void AddMachine(int type);
		bool GetBusyWasher();
		bool StartWasher(char program);
		bool GetBusyDryer();
		bool StartDryer(char program);
		bool GetBusyCentrifuge();
		bool StartCentrifuge(char program);
		bool GetBusySteamer();
		bool StartSteamer(char program);
	
	private:
		std::vector<Machine> washers;
		std::vector<Machine> dryers;
		std::vector<Machine> centrifuges;
		std::vector<Machine> steamers;
	
};

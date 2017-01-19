#pragma once

#include "Machine.h"

class MachineController{
	public:
		MachineController();
		void AddMachine(int type);
		bool GetBusyWasher();
		void StartWasher(std::string program);
		bool GetBusyDryer();
		void StartDryer(std::string program);
		bool GetBusyCentrifuge();
		void StartCentrifuge(std::string program);
		bool GetBusySteamer();
		void StartSteamer(std::string program);
	
	private:
		std::vector<Machine> washers;
		std::vector<Machine> dryers;
		std::vector<Machine> centrifuges;
		std::vector<Machine> steamers;
	
};

#include "MachineController.h"

MachineController::MachineController()
{
	
}

void MachineController::AddMachine(int type)
{
	Machine* toAdd;
	switch(type) {
		case 1: toAdd = new Machine("wasmachine");
			washers.push_back(*toAdd);
			break;
		case 2: toAdd = new Machine("dryer");
			dryers.push_back(*toAdd);
			break;
		case 3: toAdd = new Machine("steamer");
			steamers.push_back(*toAdd);
			break;
		case 4: toAdd = new Machine("centrifuge");
			centrifuges.push_back(*toAdd);
			break;
	}
}

bool MachineController::GetBusyWasher()
{
	//printf("Washerlist size %i\n", washers.size());
	for(unsigned int i=0; i<washers.size(); i++)
	{
		if(washers.at(i).GetBusy())
		{
			return true;
		}
	}
	return false;
}

void MachineController::StartWasher(std::string program)
{
	if(!GetBusyWasher())
	{
		int command = washers.at(0).StartProgram(program);
		printf("Washer started program %s, command: %i \n", program.c_str(), command);
	}
	else
	{
		printf("Washer is busy\n");
	}
}

bool MachineController::GetBusyDryer()
{
	//printf("dryers size %i\n", dryers.size());
	for(unsigned int i=0; i<dryers.size(); i++)
	{
		if(dryers.at(i).GetBusy())
		{
			return true;
		}
	}
	return false;
}

void MachineController::StartDryer(std::string program)
{
	if(!GetBusyDryer())
	{
		printf("Dryer started program %s\n", program.c_str());
	}
	else
	{
		printf("Dryer is busy\n");
	}
}

bool MachineController::GetBusyCentrifuge()
{
	//printf("Centrifugelist size %i\n", centrifuges.size());
	for(unsigned int i=0; i<centrifuges.size(); i++)
	{
		if(centrifuges.at(i).GetBusy())
		{
			return true;
		}
	}
	return false;
}

void MachineController::StartCentrifuge(std::string program)
{
	if(!GetBusyCentrifuge())
	{
		printf("Centrifuge started program %s\n", program.c_str());
	}
	else
	{
		printf("Centrifuge is busy\n");
	}
}

bool MachineController::GetBusySteamer()
{
	//printf("Steamerlist size %i\n", steamers.size());
	for(unsigned int i=0; i<steamers.size(); i++)
	{
		if(steamers.at(i).GetBusy())
		{
			return true;
		}
	}
	return false;
}

void MachineController::StartSteamer(std::string program)
{
	if(!GetBusySteamer())
	{
		printf("Steamer started program %s\n", program.c_str());
	}
	else
	{
		printf("Steamer is busy\n");
	}
}

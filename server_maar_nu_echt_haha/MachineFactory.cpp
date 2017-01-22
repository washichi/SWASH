#include "MachineFactory.h"

IMachine *MachineFactory::NewMachine(const std::string &name)
{
	if(name == "WAS")
	{
		return new Wasmachine;
	}
	else if(name == "DRY")
	{
		return new Dryer;
	}
	else if(name == "STE")
	{
		return new Steamer;
	}
	else if(name == "CEN")
	{
		return new Centrifuge;
	}
	
    return NULL;
}

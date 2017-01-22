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
    return NULL;
}

#include "Machine.h"

Machine::Machine(std::string type)
{
	type = type;
	busy = false;
	if(type == "wasmachine")
	{
		number = 15;
	}
	else if(type == "dryer")
	{
		number = 18;
	}
	else if(type == "steamer")
	{
		number = 21;
	}
	else if(type == "centrifuge")
	{
		number = 24;
	}
}

std::string Machine::GetType()
{
	return type;
}

bool Machine::GetBusy()
{
	return busy;
}

int Machine::StartProgram(std::string program)
{
	if(busy)
	{
		return -1;
	}
	if(program == "White"){busy = true; return number+0;}
	else if(program == "Black"){busy = true; return number+1;}
	else if(program == "Coloured"){busy = true; return number+2;}
	return -1;
}

void Machine::Stop()
{
	//bla
}

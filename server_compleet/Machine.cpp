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

int Machine::StartProgram(char program)
{
	if(busy)
	{
		return -1;
	}
	switch(program) {
		case 'A': busy = true;
			return number + 0;
			break;
		case 'B': busy = true;
			return number + 1;
			break;
		case 'C': busy = true;
			return number + 2;
			break;
	}
	return -1;
}

void Machine::Stop()
{
	//bla
}

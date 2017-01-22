#include "MachineController.h"

MachineController::MachineController()
{
	machines = new std::vector<IMachine*>;
}

MachineController::~MachineController()
{
	for (unsigned int i =0; i< machines->size();i++)
   {
     delete (*machines)[i];
     (*machines)[i] = NULL;
   } 
	machines->clear();
	delete machines;
}

void MachineController::AddMachine(std::string name, int id)
{
	IMachine* machine = MachineFactory::NewMachine(name);
	machine->Initialize(id);
	machines->push_back(machine);
}

bool MachineController::SendGarmentToMachine(Garment* garment)
{
	
	for(unsigned int i=0; i<machines->size(); i++)
	{
		if(machines->at(i)->AddToProgram(garment))
		{
			return true;
		}
	}
	return false;
}

void MachineController::FinishMachine(int id)
{
	for(unsigned int i = 0; i < machines->size(); i++)
	{
		if(machines->at(i)->GetId() == id)
		{
			machines->at(i)->Finish();
		}
	}
}

void MachineController::Test()
{
	for(unsigned int i = 0; i < machines->size(); i++)
	{
		machines->at(i)->Test();
	}
}

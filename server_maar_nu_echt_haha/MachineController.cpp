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
	machine->SetId(id);
	machines->push_back(machine);
}

void MachineController::Test()
{
	for(unsigned int i = 0; i < machines->size(); i++)
	{
		machines->at(i)->Test();
	}
}

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

bool MachineController::SendGarmentToMachine(Garment* garment)
{
	
	for(unsigned int i=0; i<machines->size(); i++)
	{
		//printf("Send garment with customerID %i, machine %i\n", garment->GetId(), i);
		//stuur naar machine om wasprogramma te berekenen
		//eerst wassen, de rest mag random
		machines->at(i)->CalculateProgram(garment);
	}
	return true;
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

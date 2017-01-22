#include "MachineController.h"

MachineController::MachineController()
{
	machines = new std::vector<IMachine*>;
	finishedGarments = new std::vector<Garment*>;
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
	
	for (unsigned int i =0; i< finishedGarments->size();i++)
   {
     delete (*finishedGarments)[i];
     (*finishedGarments)[i] = NULL;
   } 
	finishedGarments->clear();
	delete finishedGarments;
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
			printf("processed\n");
			return true;
		}
	}
	printf("not processed\n");
	return false;
}

void MachineController::FinishMachine(int id)
{
	for(unsigned int i = 0; i < machines->size(); i++)
	{
		if(machines->at(i)->GetId() == id)
		{
			machines->at(i)->Finish(finishedGarments);
		}
	}
}

void MachineController::CollectFinishedGarments(std::vector<Garment*>* finishedGarmentsVector)
{
	for(unsigned int i = 0; i < finishedGarments->size(); i++)
	{
		finishedGarmentsVector->push_back(finishedGarments->at(i));
	}
	finishedGarments->clear();
}

void MachineController::Test()
{
	for(unsigned int i = 0; i < machines->size(); i++)
	{
		machines->at(i)->Test();
	}
	
	for(unsigned int i = 0; i < finishedGarments->size(); i++)
	{
		printf("Finished Garment with id %i\n", finishedGarments->at(i)->GetId());
	}
}

#include "GarmentController.h"

GarmentController::GarmentController(MachineController* machineptr) 
{
	toBeProcessed = new std::vector<Garment*>;
	this->machineptr = machineptr;
}

GarmentController::~GarmentController()
{
	for (unsigned int i =0; i< toBeProcessed->size();i++)
   {
     delete (*toBeProcessed)[i];
     (*toBeProcessed)[i] = NULL;
   } 
	toBeProcessed->clear();
	delete toBeProcessed;
}

void GarmentController::AddGarment(char const* docname)
{
	Garment* garment = new Garment(docname);
	toBeProcessed->push_back(garment);
}

void GarmentController::Test()
{
	for(unsigned int i = 0; i < toBeProcessed->size(); i++)
	{
		printf("Garment %i with CustomerID %i\n", i+1, toBeProcessed->at(i)->GetId());
	}
	machineptr->Test();
}

void GarmentController::ProcessGarments()
{
	for(unsigned int i = 0; i < toBeProcessed->size(); i++)
	{
		printf("Process Garment %i with CustomerID %i\n", i+1, toBeProcessed->at(i)->GetId());
		machineptr->SendGarmentToMachine(toBeProcessed->at(i));
	}
}

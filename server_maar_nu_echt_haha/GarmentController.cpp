#include "GarmentController.h"

GarmentController::GarmentController(MachineController* machineptr) 
{
	toBeProcessed = new std::vector<Garment*>;
	finishedGarments = new std::vector<Garment*>;
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
	
	for (unsigned int i =0; i< finishedGarments->size();i++)
   {
     delete (*finishedGarments)[i];
     (*finishedGarments)[i] = NULL;
   } 
	finishedGarments->clear();
	delete finishedGarments;
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
		printf("Garment %i with CustomerID %i ready to be processed\n", i+1, toBeProcessed->at(i)->GetId());
	}
	for(unsigned int i = 0; i < finishedGarments->size(); i++)
	{
		printf("Garment %i with CustomerID %i completely finished\n", i+1, finishedGarments->at(i)->GetId());
	}
	machineptr->Test();
}

void GarmentController::ProcessGarments()
{
	for(unsigned int i = 0; i < toBeProcessed->size(); i++)
	{
		if(machineptr->SendGarmentToMachine(toBeProcessed->at(i)))
		{
			toBeProcessed->erase(toBeProcessed->begin()+i);
			i=-1;
		}
	}
}

void GarmentController::ProcessFinishedGarments()
{
	machineptr->CollectFinishedGarments(toBeProcessed);
	for(unsigned int i = 0; i < toBeProcessed->size(); i++)
	{
		if(toBeProcessed->at(i)->GetFinished())
		{
			finishedGarments->push_back(toBeProcessed->at(i));
			toBeProcessed->erase(toBeProcessed->begin()+i);
			i=-1;
		}
	}
	
	for(unsigned int i = 0; i < finishedGarments->size(); i++)
	{
		Garment* garment = finishedGarments->at(i);
		int amountinorderfinished = 0;
		for(unsigned int i = 0; i < finishedGarments->size(); i++)
		{
			if(garment->GetId() == finishedGarments->at(i)->GetId())
			{ amountinorderfinished++; }
			if(garment->GetOrderAmount() == amountinorderfinished)
			{ 
				printf("Order %i is done!\n", garment->GetId()); 
				for(unsigned int i = 0; i < finishedGarments->size(); i++)
				{
					if(garment->GetId() == finishedGarments->at(i)->GetId())
					{
						delete (*finishedGarments)[i];
						finishedGarments->erase(finishedGarments->begin()+i);
					}
				}
				return;
			}
			
		}
	}
}

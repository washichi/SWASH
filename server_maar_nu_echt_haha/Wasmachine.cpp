#include "Wasmachine.h"

void Wasmachine::Test()
{
	printf("Wasmachine test + id %i\n", id);
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     printf("Garment in washer with id %i\n", garmentsInProgram->at(i)->GetId());
   } 
}

void Wasmachine::Initialize(int id)
{
	garmentsInProgram = new std::vector<Garment*>;
	this->id = id;
	this->busy = false;
	this->readyToCalculateProgram = true;
}

Wasmachine::~Wasmachine()
{
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     delete (*garmentsInProgram)[i];
     (*garmentsInProgram)[i] = NULL;
   } 
	garmentsInProgram->clear();
	delete garmentsInProgram;
	
}

int Wasmachine::GetId()
{
	return this->id;
}

bool Wasmachine::AddToProgram(Garment* garment)
{
	if(!garment->GetWasher() || this->busy)
	{
		return false;
	}
	
	if(this->readyToCalculateProgram && GetProgram(garment->GetColor()) != 'Z')
	{
		currentProgram = GetProgram(garment->GetColor());
		readyToCalculateProgram = false;
	}
	
	if(GetProgram(garment->GetColor()) == currentProgram)
	{
		garmentsInProgram->push_back(garment);
		return true;
	}
	return false;
}

void Wasmachine::Finish(std::vector<Garment*>* finishedGarmentsVector)
{
	for(unsigned int i = 0; i<garmentsInProgram->size(); i++)
	{
		garmentsInProgram->at(i)->SetWasher(false);
		finishedGarmentsVector->push_back(garmentsInProgram->at(i));
	}
	garmentsInProgram->clear();
	this->busy = false;
	this->readyToCalculateProgram = true;
}

bool Wasmachine::IsBusy()
{
	return this->busy;
}

char Wasmachine::GetProgram(std::string color)
{
	if(color == "Black"){return 'A';}
	else if(color == "White"){return 'B';}
	else if(color == "Color"){return 'C';}
	else {return 'Z';}
}

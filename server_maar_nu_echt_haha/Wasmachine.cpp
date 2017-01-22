#include "Wasmachine.h"

void Wasmachine::Test()
{
	printf("Wasmachine test + id %i\n", id);
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     printf("Garment in program with id %i\n", garmentsInProgram->at(i)->GetId());
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
		printf("no washer and busy\n");
		return false;
	}
	
	if(this->readyToCalculateProgram)
	{
		currentProgram = GetProgram(garment->GetColor());
		readyToCalculateProgram = false;
		printf("current program %c\n", currentProgram);
	}
	
	if(GetProgram(garment->GetColor()) == currentProgram)
	{
		garmentsInProgram->push_back(garment);
		printf("no washer and busy\n");
		return true;
	}
	printf("end of addtoprogram\n");
	return false;
}

void Wasmachine::Finish(std::vector<Garment*>* finishedGarmentsVector)
{
	for(unsigned int i = 0; i<garmentsInProgram->size(); i++)
	{
		finishedGarmentsVector->push_back(garmentsInProgram->at(i));
	}
	garmentsInProgram->clear();
	printf("Wasmachine met id %i is klaar\n", this->id);
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

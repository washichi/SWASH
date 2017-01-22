#include "Centrifuge.h"

void Centrifuge::Test()
{
	printf("Dryer test + id %i\n", id);
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     printf("Garment in dryer with id %i\n", garmentsInProgram->at(i)->GetId());
   }
}

void Centrifuge::Initialize(int id)
{
	garmentsInProgram = new std::vector<Garment*>;
	this->id = id;
	this->busy = false;
	this->readyToCalculateProgram = true;
}

Centrifuge::~Centrifuge()
{
	
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     delete (*garmentsInProgram)[i];
     (*garmentsInProgram)[i] = NULL;
   } 
	garmentsInProgram->clear();
	delete garmentsInProgram;
}

int Centrifuge::GetId()
{
	return this->id;
}

bool Centrifuge::AddToProgram(Garment* garment)
{
	if(!garment->GetCentrifuge() || this->busy || garment->GetWasher())
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

void Centrifuge::Finish(std::vector<Garment*>* finishedGarmentsVector)
{
	for(unsigned int i = 0; i<garmentsInProgram->size(); i++)
	{
		garmentsInProgram->at(i)->SetCentrifuge(false);
		finishedGarmentsVector->push_back(garmentsInProgram->at(i));
	}
	garmentsInProgram->clear();
	this->busy = false;
	this->readyToCalculateProgram = true;
}

bool Centrifuge::IsBusy()
{
	return this->busy;
}

char Centrifuge::GetProgram(std::string color)
{
	if(color == "Black"){return 'A';}
	else if(color == "White"){return 'B';}
	else if(color == "Color"){return 'C';}
	else {return 'Z';}
}

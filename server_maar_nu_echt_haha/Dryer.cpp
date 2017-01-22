#include "Dryer.h"

void Dryer::Test()
{
	printf("Dryer test + id %i\n", id);
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     printf("Garment in dryer with id %i\n", garmentsInProgram->at(i)->GetId());
   }
}

void Dryer::Initialize(int id)
{
	garmentsInProgram = new std::vector<Garment*>;
	this->id = id;
	this->busy = false;
	this->readyToCalculateProgram = true;
}

Dryer::~Dryer()
{
	
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     delete (*garmentsInProgram)[i];
     (*garmentsInProgram)[i] = NULL;
   } 
	garmentsInProgram->clear();
	delete garmentsInProgram;
}

int Dryer::GetId()
{
	return this->id;
}

bool Dryer::AddToProgram(Garment* garment)
{
	if(!garment->GetDryer() || this->busy || garment->GetWasher())
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

void Dryer::Finish(std::vector<Garment*>* finishedGarmentsVector)
{
	for(unsigned int i = 0; i<garmentsInProgram->size(); i++)
	{
		garmentsInProgram->at(i)->SetDryer(false);
		finishedGarmentsVector->push_back(garmentsInProgram->at(i));
	}
	garmentsInProgram->clear();
	this->busy = false;
	this->readyToCalculateProgram = true;
}

bool Dryer::IsBusy()
{
	return this->busy;
}

char Dryer::GetProgram(std::string color)
{
	if(color == "Black"){return 'A';}
	else if(color == "White"){return 'B';}
	else if(color == "Color"){return 'C';}
	else {return 'Z';}
}

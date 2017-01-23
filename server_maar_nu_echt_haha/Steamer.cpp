#include "Steamer.h"

void Steamer::Test()
{
	printf("Dryer test + id %i\n", id);
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     printf("Garment in dryer with id %i\n", garmentsInProgram->at(i)->GetId());
   }
}

void Steamer::Initialize(int id)
{
	garmentsInProgram = new std::vector<Garment*>;
	this->id = id;
	this->busy = false;
	this->readyToCalculateProgram = true;
}

Steamer::~Steamer()
{
	
	for (unsigned int i =0; i< garmentsInProgram->size();i++)
   {
     delete (*garmentsInProgram)[i];
     (*garmentsInProgram)[i] = NULL;
   } 
	garmentsInProgram->clear();
	delete garmentsInProgram;
}

int Steamer::GetId()
{
	return this->id;
}

bool Steamer::AddToProgram(Garment* garment)
{
	if(!garment->GetSteamer() || this->busy || garment->GetWasher())
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

void Steamer::Finish(std::vector<Garment*>* finishedGarmentsVector)
{
	for(unsigned int i = 0; i<garmentsInProgram->size(); i++)
	{
		garmentsInProgram->at(i)->SetSteamer(false);
		finishedGarmentsVector->push_back(garmentsInProgram->at(i));
	}
	garmentsInProgram->clear();
	this->busy = false;
	this->readyToCalculateProgram = true;
}

bool Steamer::IsBusy()
{
	return this->busy;
}

char Steamer::GetProgram(std::string color)
{
	if(color == "Black"){return 'A';}
	else if(color == "White"){return 'B';}
	else if(color == "Color"){return 'C';}
	else {return 'Z';}
}

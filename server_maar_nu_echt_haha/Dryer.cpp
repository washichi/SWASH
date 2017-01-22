#include "Dryer.h"

void Dryer::Test()
{
	printf("Dryer test + id %i\n", id);
}

void Dryer::Initialize(int id)
{
	this->id = id;
	this->busy = false;
	this->readyToCalculateProgram = true;
}

int Dryer::GetId(int id)
{
	return this->id;
}

bool Dryer::AddToProgram(Garment* garment)
{
	if(garment->GetDryer() && !garment->GetWasher())
	{
		printf("Dryer met id %i test, Garment met id %i\n", this->id, garment->GetId());
	}
	return false;
}

void Dryer::Finish()
{
	printf("Dryer met id%i is klaar\n", this->id);
}

bool Dryer::IsBusy()
{
	return this->busy;
}

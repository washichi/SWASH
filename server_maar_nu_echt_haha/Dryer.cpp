#include "Dryer.h"

void Dryer::Test()
{
	printf("Dryer test + id %i\n", id);
}

void Dryer::SetId(int id)
{
	this->id = id;
}

int Dryer::GetId(int id)
{
	return this->id;
}

void Dryer::CalculateProgram(Garment* garment)
{
	if(garment->GetDryer() && !garment->GetWasher())
	{
		printf("Dryer met id %i test, Garment met id %i\n", this->id, garment->GetId());
	}
}

void Dryer::Finish()
{
	printf("Dryer met id%i is klaar\n", this->id);
}

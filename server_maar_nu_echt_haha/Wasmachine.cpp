#include "Wasmachine.h"

void Wasmachine::Test()
{
	printf("Wasmachine test + id %i\n", id);
}

void Wasmachine::SetId(int id)
{
	this->id = id;
}

int Wasmachine::GetId()
{
	return this->id;
}

void Wasmachine::CalculateProgram(Garment* garment)
{
	if(garment->GetWasher())
	{
		if(garment->GetColor() == "Black")
		{
			printf("Wasmachine met id %i test, Garment met id %i, wasprogramma A\n", this->id, garment->GetId());
		}
		else if(garment->GetColor() == "White")
		{
			printf("Wasmachine met id %i test, Garment met id %i, wasprogramma B\n", this->id, garment->GetId());
		}
		else if(garment->GetColor() == "Color")
		{
			printf("Wasmachine met id %i test, Garment met id %i, wasprogramma C\n", this->id, garment->GetId());
		}
		else
		{
			printf("Invalid values to create a washprogram, incorrect spelling or something\n");
		}
	}
}

void Wasmachine::Finish()
{
	printf("Wasmachine met id %i is klaar\n", this->id);
}

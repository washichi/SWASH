#include "IMachine.h"

void IMachine::IMachine::Test()
{
	
}

void IMachine::SetId(int id)
{
	this->id = id;
}

int IMachine::GetId()
{
	return this->id;
}

void IMachine::CalculateProgram(Garment* garment)
{
	printf("No machine found for garment with customerID %i\n", garment->GetId());
}

void IMachine::Finish()
{
	printf("Incorrect implementation of abstraction, should not be called\n");
}

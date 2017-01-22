#include "IMachine.h"

void IMachine::IMachine::Test()
{
	
}

void IMachine::Initialize(int id)
{
	this->id = id;
	this->busy = false;
	this->readyToCalculateProgram = true;
}

int IMachine::GetId()
{
	return this->id;
}

bool IMachine::AddToProgram(Garment* garment)
{
	printf("No machine found for garment with customerID %i\n", garment->GetId());
	return false;
}

void IMachine::Finish()
{
	printf("Incorrect implementation of abstraction, should not be called\n");
}

bool IMachine::IsBusy()
{
	return this->busy;
}

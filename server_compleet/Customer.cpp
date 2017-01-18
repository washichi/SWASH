#include "Customer.h"

Customer::Customer(int id)
: id(id)
, numberOfGarments(0)
{
}

std::vector<Garment> Customer::GetGarments()
{
	return garments;
}

Garment* Customer::GetFirstGarment()
{
	return &garments.at(0);
}

int Customer::GetNumberOfGarments()
{
	return numberOfGarments;
}

int Customer::GetId()
{
	return id;
}

void Customer::AddGarment(Garment* garment)
{
	garments.push_back(*garment);
	numberOfGarments++;
}

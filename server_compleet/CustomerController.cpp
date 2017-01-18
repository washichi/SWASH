#include "CustomerController.h"

CustomerController::CustomerController()
{
}

void CustomerController::AddGarmentToCustomer(Garment* garment)
{
	Customer* check = GetCustomerById(garment->GetId());
	if(check == NULL)
	{
		printf("customer does not exist yet\n");
		Customer c(garment->GetId());
		customers.push_back(c);
		printf("customer added!\n");
		check = GetCustomerById(garment->GetId());
	}
	check->AddGarment(garment);
	printf("garment added! id: %i\n", garment->GetId());
}

std::vector<Customer> CustomerController::GetCustomers()
{
	return customers;
}

Customer* CustomerController::GetCustomerById(int id)
{
	int positionOfCustomer = CustomerPosition(id);
	if(positionOfCustomer != -1)
	{
		return &customers.at(positionOfCustomer);
	}
	return NULL;
}

void CustomerController::RemoveCustomerById(int id)
{
	int positionToRemove = CustomerPosition(id);
	if(positionToRemove != -1)
	{
		customers.erase(customers.begin()+positionToRemove);
	}
}

int CustomerController::CustomerPosition(int id)
{
	for(unsigned int i = 0; i < customers.size(); i++)
	{
		if(id == customers.at(i).GetId())
		{
			return i;
		}
	}
	return -1;
}

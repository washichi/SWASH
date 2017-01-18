#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "Customer.h"

class CustomerController
{
	public:
		CustomerController();
		void AddGarmentToCustomer(Garment* garment);
		std::vector<Customer> GetCustomers();
		Customer* GetCustomerById(int id);
		void RemoveCustomerById(int id);
	
	private:
		std::vector<Customer> customers;
		int CustomerPosition(int id);
};

#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "Customer.h"

class CustomerController
{
	public:
		CustomerController();
		void AddCustomer(Customer customer);
		std::vector<Customer> GetCustomers();
		Customer GetCustomerById(int id);
		void RemoveCustomerById(int id);
	
	private:
	
	
};

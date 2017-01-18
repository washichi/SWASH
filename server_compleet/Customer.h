#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "Garment.h"

class Customer
{
	public:
		Customer(int id);
		std::vector<Garment> GetGarments();
		int GetNumberOfGarments();
		int GetId();
		void AddGarment(Garment garment);
	
	private:
		int id;
		int numberOfGarments;
		std::vector<Garment> garments;
		
};

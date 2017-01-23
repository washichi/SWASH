#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "Garment.h"
#include "MachineController.h"

class GarmentController
{
	public:
		GarmentController(MachineController* machineptr);
		~GarmentController();
		void AddGarment(char const* docname);
		void Test();
		void ProcessGarments();
		int ProcessFinishedGarments();
	private:
		std::vector<Garment*>* toBeProcessed;
		std::vector<Garment*>* finishedGarments;
		MachineController* machineptr;
	
};

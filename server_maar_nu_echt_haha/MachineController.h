#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "IMachine.h"
#include "MachineFactory.h"

class MachineController
{
	public:
		MachineController();
		~MachineController();
		void AddMachine(std::string name, int id);
		bool SendGarmentToMachine(Garment* garment);
		void CollectFinishedGarments(std::vector<Garment*>* finishedGarmentsVector);
		void FinishMachine(int id);
		void Test();
	private:
		std::vector<IMachine*>* machines;
		std::vector<Garment*>* finishedGarments;
};

#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include "Garment.h"

class IMachine
{
	public:
		void virtual Test();
		void virtual Initialize(int id);
		int virtual GetId();
		bool virtual AddToProgram(Garment* garment);
		void virtual Finish();
		bool virtual IsBusy();
		virtual ~IMachine() {}
	private:
		int id;
		bool readyToCalculateProgram;
		bool busy;
		char currentWashProgram;
};



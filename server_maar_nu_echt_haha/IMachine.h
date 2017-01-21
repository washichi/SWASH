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
		void virtual SetId(int id);
		int virtual GetId();
		void virtual CalculateProgram(Garment* garment);
		void virtual Finish();
		virtual ~IMachine() {}
	private:
		int id;
};



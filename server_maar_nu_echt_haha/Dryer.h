#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "IMachine.h"

class Dryer : public IMachine
{
public:
	void Test();
	void SetId(int id);
	int GetId(int id);
	void CalculateProgram(Garment* garment);
	void Finish();
	virtual ~Dryer() {}
private:
	int id;
};

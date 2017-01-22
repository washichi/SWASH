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
	void Initialize(int id);
	int GetId(int id);
	bool AddToProgram(Garment* garment);
	void Finish();
	bool IsBusy();
	virtual ~Dryer() {}
private:
	int id;
	bool busy;
	bool readyToCalculateProgram;
};

#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "IMachine.h"

class Wasmachine : public IMachine
{
public:
	void Test();
	void Initialize(int id);
	int GetId();
	bool AddToProgram(Garment* garment);
	void Finish();
	bool IsBusy();
	virtual ~Wasmachine();
private:
	int id;
	bool readyToCalculateProgram;
	bool busy;
	char currentProgram;
	char GetProgram(std::string color);
	std::vector<Garment*>* garmentsInProgram;
};

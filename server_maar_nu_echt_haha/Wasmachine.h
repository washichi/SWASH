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
	void SetId(int id);
	virtual ~Wasmachine() {}
private:
	int id;
};
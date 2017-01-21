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
	virtual ~Dryer() {}
private:
	int id;
};
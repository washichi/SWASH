#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

class IMachine
{
	public:
		void virtual Test();
		void virtual SetId(int id);
		virtual ~IMachine() {}
	private:
		int id;
};



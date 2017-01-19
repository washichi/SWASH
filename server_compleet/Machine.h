#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

class Machine{
	public:
		Machine(std::string type);
		std::string GetType();
		bool GetBusy();
		int StartProgram(std::string program);
		void Stop();
		
	private:
		bool busy;
		std::string type;
		int number;
};

#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

class Garment
{
	public:
		Garment(int id, double weight, std::string material, std::string color);
		void SetDryer(bool dryer);
		void SetSteamer(bool steamer);
		void SetCentrifuge(bool centrifuge);
		int GetId() const;
		double GetWeight() const ;
		std::string GetMaterial() const;
		std::string GetColor() const;
		bool GetDryer() const;
		bool GetSteamer() const;
		bool GetCentrifuge() const;
		
	
	private:
		int id;
		double weight;
		std::string material;
		std::string color;
		bool dryer;
		bool steamer;
		bool centrifuge;
};

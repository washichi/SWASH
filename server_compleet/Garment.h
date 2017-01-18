#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/tree.h>
#include <string>
#include <vector>

class Garment
{
	public:
		Garment(int id, double weight, std::string material, std::string color);
		Garment(char const* docname);
		int GetId() const;
		double GetWeight() const ;
		std::string GetMaterial() const;
		std::string GetColor() const;
		bool GetWasher() const;
		bool GetDryer() const;
		bool GetSteamer() const;
		bool GetCentrifuge() const;
		int GetOrderAmount() const;
	
	private:
		int id;
		double weight;
		std::string material;
		std::string color;
		bool washer;
		bool dryer;
		bool steamer;
		bool centrifuge;
		int orderamount;
		
		void SetWasher(bool washer);
		void SetDryer(bool dryer);
		void SetSteamer(bool steamer);
		void SetCentrifuge(bool centrifuge);
};

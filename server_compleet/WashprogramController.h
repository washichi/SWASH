#pragma once

#include "Garment.h"

class WashprogramController{
	public:
		WashprogramController();
		void AddGarments(std::vector<Garment>* garments);
	
	private:
		std::vector<Garment> WasherGarmentList;
		std::vector<Garment> DryerGarmentList;
		std::vector<Garment> CentrifugeGarmentList;
		std::vector<Garment> SteamerGarmentList;
		//std::vector<Machine> MachineList;
		void CalculateWashprograms();
};

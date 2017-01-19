#pragma once

#include "Garment.h"
#include "MachineController.h"

class WashprogramController{
	public:
		WashprogramController(MachineController* machinecontroller);
		void AddGarments(std::vector<Garment>* garments);
		void AddGarment(Garment* garment);
		void CalculateWashprograms();
		void StartWashprograms();
		
	
	private:
		std::vector<Garment> garmentstobewashed;
		std::vector<Garment> washergarments;
		std::vector<Garment> dryergarments;
		std::vector<Garment> centrifugegarments;
		std::vector<Garment> steamergarments;
		void CalculateWasher();
		void CalculateDryer();
		void CalculateCentrifuge();
		void CalculateSteamer();
		MachineController* machinecontroller;
};

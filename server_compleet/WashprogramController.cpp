#include "WashprogramController.h"

WashprogramController::WashprogramController(MachineController* machinecontroller)
: machinecontroller(machinecontroller)
{	
}

void WashprogramController::AddGarments(std::vector<Garment>* garments)
{
	for(unsigned int i = 0; i < garments->size(); i++)
	{
		AddGarment(&garments->at(i));
	}
}

void WashprogramController::AddGarment(Garment* garment)
{
	garmentstobewashed.push_back(*garment);
}

void WashprogramController::CalculateWashprograms()
{
	CalculateWasher();
	CalculateDryer();
	CalculateCentrifuge();
	CalculateSteamer();
}

void WashprogramController::StartWashprograms()
{
	
}

void WashprogramController::CalculateWasher()
{
	if(machinecontroller->GetBusyWasher()){return;}
	bool tobeselected = true;
	std::string firstcolor = "";
	for(unsigned int i = 0; i < garmentstobewashed.size(); i++)
	{
		printf("Washer info: %i, %s\n", garmentstobewashed.at(i).GetId(), garmentstobewashed.at(i).GetMaterial().c_str());
		printf("%i\n", i);
		if(garmentstobewashed.at(i).GetWasher())
		{
			if(tobeselected){firstcolor = garmentstobewashed.at(i).GetColor(); tobeselected = false;}
			if(firstcolor == garmentstobewashed.at(i).GetColor())
			{
				washergarments.push_back(garmentstobewashed.at(i));
				garmentstobewashed.erase(garmentstobewashed.begin()+i);
				i = -1;
			}
		}
	}
	printf("articles: %i\n", washergarments.size());
	if(!washergarments.empty())
	{
		machinecontroller->StartWasher(firstcolor);
	}
}

void WashprogramController::CalculateDryer()
{
	if(machinecontroller->GetBusyDryer()){return;}
	bool tobeselected = true;
	std::string firstcolor = "";
	for(unsigned int i = 0; i < garmentstobewashed.size(); i++)
	{
		printf("Dryer info: %i, %s\n", garmentstobewashed.at(i).GetId(), garmentstobewashed.at(i).GetMaterial().c_str());
		if(garmentstobewashed.at(i).GetDryer())
		{
			printf("ping \n");
			if(tobeselected){firstcolor = garmentstobewashed.at(i).GetColor(); tobeselected = false;}
			if(firstcolor == garmentstobewashed.at(i).GetColor())
			{
				dryergarments.push_back(garmentstobewashed.at(i));
				garmentstobewashed.erase(garmentstobewashed.begin()+i);
				i = -1;
			}
		}
	}
	if(!dryergarments.empty())
	{
		machinecontroller->StartDryer(firstcolor);
	}
}

void WashprogramController::CalculateCentrifuge()
{
	if(machinecontroller->GetBusyCentrifuge()){return;}
	bool tobeselected = true;
	std::string firstcolor = "";
	for(unsigned int i = 0; i < garmentstobewashed.size(); i++)
	{
		printf("Centrifuge info: %i, %s\n", garmentstobewashed.at(i).GetId(), garmentstobewashed.at(i).GetMaterial().c_str());
		if(garmentstobewashed.at(i).GetCentrifuge())
		{
			if(tobeselected){firstcolor = garmentstobewashed.at(i).GetColor(); tobeselected = false;}
			if(firstcolor == garmentstobewashed.at(i).GetColor())
			{
				centrifugegarments.push_back(garmentstobewashed.at(i));
				garmentstobewashed.erase(garmentstobewashed.begin()+i);
				i = -1;
			}
		}
	}
	if(!centrifugegarments.empty())
	{
		machinecontroller->StartCentrifuge(firstcolor);
	}
}

void WashprogramController::CalculateSteamer()
{
	if(machinecontroller->GetBusySteamer()){return;}
	bool tobeselected = true;
	std::string firstcolor = "";
	for(unsigned int i = 0; i < garmentstobewashed.size(); i++)
	{
		printf("Steamer info: %i, %s\n", garmentstobewashed.at(i).GetId(), garmentstobewashed.at(i).GetMaterial().c_str());
		if(garmentstobewashed.at(i).GetWasher())
		{
			if(tobeselected){firstcolor = garmentstobewashed.at(i).GetColor(); tobeselected = false;}
			if(firstcolor == garmentstobewashed.at(i).GetColor())
			{
				steamergarments.push_back(garmentstobewashed.at(i));
				garmentstobewashed.erase(garmentstobewashed.begin()+i);
				i = -1;
			}
		}
	}
	if(!steamergarments.empty())
	{
		machinecontroller->StartSteamer(firstcolor);
	}
}


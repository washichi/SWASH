#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/tree.h>
#include <string>
#include <vector>
#include <map>

#include "GarmentController.h"
#include "MachineController.h"

int main(int argc, char **argv) {
	printf("NEW MACHINECONTROLLER\n");
	MachineController* m = new MachineController();
	printf("ADD WASMACHINE\n");
	m->AddMachine("WAS", 19);
	printf("TEST MACHINECONTROLLER\n");
	m->Test();
	
	printf("NEW GARMENTCONTROLLER\n");
	GarmentController* c = new GarmentController(m);
	printf("ADD DUMMYDATA x5\n");
	c->AddGarment("dummy0.xml");
	c->AddGarment("dummy1.xml");
	c->AddGarment("dummy2.xml");
	c->AddGarment("dummy3.xml");
	c->AddGarment("dummy4.xml");
	printf("ADD DRYER\n");
	m->AddMachine("DRY", 25);
	printf("TEST GARMENTCONTROLLER\n");
	c->Test();
	printf("PROCESS GARMENTS\n");
	c->ProcessGarments();
	printf("TEST GARMENTCONTROLLER\n");
	c->Test();
	printf("FINISH WASHER\n");
	m->FinishMachine(19);
	printf("READDING FINISHED GARMENTS\n");
	c->ProcessFinishedGarments();
	printf("TEST GARMENTCONTROLLER\n");
	c->Test();
	printf("FINISH DRYER\n");
	m->FinishMachine(25);
	printf("READDING FINISHED GARMENTS\n");
	c->ProcessFinishedGarments();
	printf("TEST GARMENTCONTROLLER\n");
	c->Test();
	printf("PROCESS GARMENTS\n");
	c->ProcessGarments();
	printf("TEST GARMENTCONTROLLER\n");
	c->Test();
	printf("FINISH WASHER\n");
	m->FinishMachine(19);
	printf("READDING FINISHED GARMENTS\n");
	c->ProcessFinishedGarments();
	printf("FINISH DRYER\n");
	m->FinishMachine(25);
	printf("READDING FINISHED GARMENTS\n");
	c->ProcessFinishedGarments();
	printf("TEST GARMENTCONTROLLER\n");
	c->Test();
	
	delete c;
	delete m;
	
	xmlCleanupParser();
}

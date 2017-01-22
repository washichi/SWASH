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
	MachineController* m = new MachineController();
	m->AddMachine("WAS", 19);
	m->Test();
	
	GarmentController* c = new GarmentController(m);
	c->AddGarment("dummy0.xml");
	c->AddGarment("dummy1.xml");
	c->AddGarment("dummy2.xml");
	c->AddGarment("dummy3.xml");
	c->AddGarment("dummy4.xml");
	m->AddMachine("DRY", 25);
	c->Test();
	c->ProcessGarments();
	c->Test();
	m->FinishMachine(19);
	c->Test();
	m->FinishMachine(24);
	
	delete m;
	delete c;
	xmlCleanupParser();
}

#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/tree.h>
#include <string>
#include <vector>

#include "CustomerController.h"
#include "MachineController.h"
#include "WashprogramController.h"

int main(int argc, char **argv) {
	//Open message queue - gebruik QueueCommunicaton voor receiving/sending
	//Geef een pointer mee aan de controllers, dan kunnen die berichten op de queue zetten
	
	//Open shared memory?
	
	/*
	 * ontvang berichten uit de message queue
	 * berichten kunnen of van machines komen of van de UI
	 * gebruik washprogramcontroller en machinecontroller
	 */
	 CustomerController* c = new CustomerController();
	 MachineController* m = new MachineController();
	 m->AddMachine(1);
	 m->AddMachine(2);
	 m->AddMachine(3);
	 m->AddMachine(4);
	 WashprogramController* w = new WashprogramController(m);
	 
	 for(unsigned int i = 0; i < 5; i++)
	 {
		 char const* docname;
		 if(i == 0){docname = "dummy0.xml";}
		 else if(i == 1){docname = "dummy1.xml";}
		 else if(i == 2){docname = "dummy2.xml";}
		 else if(i == 3){docname = "dummy3.xml";}
		 else if(i == 4){docname = "dummy4.xml";}
		 printf("%s\n", docname);
		 Garment g(docname);
		 c->AddGarmentToCustomer(&g);
		 w->AddGarment(&g);
	 }
	 w->CalculateWashprograms();
	 //w->StartWasher();
	
}

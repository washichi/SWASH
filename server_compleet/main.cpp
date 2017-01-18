#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/tree.h>
#include <string>
#include <vector>

#include "CustomerController.h"

int main(int argc, char **argv) {
	//Open message queue
	
	//Open shared memory?
	
	/*
	 * ontvang berichten uit de message queue
	 * berichten kunnen of van machines komen of van de UI
	 * gebruik washprogramcontroller en machinecontroller
	 */
	if (argc != 2) {
		fprintf(stderr, "Gebruik: %s <filenaam>\n", argv[0]);
		exit(1);
	}
	
	char const* docname = argv[1];
	Garment g(docname);
	printf("Material from XML: %s\n", g.GetMaterial().c_str());
}

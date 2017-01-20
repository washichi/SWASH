#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/tree.h>
#include <string>
#include <vector>
#include <map>

#include "IMachine.h"
#include "MachineFactory.h"

int main(int argc, char **argv) {
	IMachine* x = MachineFactory::NewMachine("WAS");
	x->SetId(19);
	x->Test();
	
	IMachine* y = MachineFactory::NewMachine("DRY");
	y->SetId(25);
	y->Test();
}

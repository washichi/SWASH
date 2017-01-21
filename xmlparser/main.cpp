#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/tree.h>
#include <string>
#include <vector>

#include "Garment.h"

void
parseGarment (xmlDocPtr doc, xmlNodePtr cur) {
	xmlChar *key;
	cur = cur->xmlChildrenNode;
	int id = 0;
	std::string material;
	std::string color;
	double weight = 0;
	bool dryer = 0;
	bool steamer = 0;
	bool centrifuge = 0;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"material"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			material = (const char*)key;
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"customerid"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			id = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"color"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			color = (const char*)key;
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"weight"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			weight = atof((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"dryer"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			dryer = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"steamer"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			steamer = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"centrifuge"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			centrifuge = atoi((const char*)key);
		    xmlFree(key);
		}
			
		cur = cur->next;
	}
	Garment g(id, weight, material, color);
	g.SetDryer(dryer);
	g.SetSteamer(steamer);
	g.SetCentrifuge(centrifuge);
	printf("CustomerID from XML: %i\n", g.GetId());
	printf("Material from XML: %s\n", g.GetMaterial().c_str());
	printf("Color from XML: %s\n", g.GetColor().c_str());
	printf("Weight from XML: %f\n", g.GetWeight());
	printf("Dryer from XML: %s\n", g.GetDryer()?"true":"false");
	printf("Steamer from XML: %s\n", g.GetSteamer()?"true":"false");
	printf("Centrifuge from XML: %s\n", g.GetCentrifuge()?"true":"false");
	
    return;
}

int main(int argc, char **argv) {
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	if (argc != 2) {
		fprintf(stderr, "Gebruik: %s <filenaam>\n", argv[0]);
		exit(1);
	}
	
	char const* docname = argv[1];

	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return 0;
	}

	cur = xmlDocGetRootElement(doc);
	
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return 0;
	}
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "garment")) {
		fprintf(stderr,"document of the wrong type, root node != garment");
		xmlFreeDoc(doc);
		return 0;
	}
	else
	{
		parseGarment (doc, cur);
	}
}

#include "Garment.h"

Garment::Garment(int id, double weight, std::string material, std::string color) 
: id(id)
, weight(weight)
, material(material)
, color(color)
, dryer(false)
, steamer(false)
, centrifuge(false)
{
}

Garment::Garment(char const* docname)
{
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return ;
	}

	cur = xmlDocGetRootElement(doc);
	
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return ;
	}
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "garment")) {
		fprintf(stderr,"document of the wrong type, root node != garment");
		xmlFreeDoc(doc);
		return ;
	}
	
	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"material"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->material = (const char*)key;
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"customerid"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->id = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"color"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->color = (const char*)key;
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"weight"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->weight = atof((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"washer"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->washer = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"dryer"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->dryer = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"steamer"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->steamer = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"centrifuge"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->centrifuge = atoi((const char*)key);
		    xmlFree(key);
		}
		else if((!xmlStrcmp(cur->name, (const xmlChar *)"garmentsinorder"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			this->orderamount = atoi((const char*)key);
		    xmlFree(key);
		}
			
		cur = cur->next;
	}
}

void Garment::SetWasher(bool washer)
{
	this->washer = washer;
}

void Garment::SetDryer(bool dryer)
{
	this->dryer = dryer;
}

void Garment::SetSteamer(bool steamer)
{
	this->steamer = steamer;
}

void Garment::SetCentrifuge(bool centrifuge)
{
	this->centrifuge = centrifuge;
}

int Garment::GetId() const
{
	return id;
}

double Garment::GetWeight() const
{
	return weight;
}

std::string Garment::GetMaterial() const
{
	return material;
}

std::string Garment::GetColor() const
{
	return color;
}

bool Garment::GetWasher() const
{
	return washer;
}

bool Garment::GetDryer() const
{
	return dryer;
}

bool Garment::GetSteamer() const
{
	return steamer;
}

bool Garment::GetCentrifuge() const
{
	return centrifuge;
}

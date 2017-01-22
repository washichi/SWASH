#include "Garment.h"

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
	xmlFreeDoc(doc);
	xmlFree(cur);
	finished = false;
	CheckIfFinished();
}

void Garment::SetWasher(bool washer)
{
	this->washer = washer;
	CheckIfFinished();
}

void Garment::SetDryer(bool dryer)
{
	this->dryer = dryer;
	CheckIfFinished();
}

void Garment::SetSteamer(bool steamer)
{
	this->steamer = steamer;
	CheckIfFinished();
}

void Garment::SetCentrifuge(bool centrifuge)
{
	this->centrifuge = centrifuge;
	CheckIfFinished();
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

void Garment::CheckIfFinished()
{
	if(!GetWasher() && !GetDryer() && !GetSteamer() && !GetCentrifuge())
	{
		this->finished = true;
		printf("Garment with ID: %i is finished\n", this->id);
	}
}

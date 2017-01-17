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

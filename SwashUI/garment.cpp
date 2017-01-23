#include "garment.h"
#include <QString>
#include <QDebug>

Garment::Garment(int id, double weight, QString material, QString color, bool wash, bool dryer, bool steamer, bool centrifuge)
: id(id)
, weight(weight)
, material(material)
, color(color)
, wash(wash)
, dryer(dryer)
, steamer(steamer)
, centrifuge(centrifuge)
{
    qDebug() << "Garment was made";
}

void Garment::SetWashingMachine(bool wash)
{
    this->wash = wash;
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

QString Garment::GetMaterial() const
{
    return material;
}

QString Garment::GetColor() const
{
    return color;
}

QString Garment::ToString()
{
    QString Garmentstring = "Id: " + QString::number(id) + "Weight: " + QString::number(weight) + "Material: " + material + "Color: " + color + "Wash: " + wash + "Dryer: " + dryer + "Steamer: " + steamer + "Centrifuge: " + centrifuge;
    return Garmentstring;
}

bool Garment::GetWashingMachine() const
{
    return wash;
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

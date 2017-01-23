#include "swashadmin.h"

#include <QString>
#include <QDebug>


SwashAdmin::SwashAdmin()
{
    QString name = "Hoze Joze";
    QString material = "Wool";
    QString color = "Coloured";
    customer = new Customer(1, name);
    garment = new Garment(1, 20.20, material, color, false, false, false, false);
    bool inProcess = false;
}

void SwashAdmin::addGarmentToList(Garment *garment)
{
    garmentlist.append(garment);
    qDebug() << "garment was added to the garment list";
}

void SwashAdmin::addCustomerToList(Customer *customer)
{
    customerlist.append(customer);
    qDebug() << "customer was added to the customer list";
}

void SwashAdmin::addMachineToList(Machine *machine)
{
    machines.append(machine);
    qDebug() << "customer was added to the customer list";
}

QString SwashAdmin::GetGarmentString()
{
    addGarmentToList(this->garment);
    QString AllGarmentElements;
      for(it = garmentlist.begin(); it != garmentlist.end(); it++)
      {
          AllGarmentElements = (*it)->ToString();
      }
      qDebug() << AllGarmentElements;
      return AllGarmentElements;
}

QString SwashAdmin::GetCustomerString()
{
    QString AllCustomerElements;
    for(iterator = customerlist.begin(); iterator != customerlist.end(); iterator++)
    {
      AllCustomerElements = (*iterator)->ToString();
    }
    return AllCustomerElements;
}

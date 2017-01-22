#include "customer.h"

#include <QString>
#include <QDebug>

Customer::Customer(int id, QString name )
{
    this->Id = id;
    this->name = name;
    qDebug() << "new customer was made";
}

QString Customer::ToString()
{
    QString customerString = "Customer:  id: " + QString::number(Id) + "Name: " + name + "payed: " + pay;
    return customerString;
}

bool Customer::AcceptProgram()
{
    pay = true;
    return pay;
}

QString Customer::getName()
{
    return name;
}

void Customer::setName(QString newname)
{
    name = newname;
}

int Customer::getId()
{
    return Id;
}

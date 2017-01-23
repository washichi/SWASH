#ifndef SWASHADMIN_H
#define SWASHADMIN_H

#include "customer.h"
#include "garment.h"

#include <QVector>
#include <QString>

class SwashAdmin
{
public:
    SwashAdmin();
    void addGarmentToList(Garment *garment);
    void addCustomerToList(Customer *customer);
    QString GetGarmentString();
    QString GetCustomerString();
    void updateProcess();

private:
    Garment *garment;
    Customer *customer;
    QVector<Customer*> customerlist;
    QVector<Garment*> garmentlist;
    QVector<Customer*>::iterator iterator;
    QVector<Garment*>::iterator it;
    bool inProcess;

};

#endif // SWASHADMIN_H

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer
{
public:
    Customer(int id, QString name);
    QString ToString();
    QString getName();
    int getId();
    bool AcceptProgram();
    void setName(QString name);

private:
    int Id;
    QString name;
    bool pay = false;
};

#endif // CUSTOMER_H

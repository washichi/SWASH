#ifndef MACHINE_H
#define MACHINE_H

#include <QString>

class Machine
{

public:
    Machine(int id);
    int machineID;
    enum machineTypes{WashingMachine, Centrifuge};
    machineTypes machineType;

    QString ToString();

};


#endif // MACHINE_H

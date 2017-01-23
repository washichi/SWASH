#include "machine.h"

Machine::Machine(int id)
{
    this->machineID = id;
    if(id == 0032)
    {
        this->machineType = WashingMachine;
    }
    else if(id == 0033)
    {
        this->machineType = Centrifuge;
    }
}

QString Machine::ToString()
{
    QString returnString = this->machineType + ": " + this->machineID;
    return returnString;
}

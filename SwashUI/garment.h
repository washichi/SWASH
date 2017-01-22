#ifndef GARMENT_H
#define GARMENT_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <QString>

class Garment
{
    public:
        Garment(int id, double weight, QString material, QString color, bool wash, bool dryer, bool steamer, bool centrifuge);
        void SetWashingMachine(bool wash);
        void SetWash(bool wash);
        void SetDryer(bool dryer);
        void SetSteamer(bool steamer);
        void SetCentrifuge(bool centrifuge);
        int GetId() const;
        double GetWeight() const ;

        QString GetMaterial() const;
        QString GetColor() const;

        bool GetWashingMachine() const;
        bool GetDryer() const;
        bool GetSteamer() const;
        bool GetCentrifuge() const;

        QString ToString();


    private:
        int id;
        double weight;

        QString material;
        QString color;

        bool wash;
        bool dryer;
        bool steamer;
        bool centrifuge;
};


#endif // GARMENT_H

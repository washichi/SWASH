#include "xmlfilehandler.h"
#include "garment.h"
#include "communication.h"
#include "swashadmin.h"

#include <QtXml>
#include <QFile>
#include <QDebug>
#include <QString>

XMLFileHandler::XMLFileHandler(Communication *clientPtr)
{
    //this->admin = ui;
    this->clientPtr = clientPtr;
}

void XMLFileHandler::CreateQDomDocument()
{
    QDomDocument xmlBOM;
    QString errMsg;
    QFileDevice::FileError err = QFileDevice::NoError;
    QFile qfile("/home/student/Desktop/SwashUI/garmentxml.xml");
    if (!qfile.open(QIODevice::ReadOnly ))
    {
        std::cerr << "Error while loading file" << std::endl;
        errMsg = qfile.errorString();
        err = qfile.error();
    }
    xmlBOM.setContent(&qfile);
    qfile.close();

    QDomElement root = xmlBOM.documentElement();
    QDomElement Component = root.firstChild().toElement();

    while(!Component.isNull())
    {
        if (Component.tagName()=="COMPONENT")
        {
            QString ID=Component.attribute("ID","No ID");
            QDomElement Child=Component.firstChild().toElement();

            int id;
            QString Material;
            QString color;
            double weight;
            bool washer;
            bool dryer;
            bool steamer;
            bool centrifuge;
            int order;

            while (!Child.isNull())
            {
                if (Child.tagName()=="CUSTOMERID") id=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="MATERIAL") Material=Child.firstChild().toText().data();
                if (Child.tagName()=="COLOR") color=Child.firstChild().toText().data();
                if (Child.tagName()=="WEIGHT") weight=Child.firstChild().toText().data().toDouble();
                if (Child.tagName()=="WASHER") washer=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="DRYER") dryer=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="STEAMER") steamer=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="CENTRIFUGE") centrifuge=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="GARMENTSINORDER") order=Child.firstChild().toText().data().toInt();

                garment = new Garment(id, weight, Material, color, washer, dryer, steamer, centrifuge);
                //admin->addGarmentToList(garment);
                qDebug() << "new garments were created";

                QString message = QString::number(id) + Material + color + QString::number(weight);

                clientPtr->SendMessage(message);

                Child = Child.nextSibling().toElement();


            }
        }

        Component = Component.nextSibling().toElement();
    }
}

void XMLFileHandler::ProcessData()
{
    QDomElement root = xmlGar->documentElement();
    QDomElement Component = root.firstChild().toElement();

    while(!Component.isNull())
    {
        if (Component.tagName()=="COMPONENT")
        {
            QString ID=Component.attribute("ID","No ID");
            QDomElement Child=Component.firstChild().toElement();

            int id;
            QString Material;
            QString color;
            double weight;
            bool washer;
            bool dryer;
            bool steamer;
            bool centrifuge;
            int order;

            while (!Child.isNull())
            {
                if (Child.tagName()=="CUSTOMERID") id=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="MATERIAL") Material=Child.firstChild().toText().data();
                if (Child.tagName()=="COLOR") color=Child.firstChild().toText().data();
                if (Child.tagName()=="WEIGHT") weight=Child.firstChild().toText().data().toDouble();
                if (Child.tagName()=="WASHER") washer=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="DRYER") dryer=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="STEAMER") steamer=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="CENTRIFUGE") centrifuge=Child.firstChild().toText().data().toInt();
                if (Child.tagName()=="GARMENTSINORDER") order=Child.firstChild().toText().data().toInt();

                garment = new Garment(id, weight, Material, color, washer, dryer, steamer, centrifuge);
                //admin->addGarmentToList(garment);
                qDebug() << "new garments were created";

                QString message = QString::number(id) + Material + color + QString::number(weight);

                clientPtr->SendMessage(message);
                qDebug() << message;
                Child = Child.nextSibling().toElement();


            }
        }

        Component = Component.nextSibling().toElement();
    }
}

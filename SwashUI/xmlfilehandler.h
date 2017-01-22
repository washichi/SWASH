#ifndef XMLFILEHANDLER_H
#define XMLFILEHANDLER_H

#include "garment.h"
#include "swashadmin.h"
#include "communication.h"

#include <QFile>
#include <QtXml>
#include <QString>

class XMLFileHandler
{
public:
    XMLFileHandler(Communication *clientPtr);
    void CreateQDomDocument();
    void ProcessData();

private:

   // QFile *qfile;
      QDomDocument *xmlGar;
    //QDomElement *root;
    Garment *garment;
    //SwashAdmin *admin;
    Communication *clientPtr;
};

#endif // XMLFILEHANDLER_H

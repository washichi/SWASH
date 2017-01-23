#include "swashuiadmin.h"
#include "ui_swashuiadmin.h"
#include "communication.h"
#include "customer.h"
#include "xmlfilehandler.h"
#include "garment.h"
#include "swashadmin.h"

#include <QDebug>

SwashUIAdmin::SwashUIAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SwashUIAdmin)
{
    ui->setupUi(this);
}

SwashUIAdmin::~SwashUIAdmin()
{
    delete ui;
}

void SwashUIAdmin::setup(Communication *clientPtr, QString port)
{
    clientPtr->start();
    ui->lbPort->setText(port);
    uiadmin = new SwashAdmin();
    filehandler = new XMLFileHandler(clientPtr);
}

void SwashUIAdmin::addGarment(Garment *garment)
{
    uiadmin->addGarmentToList(garment);
    QString sendString = "<?xml version='1.0' encoding='UTF-8'?> \n <garment> \n <customerid>" + QString::number(garment->GetId()) + "</customerid> \n <material>"
                        + garment->GetMaterial() + "</material> \n <color>" + garment->GetColor() + "</color> \n <weight>" + QString::number(garment->GetWeight()) +
                        "</weight> \n <dryer>" + garment->GetDryer() + "</dryer> \n <steamer>" +
                        garment->GetSteamer() + "</steamer> \n <centrifuge>" +
                        garment->GetCentrifuge() + "</centrifuge> \n </garment>";
    clientPtr->SendMessage(sendString);
}

void SwashUIAdmin::on_btnDummyData_clicked()
{
    filehandler->CreateQDomDocument();
    filehandler->ProcessData();
    ui->lwGarments->addItem(uiadmin->GetGarmentString());
}

void SwashUIAdmin::on_btnSendGarments_clicked()
{
    clientPtr->SendMessage("garmentsgarments doesn't have a problem");
}

void SwashUIAdmin::RefreshListWidgets()
{
    /*
      for(it = garmentlist.begin(); it != garmentlist.end(); it++)
      {
           ui->lwGarments->addItem((*it)->ToString());
      }

      for(it = customerlist.begin(); it != customerlist.end(); it++)
      {
           ui->lwCustomer->addItem((*it)->ToString());
      }
      */
}


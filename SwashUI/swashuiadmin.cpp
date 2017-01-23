#include "swashuiadmin.h"
#include "ui_swashuiadmin.h"
#include "communication.h"
#include "customer.h"
#include "xmlfilehandler.h"
#include "garment.h"
#include "swashadmin.h"

#include <QDebug>

#define POLLING_MS      300

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

    uiTimer = new QTimer(this);
            connect(uiTimer, SIGNAL(timeout()), this, SLOT(updateUI()));
            uiTimer->start(POLLING_MS);

        processTimer = new QTimer(this);
            connect(processTimer, SIGNAL(timeout()), this, SLOT(updateAllProcess()));
            processTimer->start(POLLING_MS);

}

void SwashUIAdmin::updateAllProcess()
{
    updateProcess();
}

void SwashUIAdmin::updateProcess()
{
       std::string lastMessage = (clientPtr->GetLastMessage().toStdString());
       if(lastMessage == "032")
       {
            int value = atoi(lastMessage.c_str());
            Machine *machine = new Machine(value);
            uiadmin->addMachineToList(machine);
            ui->lwMachineStatus->addItem(machine->ToString());
       }
       else if(lastMessage == "033")
       {

       }
       else if(lastMessage == "Customer")
       {
           //findCustomer(customer);
           //CustomerReady show on screen
       }
}

void SwashUIAdmin::updateUI()
{
    //Update List Widgets
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

}


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
    //uiadmin = new SwashAdmin();
    filehandler = new XMLFileHandler(clientPtr);
}

void SwashUIAdmin::on_btnDummyData_clicked()
{
    filehandler->CreateQDomDocument();
    filehandler->ProcessData();
    //ui->lwGarments->addItem(uiadmin->GetGarmentString());
}

void SwashUIAdmin::on_btnSendGarments_clicked()
{
    clientPtr->SendMessage("garmentsgarments doesn't have a problem");
}

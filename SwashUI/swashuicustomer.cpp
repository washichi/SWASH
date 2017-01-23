#include "swashuicustomer.h"
#include "ui_swashuicustomer.h"
#include "customer.h"


#include <QDebug>
#include <QTextEdit>
#include <QMessageBox>

SwashUICustomer::SwashUICustomer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SwashUICustomer)
{
    ui->setupUi(this);
}

SwashUICustomer::~SwashUICustomer()
{
    delete ui;
}

void SwashUICustomer::setup(SwashUIAdmin *UiAdmin, Communication *client, QString port)
{
    client->start();
    uiAdmin = UiAdmin;
    this->clientPtr = client;
    counter = 0;
}

void SwashUICustomer::on_btnAccept_clicked()
{
    clientPtr->SendMessage("programaccepted");
    customer->AcceptProgram();
    counter += 1;
}


void SwashUICustomer::on_btAddGarment_clicked()
{
    if(ui->nmrWeight->value() <= 0.0)
    {
        QMessageBox msgBox;
        msgBox.setText("Please enter the weight.");
        msgBox.exec();
    }
    else if(!ui->cbWash->isChecked() && !ui->cbCentrifuge->isChecked() && !ui->cbSteam->isChecked() && !ui->cbDry->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setText("Please check the boxes of the machine(s) you want to use.");
        msgBox.exec();
    }
    else
    {

        QString materialString = (ui->cmbMaterial->currentText());
        QString colourString = (ui->cmbColour->currentText());
        Garment *garment = new Garment(counter, ui->nmrWeight->value(), materialString, colourString, ui->cbWash->isChecked(), ui->cbDry->isChecked(), ui->cbSteam->isChecked(), ui->cbCentrifuge->isChecked());
        //Garments.push_back(*garment);
        ui->listWidget_2->addItem(garment->ToString());
        uiAdmin->addGarment(garment);

        // Signal to slot in SwashAdmin to add to list and use comms.
        QMessageBox msgBox;
        msgBox.setText("Garment has been added.");
        msgBox.exec();
    }
}


void SwashUICustomer::on_pushButton_clicked()
{
    QString name = "Harry Potter";
    if((ui->txtLogin->text()).toStdString() == "77892")
    {
         customer = new Customer(77892, name);
         QMessageBox msgBox;
         msgBox.setText("Hello Mr. Potter");
         msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Login Failed");
        msgBox.exec();
   }
}

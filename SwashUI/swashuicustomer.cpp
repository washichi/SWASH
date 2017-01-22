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

void SwashUICustomer::setup(Communication *client, QString port)
{
    client->start();
    this->clientPtr = client;
}

void SwashUICustomer::on_btnAccept_clicked()
{
    clientPtr->SendMessage("programaccepted");
    customer->AcceptProgram();
}

void SwashUICustomer::on_txtLogin_textChanged()
{
    QString name = "Harry Potter";
    QString str = ui->txtLogin->text();
    if(str == "77892")
    {
         customer = new Customer(77892, name);
    }
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
        std::string materialString = (ui->cmbMaterial->currentText()).toStdString();
        std::string colourString = (ui->cmbColour->currentText()).toStdString();
        /*Garment *garment = new Garment(123, ui->nmrWeight->value(), materialString, colourString, ui->cbWash->isChecked(), ui->cbDry->isChecked(), ui->cbSteam->isChecked(), ui->cbCentrifuge->isChecked());
        Garments.push_back(*garment);*/
        QMessageBox msgBox;
        msgBox.setText("Garment has been added.");
        msgBox.exec();
    }
}

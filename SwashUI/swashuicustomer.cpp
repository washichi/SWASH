#include "swashuicustomer.h"
#include "ui_swashuicustomer.h"
#include "customer.h"

#include <QDebug>
#include <QTextEdit>

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
    QString str = ui->txtLogin->toPlainText();
    if(str == "77892")
    {
         customer = new Customer(77892, name);
    }
}

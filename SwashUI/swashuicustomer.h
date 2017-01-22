#ifndef SWASHUICUSTOMER_H
#define SWASHUICUSTOMER_H

#include <QMainWindow>
#include <QString>

#include "communication.h"
#include "customer.h"

namespace Ui {
class SwashUICustomer;
}

class SwashUICustomer : public QMainWindow
{
    Q_OBJECT

public:
    explicit SwashUICustomer(QWidget *parent = 0);
    ~SwashUICustomer();
    void setup(Communication *clientPtr, QString port);

private slots:
    void on_btnAccept_clicked();

    void on_txtLogin_textChanged();

    void on_btAddGarment_clicked();

private:
    Ui::SwashUICustomer *ui;

    Communication *clientPtr;
    QString Port;
    Customer *customer;
};

#endif // SWASHUICUSTOMER_H

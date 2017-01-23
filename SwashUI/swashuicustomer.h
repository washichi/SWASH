#ifndef SWASHUICUSTOMER_H
#define SWASHUICUSTOMER_H

#include <QMainWindow>
#include <QString>

#include "communication.h"
#include "customer.h"
#include "swashuiadmin.h"
#include "garment.h"

namespace Ui {
class SwashUICustomer;
}

class SwashUICustomer : public QMainWindow
{
    Q_OBJECT

public:
    explicit SwashUICustomer(QWidget *parent = 0);
    ~SwashUICustomer();
    void setup(SwashUIAdmin *UiAdmin, Communication *clientPtr, QString port);

private slots:
    void on_btnAccept_clicked();

    void on_txtLogin_textChanged();

    void on_btAddGarment_clicked();

    void on_txtLogin_textChanged(const QString &arg1);

    void on_btLogin_clicked();

    void on_pushButton_clicked();

private:
    Ui::SwashUICustomer *ui;
    SwashUIAdmin *uiAdmin;

    Communication *clientPtr;
    QString Port;
    Customer *customer;
    int counter;
};

#endif // SWASHUICUSTOMER_H

#ifndef SWASHUIADMIN_H
#define SWASHUIADMIN_H

#include <QMainWindow>
#include <QString>
#include <QVector>

#include "garment.h"
#include "customer.h"
#include "communication.h"
#include "xmlfilehandler.h"

namespace Ui {
class SwashUIAdmin;
}

class SwashUIAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit SwashUIAdmin(QWidget *parent = 0);
    ~SwashUIAdmin();
    void setup(Communication *clientPtr, QString port);
    void addGarment(Garment *garment);
    void RefreshListWidgets();

private slots:
    void on_btnDummyData_clicked();
    void updateAllProcess();

    void on_btnSendGarments_clicked();

private:
    SwashAdmin *uiadmin;
    XMLFileHandler *filehandler;
    Ui::SwashUIAdmin *ui;
    Communication *clientPtr;
    QTimer *uiTimer;
    QTimer *processTimer;
    void updateUI();
    void updateProcess();

};

#endif // SWASHUIADMIN_H

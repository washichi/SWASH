#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <iostream>
#include "Garment.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_tabUI_tabBarClicked(int index);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_btStopSelectedMachine_clicked();

    void on_btCallEmployee_clicked();

    void on_btAddGarmentTest_clicked();

    void addGarmentToListWidget(QString garmentId);

    void on_listWidgetGarments_clicked(const QModelIndex &index);

    Garment findObject(int idName);

    void on_btAddGarment_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

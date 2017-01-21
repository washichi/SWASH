#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include "Communication.h"
#include "string.h"
#include <sstream>

Communication communication;
std::vector<Garment> Garments;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox msgBox;

    if(communication.Connect())
    {
        msgBox.setText("Connected.");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("Connection failed.");
        msgBox.exec();
    }

}

MainWindow::~MainWindow()
{
    communication.Close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Thank you for choosing Swash");
    msgBox.exec();
}

void MainWindow::on_tabUI_tabBarClicked(int index)
{
    int nummertje = index;
    nummertje += 1;
    //bool ok;
    //QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User name: "), QLineEdit::Normal, QDir::home()dirName(), &ok);
   //if(ok && !text.isEmpty())
    //{textLabel->setText(text);}
}


void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox msgBox;

    if(communication.Write())
    {
        msgBox.setText("Message is sent.");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("Message was not sent.");
        msgBox.exec();
    }

}

void MainWindow::on_pushButton_7_clicked()
{
    communication.Read();
}

void MainWindow::on_btStopSelectedMachine_clicked()
{
    /*std::string selectedMachineName = "";
    selectedMachineName = listViewMachines.selected;
    communication.Write("Stop " + selectedMachineName);*/

}

void MainWindow::on_btAlarmStop_clicked()
{
    Communication.send("Stop Everything!");

}


void MainWindow::on_listWidgetGarments_clicked(const QModelIndex &index)
{
    //QListWidgetItem *object = ui->listWidgetGarments->currentItem();

    ui->lblWashingMachine->setText("Washingmachine= No");
    ui->lblDryer->setText("Dryer= No");
    ui->lblSteamer->setText("Steamer= No");
    ui->lblCentrifuge->setText("Centrifuge= No");

    QString objectName = ui->listWidgetGarments->currentItem()->text();
    int id = objectName.toInt();
    Garment garment = findObject(id);

    double dGarmentId;
    std::string sMaterial;
    double dWeight;
    std::string sColor;

    dGarmentId = garment.GetId();
    sMaterial = garment.GetMaterial();
    dWeight = garment.GetWeight();
    sColor = garment.GetColor();

    QString qsGarmentId = QString::number(dGarmentId);
    QString qsMaterial = QString::fromUtf8(sMaterial.c_str());
    QString qsWeight = QString::number(dWeight);
    QString qsColor = QString::fromUtf8(sColor.c_str());

    ui->lblGarmentId->setText("GarmentID= " + qsGarmentId);
    ui->lblMaterial->setText("Material= " +qsMaterial);
    ui->lblWeight->setText("Weight= " + qsWeight);
    ui->lblColoured->setText("Color= " + qsColor);

    if(garment.GetWashingMachine())
    {
        std::stringstream ssWashingMachine;
        ssWashingMachine << garment.GetWashingMachine();
        ui->lblWashingMachine->setText("Washingmachine= Yes");
    }
    if(garment.GetDryer())
    {
        std::stringstream ssDryer;
        ssDryer << garment.GetDryer();
        ui->lblDryer->setText("Dryer= Yes");
    }
    if(garment.GetSteamer())
    {
        std::stringstream ssSteamer;
        ssSteamer << garment.GetSteamer();
        ui->lblSteamer->setText("Steamer= Yes");
    }
    if(garment.GetCentrifuge())
    {
        std::stringstream ssCentrifuge;
        ssCentrifuge << garment.GetCentrifuge();
        ui->lblCentrifuge->setText("Centrifuge= Yes");
    }
}

void MainWindow::on_btCallEmployee_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Chris is onderweg");
    msgBox.exec();
}

void MainWindow::addGarmentToListWidget(QString garmentId)
{
    ui->listWidgetGarments->addItem(garmentId);
}

void MainWindow::on_btAddGarmentTest_clicked()
{
    Garment *garment = new Garment(888, 88, "Cotton", "Black", true, false, false, true);

    QString garmentId = QString::number(garment->GetId());
    ui->listWidgetGarments->addItem(garmentId);
    Garments.push_back(*garment);
}

Garment MainWindow::findObject(int idName)
{
    Garment garment = Garment(0, 0, "", "", false, false, false, false);
    std::vector<Garment>::iterator it;
    int i = 0;
       for(it=Garments.begin(); it < Garments.end(); it++, i++)
       {
            if((*it).GetId() == idName)
            {
                return *it;
            }
       }
       return garment;
}

void MainWindow::on_btAddGarment_clicked()
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
        Garment *garment = new Garment(123, ui->nmrWeight->value(), materialString, colourString, ui->cbWash->isChecked(), ui->cbDry->isChecked(), ui->cbSteam->isChecked(), ui->cbCentrifuge->isChecked());
        Garments.push_back(*garment);
        QMessageBox msgBox;
        msgBox.setText("Garment has been added.");
        msgBox.exec();
    }


}

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabUI;
    QWidget *tabCustomerUI;
    QPushButton *btStartProgram;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btCallEmployee;
    QLabel *lbWelcome;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_8;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QComboBox *cmbColour;
    QCheckBox *cbWash;
    QCheckBox *cbDry;
    QCheckBox *cbSteam;
    QCheckBox *cbCentrifuge;
    QComboBox *cmbMaterial;
    QDoubleSpinBox *nmrWeight;
    QPushButton *btAddGarment;
    QWidget *tabAdministratorUI;
    QGroupBox *groupBox_2;
    QListView *listViewMachines;
    QGroupBox *groupBox_3;
    QListWidget *listWidgetGarments;
    QLabel *lblGarmentId;
    QLabel *lblMaterial;
    QLabel *lblWeight;
    QLabel *lblColoured;
    QLabel *lblWashingMachine;
    QLabel *lblDryer;
    QLabel *lblSteamer;
    QLabel *lblCentrifuge;
    QPushButton *btStopSelectedMachine;
    QPushButton *btAlarmStop;
    QPushButton *btAddGarmentTest;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(877, 713);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabUI = new QTabWidget(centralWidget);
        tabUI->setObjectName(QStringLiteral("tabUI"));
        tabUI->setGeometry(QRect(10, 0, 861, 651));
        tabCustomerUI = new QWidget();
        tabCustomerUI->setObjectName(QStringLiteral("tabCustomerUI"));
        btStartProgram = new QPushButton(tabCustomerUI);
        btStartProgram->setObjectName(QStringLiteral("btStartProgram"));
        btStartProgram->setGeometry(QRect(30, 560, 171, 31));
        frame = new QFrame(tabCustomerUI);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 70, 271, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 68, 21));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 50, 68, 21));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 141, 21));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 80, 68, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 91, 21));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 120, 68, 21));
        btCallEmployee = new QPushButton(tabCustomerUI);
        btCallEmployee->setObjectName(QStringLiteral("btCallEmployee"));
        btCallEmployee->setGeometry(QRect(10, 370, 231, 151));
        lbWelcome = new QLabel(tabCustomerUI);
        lbWelcome->setObjectName(QStringLiteral("lbWelcome"));
        lbWelcome->setGeometry(QRect(130, 10, 351, 41));
        QFont font;
        font.setPointSize(27);
        lbWelcome->setFont(font);
        lbWelcome->setAlignment(Qt::AlignCenter);
        pushButton_5 = new QPushButton(tabCustomerUI);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 480, 101, 31));
        pushButton_6 = new QPushButton(tabCustomerUI);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(340, 520, 101, 31));
        pushButton_7 = new QPushButton(tabCustomerUI);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(340, 560, 101, 31));
        label_8 = new QLabel(tabCustomerUI);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(470, 500, 81, 81));
        groupBox = new QGroupBox(tabCustomerUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(340, 60, 511, 321));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 256, 192));
        cmbColour = new QComboBox(groupBox);
        cmbColour->setObjectName(QStringLiteral("cmbColour"));
        cmbColour->setGeometry(QRect(290, 30, 191, 31));
        cbWash = new QCheckBox(groupBox);
        cbWash->setObjectName(QStringLiteral("cbWash"));
        cbWash->setGeometry(QRect(290, 150, 100, 26));
        cbDry = new QCheckBox(groupBox);
        cbDry->setObjectName(QStringLiteral("cbDry"));
        cbDry->setGeometry(QRect(290, 180, 100, 26));
        cbSteam = new QCheckBox(groupBox);
        cbSteam->setObjectName(QStringLiteral("cbSteam"));
        cbSteam->setGeometry(QRect(290, 210, 100, 26));
        cbCentrifuge = new QCheckBox(groupBox);
        cbCentrifuge->setObjectName(QStringLiteral("cbCentrifuge"));
        cbCentrifuge->setGeometry(QRect(290, 240, 100, 26));
        cmbMaterial = new QComboBox(groupBox);
        cmbMaterial->setObjectName(QStringLiteral("cmbMaterial"));
        cmbMaterial->setGeometry(QRect(290, 70, 191, 31));
        nmrWeight = new QDoubleSpinBox(groupBox);
        nmrWeight->setObjectName(QStringLiteral("nmrWeight"));
        nmrWeight->setGeometry(QRect(290, 110, 50, 31));
        btAddGarment = new QPushButton(groupBox);
        btAddGarment->setObjectName(QStringLiteral("btAddGarment"));
        btAddGarment->setGeometry(QRect(380, 280, 121, 31));
        tabUI->addTab(tabCustomerUI, QString());
        tabAdministratorUI = new QWidget();
        tabAdministratorUI->setObjectName(QStringLiteral("tabAdministratorUI"));
        tabAdministratorUI->setAutoFillBackground(false);
        groupBox_2 = new QGroupBox(tabAdministratorUI);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 240, 351, 251));
        listViewMachines = new QListView(groupBox_2);
        listViewMachines->setObjectName(QStringLiteral("listViewMachines"));
        listViewMachines->setGeometry(QRect(10, 30, 331, 211));
        groupBox_3 = new QGroupBox(tabAdministratorUI);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 681, 231));
        listWidgetGarments = new QListWidget(groupBox_3);
        listWidgetGarments->setObjectName(QStringLiteral("listWidgetGarments"));
        listWidgetGarments->setGeometry(QRect(10, 30, 331, 192));
        lblGarmentId = new QLabel(groupBox_3);
        lblGarmentId->setObjectName(QStringLiteral("lblGarmentId"));
        lblGarmentId->setGeometry(QRect(370, 30, 301, 21));
        lblMaterial = new QLabel(groupBox_3);
        lblMaterial->setObjectName(QStringLiteral("lblMaterial"));
        lblMaterial->setGeometry(QRect(370, 50, 301, 21));
        lblWeight = new QLabel(groupBox_3);
        lblWeight->setObjectName(QStringLiteral("lblWeight"));
        lblWeight->setGeometry(QRect(370, 70, 321, 21));
        lblColoured = new QLabel(groupBox_3);
        lblColoured->setObjectName(QStringLiteral("lblColoured"));
        lblColoured->setGeometry(QRect(370, 90, 321, 21));
        lblWashingMachine = new QLabel(groupBox_3);
        lblWashingMachine->setObjectName(QStringLiteral("lblWashingMachine"));
        lblWashingMachine->setGeometry(QRect(370, 110, 321, 21));
        lblDryer = new QLabel(groupBox_3);
        lblDryer->setObjectName(QStringLiteral("lblDryer"));
        lblDryer->setGeometry(QRect(370, 130, 321, 21));
        lblSteamer = new QLabel(groupBox_3);
        lblSteamer->setObjectName(QStringLiteral("lblSteamer"));
        lblSteamer->setGeometry(QRect(370, 150, 321, 21));
        lblCentrifuge = new QLabel(groupBox_3);
        lblCentrifuge->setObjectName(QStringLiteral("lblCentrifuge"));
        lblCentrifuge->setGeometry(QRect(370, 170, 321, 21));
        btStopSelectedMachine = new QPushButton(tabAdministratorUI);
        btStopSelectedMachine->setObjectName(QStringLiteral("btStopSelectedMachine"));
        btStopSelectedMachine->setGeometry(QRect(400, 400, 251, 31));
        btAlarmStop = new QPushButton(tabAdministratorUI);
        btAlarmStop->setObjectName(QStringLiteral("btAlarmStop"));
        btAlarmStop->setGeometry(QRect(400, 440, 251, 31));
        btAddGarmentTest = new QPushButton(tabAdministratorUI);
        btAddGarmentTest->setObjectName(QStringLiteral("btAddGarmentTest"));
        btAddGarmentTest->setGeometry(QRect(480, 250, 101, 31));
        tabUI->addTab(tabAdministratorUI, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 877, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabUI->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btStartProgram->setText(QApplication::translate("MainWindow", "Start (S)washing", 0));
        label->setText(QApplication::translate("MainWindow", "Price:", 0));
        label_2->setText(QApplication::translate("MainWindow", "7,95", 0));
        label_3->setText(QApplication::translate("MainWindow", "Estimated duration:", 0));
        label_4->setText(QApplication::translate("MainWindow", "1 Hour", 0));
        label_5->setText(QApplication::translate("MainWindow", "Finished at:", 0));
        label_6->setText(QApplication::translate("MainWindow", "13.45", 0));
        btCallEmployee->setText(QApplication::translate("MainWindow", "Call an employee", 0));
        lbWelcome->setText(QApplication::translate("MainWindow", "Welcome To Swash!", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Connect", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Send", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Receivelabe", 0));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Add Garments:", 0));
        cmbColour->clear();
        cmbColour->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Black", 0)
         << QApplication::translate("MainWindow", "White", 0)
         << QApplication::translate("MainWindow", "Coloured", 0)
        );
        cbWash->setText(QApplication::translate("MainWindow", "Wash", 0));
        cbDry->setText(QApplication::translate("MainWindow", "Dry", 0));
        cbSteam->setText(QApplication::translate("MainWindow", "Steam", 0));
        cbCentrifuge->setText(QApplication::translate("MainWindow", "Centrifuge", 0));
        cmbMaterial->clear();
        cmbMaterial->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Cotton", 0)
         << QApplication::translate("MainWindow", "Silk", 0)
         << QApplication::translate("MainWindow", "Wool", 0)
         << QApplication::translate("MainWindow", "Satin", 0)
         << QApplication::translate("MainWindow", "Nylon", 0)
         << QApplication::translate("MainWindow", "Linen", 0)
         << QApplication::translate("MainWindow", "Polyester", 0)
        );
        btAddGarment->setText(QApplication::translate("MainWindow", "Add Garment", 0));
        tabUI->setTabText(tabUI->indexOf(tabCustomerUI), QApplication::translate("MainWindow", "Customer", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Machines", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Garments", 0));
        lblGarmentId->setText(QString());
        lblMaterial->setText(QString());
        lblWeight->setText(QString());
        lblColoured->setText(QString());
        lblWashingMachine->setText(QString());
        lblDryer->setText(QString());
        lblSteamer->setText(QString());
        lblCentrifuge->setText(QString());
        btStopSelectedMachine->setText(QApplication::translate("MainWindow", "Stop Selected Machine", 0));
        btAlarmStop->setText(QApplication::translate("MainWindow", "Alarm! Stop Everything", 0));
        btAddGarmentTest->setText(QApplication::translate("MainWindow", "PushButton", 0));
        tabUI->setTabText(tabUI->indexOf(tabAdministratorUI), QApplication::translate("MainWindow", "Administrator", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

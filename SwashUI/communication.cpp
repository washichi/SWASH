#include "communication.h"


//#include <QWebSocket>
#include <QtCore/QDebug>
#include <QCoreApplication>
#include <iostream>
#include <QTimer>
#include <QException>
#include <QMessageBox>
#include <QProcess>
#include <arpa/inet.h>
#include <QtCore>
#include <QEvent>

Communication::Communication(const char * ipaddress, unsigned short port, QObject *parent) : QThread(parent)
{
    qRegisterMetaType<std::string>("std::string");
    Stop = true;
    socketdescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socketdescriptor == -1)
    {
        perror("Socket could not be created!\n");
        Stop = false;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ipaddress);
    server.sin_port = htons(port);

    if(::connect(socketdescriptor, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Could not connect!\n");
        Stop = false;
    }

    lastMessage = "";
}

void Communication::SendMessage(QString message)
{
    const char *messagee = message.toStdString().c_str();
    write(socketdescriptor, messagee, strlen(messagee));

    QEventLoop loop;
    connect(this, SIGNAL(messageReceived(std::string)), &loop, SLOT(quit()));
    loop.exec();
}

QString Communication::GetLastMessage()
{
    QString tempMessage = lastMessage;
    lastMessage = "";
    return tempMessage;
}

std::string Communication::ReceiveMessage()
{
    char buffer[256];
    int nrOfBytes = -1;
    nrOfBytes = recv(socketdescriptor, buffer, 255, 0);
    std::string compiledString = "";
    int j;
    if(nrOfBytes != -1)
    {
        for (j = 0; j < nrOfBytes; j++)
        {
            compiledString += buffer[j];
        }
    }
    lastMessage = QString::fromLocal8Bit(compiledString.c_str());
    qDebug() << lastMessage;
    return compiledString;
}

void Communication::run()
{
    Stop = false;
    while(!Stop)
    {
        std::string receivedString = ReceiveMessage();
        emit messageReceived(receivedString);
    }
}

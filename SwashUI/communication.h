#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QtCore/QObject>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <QThread>
#include <QMetaType>
#include <QMutex>
#include <QEvent>
#include <QObject>

class Communication : public QThread
{
    Q_OBJECT

public:
    Communication(const char * ipaddress, unsigned short port, QObject *parent = 0);
    void SendMessage(QString);
    std::string ReceiveMessage();
    QString GetLastMessage();
    void run();
    bool Stop;
    QString lastMessage;

private:
    int socketdescriptor;
    struct sockaddr_in server;

signals:
    void messageReceived(std::string message);

public slots:

};


#endif // COMMUNICATION_H

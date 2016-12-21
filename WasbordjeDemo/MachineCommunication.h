#ifndef MACHINECOMMUNICATION_H
#define MACHINECOMMUNICATION_H

#include "Arduino.h"
#include <Ethernet.h>

class MachineCommunication
{
  public:
    MachineCommunication(IPAddress ip, IPAddress server, int port);
    ~MachineCommunication();
    void SendCommand(String message);
    int ReceiveCommand();
    String GetInfo();    

  private:
    IPAddress ip;
    IPAddress server;
    int port;
    EthernetClient client;
};

#endif

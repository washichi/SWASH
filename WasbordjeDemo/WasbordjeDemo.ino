#include "MachineCommunication.h"

IPAddress ip(10, 0, 0, 45);
IPAddress server(10, 0, 0 , 15);
int port = 5001; // port 5001 is unused in TCP

MachineCommunication* machineCommunication;

void setup()
{

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Connecting...");

  machineCommunication = new MachineCommunication(ip, server, port);
  /*
    // Initialize the ethernet device
    if (Ethernet.begin(mac) != 1)
    {
      Ethernet.begin(mac, ip);  //ip needed if the PC is the server (pc doesn't have dhcp to give the Arduino an IP)
    }
    Serial.println(Ethernet.localIP());

    // Connect to the server
    while (!client.connect(server, 5001))
    {
      Serial.println("connection failed");
    }
    Serial.println("connected");
  */
}

void CheckCommand(int command)
{
  switch (command)
  {
    case 001:
      machineCommunication->SendCommand("#Door opened$");
      break;
    case 002:

      machineCommunication->SendCommand("#Door closed$");
      break;
    case 999:
      machineCommunication->SendCommand("#Start machinetests$");

      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}


void loop()
{
  int command = machineCommunication->ReceiveCommand();
  CheckCommand(command);

}


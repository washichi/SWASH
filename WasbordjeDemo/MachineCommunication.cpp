#include "MachineCommunication.h"

MachineCommunication::MachineCommunication(IPAddress ip, IPAddress server, int port)
{
  this->ip = ip;
  this->server = server;
  this->port = port;
  byte mac[] = {
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
  };

  Serial.println("Get IP");
  if (Ethernet.begin(mac) != 1)
  {
    Serial.println("No DHCP, assigning auto ip");
    Ethernet.begin(mac, this->ip);  //ip needed if the PC is the server (pc doesn't have dhcp to give the Arduino an IP)
  }

  while (!client.connect(server, port))
  {
    Serial.println("connection failed");
  }
  Serial.println("connected");
}

MachineCommunication::~MachineCommunication()
{

}

void MachineCommunication::SendCommand(String message)
{
  if (message.startsWith("#") && message.endsWith("$"))
  {
    client.println(message);
  }
  else
  {
    //Give error feedback
  }
}

int MachineCommunication::ReceiveCommand()
{
    char thisChar = client.read();
    String command_str;
    int command;
    if (thisChar == '#')
    {
      command_str = client.readStringUntil('$');
      Serial.println(command_str);
      if (command = command_str.toInt() == 0)
      {
        return -1;
      }
      return command;
    }
  /*
  String commandStr;
  if (client.available() > 0)
  {
    // read the bytes incoming from the client:

    
    char thisChar = client.read();
    test += thisChar;
*/
    
    
    
    /*
    char thisChar = "";
    do
    {
      thisChar += client.read();
    }
    while(client.read() != -1);

    Serial.println(thisChar);
    */

    /*
    String command_str;
    int command;
    if (thisChar == '#')
    {
      command_str = client.readStringUntil('$');
      Serial.println(command_str);
      if (command = command_str.toInt() == 0)
      {
        return -1;
      }
      return command;
    }
    
  }
  */
  //Serial.println(test);
  return -1;
}

String MachineCommunication::GetInfo()
{
  IPAddress address = Ethernet.localIP();
  return String(address[0]) + "." +
         String(address[1]) + "." +
         String(address[2]) + "." +
         String(address[3]);
}


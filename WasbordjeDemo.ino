#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 0, 0, 45);
IPAddress server(10, 0, 0 , 50);
int port = 5001; // port 5001 is unused in TCP

EthernetClient client;
//boolean alreadyConnected = false; // whether or not the client was connected previously

void setup() {
  // initialize the ethernet device
  Ethernet.begin(mac, ip);//ip needed if the PC is the server (pc doesn't have dhcp to give the Arduino an IP)
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Connecting...");

  while (!client.connect(server, 5001))
  {
    Serial.println("connection failed");
  }
  Serial.println("connected");

}

/*
  CheckCommand(int command)
  {
  if(command == 001)
  {
    Serial.print("zorg dat hier de deur open gaat, sesam open u shit");
  }
  }
*/

void loop() {

  if (client.available() > 0) {
    // read the bytes incoming from the client:
    char thisChar = client.read();
    String command_str;
    int command;
    if (thisChar == '#')
    {
      command_str = client.readStringUntil('$');
      command = command_str.toInt();
    }
    // echo the bytes back to the client:
    //server.write(thisChar);
    //CheckCommand(command);
    switch (command)
    {
      case 001:

        client.println("Door opened");
        break;
      case 002:

        client.println("Door closed");
        break;
      case 999:
        client.println("Start machinetests");
       
        break;
      default:
        // if nothing else matches, do the default
        // default is optional
        break;
    }
  }
}





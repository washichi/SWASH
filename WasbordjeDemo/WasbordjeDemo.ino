#include "MachineCommunication.h"
#include "Machine.h"
#include "WashingMachine.h"

// te bepalen voor uploaden naar Arduino:
Machine* machine;
MachineType machinetype = washingmachine;
int drumsize = 5;
String whoami = "";
IPAddress ip(10, 0, 0, 45);
IPAddress server(10, 0, 0, 15);
int port = 5001; // port 5001 is unused in TCP

MachineCommunication* machineCommunication;

bool Whoami()
{
  switch (machinetype)
  {
    case washingmachine:
      whoami = 001;
      break;

    case dryer:
      whoami = 002;
      break;

    case steamer:
      whoami = 003;
      break;

    case centrifuge:
      whoami = 004;
      break;

    default:
      //machine not recognized.
      return false;
      break;
  }

  return true;
}

void setup()
{

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Connecting...");
  // not aanpassen aan machine:
  machine = new WashingMachine(drumsize);
  machineCommunication = new MachineCommunication(ip, server, port);

  if (Whoami() == false)
  {
    // whoami not recognized
    Serial.println("WHOAMI not recognized, invalid machinetype");
    return;
  }
  
  machineCommunication->SendCommand("#" + whoami + "$");
  Serial.println("WHOAMI sended");
}

void CheckCommand(int command)
{
  switch (command)
  {
    case 15:
      //wasprogramma A
      machine->Start('A');
      //hearbeat iets? : machineCommunication->SendCommand("#Door opened$");
      break;
    case 16:
      //wasprogramma B
      break;
    case 17:
      //wasprogramma C
      break;
    case 18:
      //Dryprogram A
      break;
    case 19:
      //Dryprogram B
      break;
    case 20:
      //Dryprogram C
      break;
    case 21:
      //Steamprogram A
      break;
    case 22:
      //Steamprogram B
      break;
    case 23:
      //Steamprogram C
      break;
    case 24:
      //Centrifugeprogram A
      break;
    case 25:
      //Centrifugeprogram B
      break;
    case 26:
      //Centrifugeprogram C
      break;
    case 999:
      //machinetest
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


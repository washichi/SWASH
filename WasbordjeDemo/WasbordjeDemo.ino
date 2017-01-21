#include "MachineCommunication.h"
#include "Machine.h"
#include "WashingMachine.h"
#include "Dryer.h"
#include "SteamMachine.h"
#include "Centrifuge.h"

// hardcoded machinetype and drumsize:
const MachineType machinetype = washingmachine;
const int drumsize = 5;

String machineID = "";
char program = ' ';
const IPAddress ip(10, 0, 0, 45);
const IPAddress server(10, 0, 0, 15);
const int port = 5001; // port 5001 is unused in TCP

MachineCommunication* machineCommunication;
Machine* machine = NULL;

// creates machine based on machinetype variable
bool machineInit()
{
  switch (machinetype)
  {
    case washingmachine:
      machine = new WashingMachine(drumsize);
      machineID = 001;
      break;

    case dryer:
      machine = new Dryer(drumsize);
      machineID = 002;
      break;

    case steammachine:
      machine = new SteamMachine(drumsize);
      machineID = 003;
      break;

    case centrifuge:
      machine = new Centrifuge(drumsize);
      machineID = 004;
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

  machineCommunication = new MachineCommunication(ip, server, port);
  // create a machine
  if (machineInit() == false)
  {
    //machine not recognized
    Serial.println("machine not recognized, invalid machinetype");
    return;
  }
  if(machine == NULL)
  {
    // machine creation failed
    Serial.println("error while creating machine");
    return;
  }
  machineCommunication->SendCommand("#" + machineID + "$");
  Serial.println("machineID sended");
}


//function to convert command to action via protocol
void CheckCommand(int command)
{
  switch (command)
  {
    case 5:
      //start machine
      Serial.println("starting program: " + String(program) +  ", machineID: " + machineID);
      machine->Start(program);
      break;
    case 9:
      //emergency

      break;
    case 15:  //washprogram A
    case 18:  //Dryprogram A
    case 21:  //Steamprogram A
    case 24:  //Centrifugeprogram A
      program = 'A';
      break;
    case 16:  //washprogram  B
    case 19:  //Dryprogram B
    case 22:  //Steamprogram B
    case 25:  //Centrifugeprogram B
      program = 'B';
      break;
    case 17:  //washprogram  C
    case 20:  //Dryprogram C
    case 23:  //Steamprogram C
    case 26:  //Centrifugeprogram C
      program = 'C';
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


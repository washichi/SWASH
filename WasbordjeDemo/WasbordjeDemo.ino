#include "MachineCommunication.h"
#include "Machine.h"
#include "WashingMachine.h"
#include "Dryer.h"
#include "SteamMachine.h"
#include "Centrifuge.h"

// hardcoded machinetype and drumsize:
const MachineType machinetype = washingmachine;
const int drumsize = 10;

String machineID = "";
char program = ' ';
String programID = "";
MachineState machinestate = stateUnknown;
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
      machine = new WashingMachine(drumsize, *machineCommunication);
      machineID = 001;
      break;

    case dryer:
      machine = new Dryer(drumsize, *machineCommunication);
      machineID = 002;
      break;

    case steammachine:
      machine = new SteamMachine(drumsize, *machineCommunication);
      machineID = 003;
      break;

    case centrifuge:
      machine = new Centrifuge(drumsize, *machineCommunication);
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
  if (machine == NULL)
  {
    // machine creation failed
    Serial.println("error while creating machine");
    return;
  }
  machineCommunication->SendCommand("#" + machineID + "$");
  machinestate = idle;
  Serial.println("machineID sended");
}

String WaterLevelMapper()
{
  int waterlevel = 50;//machine->GetWaterLevel();
  waterlevel  = map(waterlevel, 0, 100, 100, 200);
  return String(waterlevel);
}

String TemperatureMapper()
{
  int temperature = 50;//machine->GetTemperature();
  temperature  = map(temperature, 0, 100, 201, 300);
  return String(temperature);
}

//function to convert command to action via protocol
void CheckCommand(int command)
{
  switch (command)
  {
    case 5:
      //start machine
      machineCommunication->SendCommand("#005$");
      Serial.println("starting program: " + String(program) +  ", machineID: " + machineID);
      if (machine->Start(program))
      {
        // send done command
        machineCommunication->SendCommand("#008$");
        machinestate = idle;
      }
      break;
    case 9:
      //emergency
      break;

    case 10:
      return program;
      break;
    case 11:
      // return waterlevel;
      machineCommunication->SendCommand("#" + WaterLevelMapper() + "$");
      break;
    case 12:
      // return temperature;
      machineCommunication->SendCommand("#" + TemperatureMapper() + "$");
      break;
    case 15:  //washprogram A
      if (machinestate != idle){return;}
      else
      {
        program = 'A';
        programID = "015";
        CheckCommand(5);
      }
      break;
    case 18:  //Dryprogram A
      if (machinestate != idle){return;}
      else
      {
        program = 'A';
        programID = "018";
        CheckCommand(5);
      }
      break;
    case 21:  //Steamprogram A
      if (machinestate != idle){return;}
      else
      {
        program = 'A';
        programID = "021";
        CheckCommand(5);
      }
      break;
    case 24:  //Centrifugeprogram A
      if (machinestate != idle){return;}
      else
      {
        program = 'A';
        programID = "024";
        CheckCommand(5);
      }
      break;
    case 16:  //washprogram  B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "016";
      CheckCommand(5);
      }
      break;    
    case 19:  //Dryprogram B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "019";
      CheckCommand(5);
      }
      break;
    case 22:  //Steamprogram B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "022";
      CheckCommand(5);
      }
      break;
    case 25:  //Centrifugeprogram B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "025";
      CheckCommand(5);
      }
      break;
    case 17:  //washprogram  C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      programID = "017";
      CheckCommand(5);
      }
      break;
    case 20:  //Dryprogram C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      programID = "020";
      CheckCommand(5);
      }
      break;
    case 23:  //Steamprogram C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      programID = "023";
      CheckCommand(5);
      }
      break;
    case 26:  //Centrifugeprogram C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      CheckCommand(5);
      }
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


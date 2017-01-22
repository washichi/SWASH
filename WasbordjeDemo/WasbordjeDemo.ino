#include "MachineControl.h"
#include "MachineCommunication.h"
#include "Machine.h"
#include "WashingMachine.h"
#include "Dryer.h"
#include "SteamMachine.h"
#include "Centrifuge.h"

// hardcoded machinetype and drumsize:
const MachineType machinetype = washingmachine;
const int drumsize = 10;


const IPAddress ip(10, 0, 0, 45);
const IPAddress server(10, 0, 0, 15);
const int port = 5001; // port 5001 is unused in TCP

MachineCommunication* machineCommunication;
MachineControl* machineControl;
Machine* machine = NULL;



void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Connecting...");

  machineCommunication = new MachineCommunication(ip, server, port);
    // create a machine
  machinecontrol = new MachineControl(*machineCommunication, machinetype);
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




void loop()
{
  int command = machineCommunication->ReceiveCommand();
  CommandExecutioni(command);

}


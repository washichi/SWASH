#include "MachineControl.h"


MachineControl::MachineControl(MachineCommunication& com, MachineType type)
  : machineCommunication(com)
  , machinetype(type)
  , machineID("")
  , program(' ')
  , programID("")
{
  //hardware = new iHardwareControl();
  machinetype = type;
  if(&com == NULL || type == NULL)
  {
    //ERROR!
  }
	if(!machineInit())
	{
		// machine init failed
    // eror!!!!!!!!!!
	}
}

MachineControl::~MachineControl()
{
  //delete hardware;

}


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


//function to convert command to action via protocol
void CommandExecution(int command)
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
        CommandExecution(5);
      }
      break;
    case 18:  //Dryprogram A
      if (machinestate != idle){return;}
      else
      {
        program = 'A';
        programID = "018";
        CommandExecution(5);
      }
      break;
    case 21:  //Steamprogram A
      if (machinestate != idle){return;}
      else
      {
        program = 'A';
        programID = "021";
        CommandExecution(5);
      }
      break;
    case 24:  //Centrifugeprogram A
      if (machinestate != idle){return;}
      else
      {
        program = 'A';
        programID = "024";
        CommandExecution(5);
      }
      break;
    case 16:  //washprogram  B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "016";
      CommandExecution(5);
      }
      break;    
    case 19:  //Dryprogram B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "019";
      CommandExecution(5);
      }
      break;
    case 22:  //Steamprogram B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "022";
      CommandExecution(5);
      }
      break;
    case 25:  //Centrifugeprogram B
      if (machinestate != idle){return;}
      else
      {
      program = 'B';
      programID = "025";
      CommandExecution(5);
      }
      break;
    case 17:  //washprogram  C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      programID = "017";
      CommandExecution(5);
      }
      break;
    case 20:  //Dryprogram C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      programID = "020";
      CommandExecution(5);
      }
      break;
    case 23:  //Steamprogram C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      programID = "023";
      CommandExecution(5);
      }
      break;
    case 26:  //Centrifugeprogram C
      if (machinestate != idle){return;}
      else
      {
      program = 'C';
      CommandExecution(5);
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


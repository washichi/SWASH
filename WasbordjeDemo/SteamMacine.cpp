#include "SteamMachine.h"

SteamMachine::SteamMachine(int drumSize, MachineCommunication& com)
  : Machine(drumSize, com)
  , temperature(0)
  , pressure(0)
{
  
}

SteamMachine::~SteamMachine()
{
  
}

bool SteamMachine::Start(char program)
{
  currentProgram = program;
  switch (program)
  {
    case 'A':
      hardware->setProgramLed(1);
      //set variables:
      TempControl(50);
      steamPhase1.timesExecuted =  1;
      steamPhase1.rotateClockwise = 1;
      steamPhase1.speed = 1; // lowest speed
      steamPhase1.time = 60; //time in sec
      steamPhase2.timesExecuted = 1;
      steamPhase2.rotateClockwise = 0; // counterclockwise
      steamPhase2.speed = 1; // lowest speed
      steamPhase2.time = 60; //time in sec
      break;

    case 'B':
      hardware->setProgramLed(2);
      //set variables:
      TempControl(30);
      steamPhase1.timesExecuted =  1;
      steamPhase1.rotateClockwise = 1;
      steamPhase1.speed = 3; // regular
      steamPhase1.time = 30; //time in sec
      steamPhase2.timesExecuted = 1;
      steamPhase2.rotateClockwise = 0; // counterclockwise
      steamPhase2.speed = 3; // regular
      steamPhase2.time = 30; //time in sec     
      break;

    case 'C':
      hardware->setProgramLed(3);
      //set variables: 
	  TempControl(40);
      steamPhase1.timesExecuted =  2;
      steamPhase1.rotateClockwise = 1;
      steamPhase1.speed = 2; // regular
      steamPhase1.time = 30; //time in sec
      steamPhase2.timesExecuted = 2;
      steamPhase2.rotateClockwise = 0; // counterclockwise
      steamPhase2.speed = 2; // regular
      steamPhase2.time = 30; //time in sec     
      break;
    default:
      break;
  }

  programRunning = true;
  hardware->lockDoor(true);

  Program(steamPhase1);
  Program(steamPhase2);

  hardware->lockDoor(false);
  programRunning = false;
  return true;
}

bool SteamMachine::Program(motorPhase &program)
{
  for (int i = 0; i < program.timesExecuted; i++)
  {
    hardware->SetDirection(program.rotateClockwise);
    hardware->SetSpeed(program.speed);
    /*
      clock_t start_time = clock();
      while((clock() - start_time) < (prewash.motorPhase1.time * 1000))
      {
        tempControl(prewash.heat);
      }
    */
    for (int j = 0; j < (program.time * 10000); j++)
    {
      // ##########################################################
      // CHECK FOR MESSAGES
      // ##########################################################
    }
  }

  return true;
}


int SteamMachine::GetPressure()
{
  return pressure;
}

int SteamMachine::getTemperature()
{
  return temperature;
}

void SteamMachine::ProduceSteam()
{
  
}

void SteamMachine::Heat(int temperature)
{
  if(temperature < 0)
  {
    //throw invalid_argument("Temperature has to be greater than 0");
  }
}


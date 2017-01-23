#include "Dryer.h"

Dryer::Dryer(int drumSize, MachineCommunication& com)
  : Machine(drumSize, com)
  , temperature(0)
{
  
}

Dryer::~Dryer()
{
  
}

bool Dryer::TempControl(int temp)
{
  if (GetTemperature() < temp)
  {
    hardware->SetHeater(true);
    return false;
  }
  else
  {
    hardware->SetHeater(false);
    return true;
  }
}

bool Dryer::Start(char program)
{
  currentProgram = program;
  switch (program)
  {
    case 'A':
      hardware->setProgramLed(1);
      //set variables:
      TempControl(50);
      dryerPhase1.timesExecuted =  1;
      dryerPhase1.rotateClockwise = 1;
      dryerPhase1.speed = 1; // lowest speed
      dryerPhase1.time = 60; //time in sec
      dryerPhase2.timesExecuted = 1;
      dryerPhase2.rotateClockwise = 0; // counterclockwise
      dryerPhase2.speed = 1; // lowest speed
      dryerPhase2.time = 60; //time in sec
      break;

    case 'B':
      hardware->setProgramLed(2);
      //set variables:
      TempControl(30);
      dryerPhase1.timesExecuted =  1;
      dryerPhase1.rotateClockwise = 1;
      dryerPhase1.speed = 3; // regular
      dryerPhase1.time = 30; //time in sec
      dryerPhase2.timesExecuted = 1;
      dryerPhase2.rotateClockwise = 0; // counterclockwise
      dryerPhase2.speed = 3; // regular
      dryerPhase2.time = 30; //time in sec     
      break;

    case 'C':
      hardware->setProgramLed(3);
      //set variables: 
	  TempControl(40);
      dryerPhase1.timesExecuted =  2;
      dryerPhase1.rotateClockwise = 1;
      dryerPhase1.speed = 2; // regular
      dryerPhase1.time = 30; //time in sec
      dryerPhase2.timesExecuted = 2;
      dryerPhase2.rotateClockwise = 0; // counterclockwise
      dryerPhase2.speed = 2; // regular
      dryerPhase2.time = 30; //time in sec     
      break;
    default:
      break;
  }

  programRunning = true;
  hardware->lockDoor(true);

  Program(dryerPhase1);
  Program(dryerPhase2);

  hardware->lockDoor(false);
  programRunning = false;
  return true;
}

bool Dryer::Program(motorPhase &program)
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

//

int Dryer::GetTemperature()
{
  return temperature;
}




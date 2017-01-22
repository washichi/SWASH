#include "Centrifuge.h"

Centrifuge::Centrifuge(int drumSize, MachineCommunication& com)
  : Machine(drumSize,com)
{
  
}

Centrifuge::~Centrifuge()
{
  
}

bool Centrifuge::Start(char program)
{
  currentProgram = program;
  switch (program)
  {
    case 'A':
      hardware->setProgramLed(1);
      //set variables:
      centrifugePhase1.timesExecuted =  1;
      centrifugePhase1.rotateClockwise = 1;
      centrifugePhase1.speed = 1; // lowest speed
      centrifugePhase1.time = 60; //time in sec
      centrifugePhase2.timesExecuted = 1;
      centrifugePhase2.rotateClockwise = 0; // counterclockwise
      centrifugePhase2.speed = 1; // lowest speed
      centrifugePhase2.time = 60; //time in sec
      break;

    case 'B':
      hardware->setProgramLed(2);
      //set variables:
      centrifugePhase1.timesExecuted =  1;
      centrifugePhase1.rotateClockwise = 1;
      centrifugePhase1.speed = 3; // regular
      centrifugePhase1.time = 30; //time in sec
      centrifugePhase2.timesExecuted = 1;
      centrifugePhase2.rotateClockwise = 0; // counterclockwise
      centrifugePhase2.speed = 3; // regular
      centrifugePhase2.time = 30; //time in sec     
      break;

    case 'C':
      hardware->setProgramLed(3);
      //set variables:     
      centrifugePhase1.timesExecuted =  2;
      centrifugePhase1.rotateClockwise = 1;
      centrifugePhase1.speed = 2; // regular
      centrifugePhase1.time = 30; //time in sec
      centrifugePhase2.timesExecuted = 2;
      centrifugePhase2.rotateClockwise = 0; // counterclockwise
      centrifugePhase2.speed = 2; // regular
      centrifugePhase2.time = 30; //time in sec     
      break;
    default:
      break;
  }

  programRunning = true;
  hardware->lockDoor(true);

  Program(centrifugePhase1);
  Program(centrifugePhase2);

  hardware->lockDoor(false);
  programRunning = false;
  return true;
}

bool Centrifuge::Program(motorPhase &program)
{
  hardware->openSink();
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
  hardware->closeSink();

  return true;
}


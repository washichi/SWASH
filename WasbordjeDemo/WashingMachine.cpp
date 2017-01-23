#include "WashingMachine.h"




WashingMachine::WashingMachine(int drumSize, MachineCommunication& com)
  : Machine(drumSize, com)
  , temperature(0)
{
  waterlevel = 0;
}


bool WashingMachine::Start(char program)
{
  currentProgram = program;
  switch (program)
  {
    case 'A':
      hardware->setProgramLed(1);
      //set variables:
      prewash.takeWater = 2; // 50%
      prewash.heat = 0;
      prewash.soap = 1;
      prewash.motorPhase1.timesExecuted =  1;
      prewash.motorPhase1.rotateClockwise = 1;
      prewash.motorPhase1.speed = 1; // lowest speed
      prewash.motorPhase1.time = 60; //time in sec
      prewash.motorPhase2.timesExecuted = 1;
      prewash.motorPhase2.rotateClockwise = 0; // counterclockwise
      prewash.motorPhase2.speed = 1; // lowest speed
      prewash.motorPhase2.time = 60; //time in sec

      mainwash1.takeWater = 2; // 50%
      mainwash1.heat = 2; // 50%
      mainwash1.soap = 2;
      mainwash1.motorPhase1.timesExecuted =  2;
      mainwash1.motorPhase1.rotateClockwise = 1;
      mainwash1.motorPhase1.speed = 2; // regular
      mainwash1.motorPhase1.time = 60; //time in sec
      mainwash1.motorPhase2.timesExecuted = 2;
      mainwash1.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash1.motorPhase2.speed = 2; // regular
      mainwash1.motorPhase2.time = 60; //time in sec

      mainwash2.takeWater = 2; // 50%
      mainwash2.heat = 0;
      mainwash2.soap = 0;
      mainwash2.motorPhase1.timesExecuted =  2;
      mainwash2.motorPhase1.rotateClockwise = 1;
      mainwash2.motorPhase1.speed = 2; // regular
      mainwash2.motorPhase1.time = 60; //time in sec
      mainwash2.motorPhase2.timesExecuted = 2;
      mainwash2.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash2.motorPhase2.speed = 2; // regular
      mainwash2.motorPhase2.time = 60; //time in sec
      break;

    case 'B':
      hardware->setProgramLed(2);
      //set variables:
      prewash.takeWater = 2; // 50%
      prewash.heat = 2; // 50%
      prewash.soap = 1;
      prewash.motorPhase1.timesExecuted =  1;
      prewash.motorPhase1.rotateClockwise = 1;
      prewash.motorPhase1.speed = 2; // regular
      prewash.motorPhase1.time = 60; //time in sec
      prewash.motorPhase2.timesExecuted = 1;
      prewash.motorPhase2.rotateClockwise = 0; // counterclockwise
      prewash.motorPhase2.speed = 2; // regular
      prewash.motorPhase2.time = 60; //time in sec

      mainwash1.takeWater = 2; // 50%
      mainwash1.heat = 50;
      mainwash1.soap = 2;
      mainwash1.motorPhase1.timesExecuted =  2;
      mainwash1.motorPhase1.rotateClockwise = 1;
      mainwash1.motorPhase1.speed = 2; // regular
      mainwash1.motorPhase1.time = 60; //time in sec
      mainwash1.motorPhase2.timesExecuted = 2;
      mainwash1.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash1.motorPhase2.speed = 2; // regular
      mainwash1.motorPhase2.time = 60; //time in sec

      mainwash2.takeWater = 2; // 50%
      mainwash2.heat = 0;
      mainwash2.soap = 0;
      mainwash2.motorPhase1.timesExecuted =  2;
      mainwash2.motorPhase1.rotateClockwise = 1;
      mainwash2.motorPhase1.speed = 2; // regular
      mainwash2.motorPhase1.time = 60; //time in sec
      mainwash2.motorPhase2.timesExecuted = 2;
      mainwash2.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash2.motorPhase2.speed = 2; // regular
      mainwash2.motorPhase2.time = 60; //time in sec
      break;

    case 'C':
      hardware->setProgramLed(3);
      //set variables:
      prewash.takeWater = 2; // 50%
      prewash.heat = 2; // 50%
      prewash.soap = 1;
      prewash.motorPhase1.timesExecuted =  1;
      prewash.motorPhase1.rotateClockwise = 1;
      prewash.motorPhase1.speed = 2; // regular
      prewash.motorPhase1.time = 60; //time in sec
      prewash.motorPhase2.timesExecuted = 1;
      prewash.motorPhase2.rotateClockwise = 0; // counterclockwise
      prewash.motorPhase2.speed = 2; // regular
      prewash.motorPhase2.time = 60; //time in sec

      mainwash1.takeWater = 3; //100%
      mainwash1.heat = 3; //100%
      mainwash1.soap = 2;
      mainwash1.motorPhase1.timesExecuted = 4;
      mainwash1.motorPhase1.rotateClockwise = 1;
      mainwash1.motorPhase1.speed = 3; // highest speed
      mainwash1.motorPhase1.time = 60; //time in sec
      mainwash1.motorPhase2.timesExecuted = 4;
      mainwash1.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash1.motorPhase2.speed = 3; // highest speed
      mainwash1.motorPhase2.time = 60; //time in sec

      mainwash2.takeWater = 2; // 50%
      mainwash2.heat = 0;
      mainwash2.soap = 0;
      mainwash2.motorPhase1.timesExecuted =  4;
      mainwash2.motorPhase1.rotateClockwise = 1;
      mainwash2.motorPhase1.speed = 3; // highest speed
      mainwash2.motorPhase1.time = 60; //time in sec
      mainwash2.motorPhase2.timesExecuted = 4;
      mainwash2.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash2.motorPhase2.speed = 3; // highest speed
      mainwash2.motorPhase2.time = 60; //time in sec
      break;
    default:
      break;
  }

  programRunning = true;
  hardware->lockDoor(true);

  Program(prewash);
  Program(mainwash1);
  Program(mainwash2);

  hardware->lockDoor(false);
  programRunning = false;
  return true;
}

bool WashingMachine::TempControl(int temp)
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

bool WashingMachine::MotorCyclus(int dir, int speed, int time, int repeat, int heat)
{
  for (int i = 0; i < repeat; i++)
  {
    hardware->SetDirection(dir);
    hardware->SetSpeed(speed);
    /*
      clock_t start_time = clock();
      while((clock() - start_time) < (prewash.motorPhase1.time * 1000))
      {
        tempControl(prewash.heat);
      }
    */
    for (int j = 0; j < (time * 10000); j++)
    {
      // ##########################################################
      // CHECK FOR MESSAGES
      // ##########################################################
      TempControl(heat);
    }
  }
}

void WashingMachine::SetSoap(int soap)
{
  switch (soap)
  {
    case 0:
      hardware->setSoap1Led(false);
      hardware->setSoap2Led(false);
      break;

    case 1:
      hardware->setSoap1Led(true);
      hardware->setSoap2Led(false);
      break;

    case 2:
      hardware->setSoap1Led(false);
      hardware->setSoap2Led(true);
      break;

    default:
      break;

  }
}

bool WashingMachine::Program(wash & program)
{
  //Water pakken -> blocking tot juiste niveau
  Serial.println("Water pakken");

  hardware->closeSink();
  hardware->openDrain();
  while (GetWaterlevel() < program.takeWater)
  {
    // ##########################################################
    // CHECK FOR MESSAGES
    //int receivedcommand = machineCommunication->ReceiveCommand();
    //CheckCommand(receivedcommand);
    // ##########################################################
    TempControl(program.heat); // alvast beginnen met opwarmen
  }
  hardware->closeDrain();

  //Verwarmen -> blocking Koelt automatisch af wanneer niet aan
  Serial.println("Verwarmen");
  while ((TempControl(program.heat)) == false)
  {
    // ##########################################################
    // CHECK FOR MESSAGES
    // ##########################################################
    TempControl(program.heat);
  }

  //Zeep toevoegen
  Serial.println("Zeep pakken");
  SetSoap(program.soap);

  //Motor starten voor bepaalde tijd
  Serial.println("Motorcyclus");
  MotorCyclus(program.motorPhase1.rotateClockwise, program.motorPhase1.speed, program.motorPhase1.time,
              program.motorPhase1.timesExecuted, program.heat);
  MotorCyclus(program.motorPhase2.rotateClockwise, program.motorPhase2.speed, program.motorPhase2.time,
              program.motorPhase2.timesExecuted, program.heat);

  SetSoap(0);
  TempControl(0);
  hardware->SetSpeed(0);

  //Water aflaten -> blocking tot juiste niveau
  Serial.println("Water aflaten");

  hardware->openSink();
  while (GetWaterlevel() != 0)
  {
    // ##########################################################
    // CHECK FOR MESSAGES
    // ##########################################################    
  }
  hardware->closeSink();


  return true;
}


int WashingMachine::GetWaterlevel()
{
  waterlevel = hardware->getWaterLevel();
  return waterlevel;
}

int WashingMachine::GetTemperature()
{
  temperature = hardware->getTemperature();
  return temperature;
}

void WashingMachine::TakeWater(int waterlevel)
{
  if (waterlevel < 0)
  {
    //throw invalid_argument("Waterlevel has to be higher than 0");
  }
}

void WashingMachine::Sink()
{

}

void WashingMachine::Heat(int temperature)
{
  if (temperature < 0)
  {
    //throw invalid_argument("Temperature has to be greater than 0");
  }
}


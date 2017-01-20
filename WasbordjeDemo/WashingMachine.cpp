#include "WashingMachine.h"

struct motorPhase
{
  int timesExecuted;
  int rotateClockwise;
  int speed;
  int time;
} ;


struct wash {
  int takeWater;
  int heat;
  int soap;
  motorPhase motorPhase1;
  motorPhase motorPhase2;
} ;

wash prewash;
wash mainwash1;
wash mainwash2;


WashingMachine::WashingMachine(int drumSize)
  : Machine(drumSize)
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
      //zet variabele;
      prewash.takeWater = 50;
      prewash.heat = 0;
      prewash.soap = 1;
      prewash.motorPhase1.timesExecuted =  1;
      prewash.motorPhase1.rotateClockwise = 1;
      prewash.motorPhase1.speed = 2; // regular
      prewash.motorPhase1.time = 60; //time in sec
      prewash.motorPhase2.timesExecuted = 1;
      prewash.motorPhase2.rotateClockwise = 0; // counterclockwise
      prewash.motorPhase2.speed = 2; // regular
      prewash.motorPhase2.time = 60; //time in sec

      mainwash1.takeWater = 50;
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

      mainwash2.takeWater = 50;
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
      //zet variabele;
      prewash.takeWater = 50;
      prewash.heat = 50;
      prewash.soap = 1;
      prewash.motorPhase1.timesExecuted =  1;
      prewash.motorPhase1.rotateClockwise = 1;
      prewash.motorPhase1.speed = 2; // regular
      prewash.motorPhase1.time = 60; //time in sec
      prewash.motorPhase2.timesExecuted = 1;
      prewash.motorPhase2.rotateClockwise = 0; // counterclockwise
      prewash.motorPhase2.speed = 2; // regular
      prewash.motorPhase2.time = 60; //time in sec

      mainwash1.takeWater = 50;
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

      mainwash2.takeWater = 50;
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
      //zet variabele;
      prewash.takeWater = 50;
      prewash.heat = 50;
      prewash.soap = 1;
      prewash.motorPhase1.timesExecuted =  1;
      prewash.motorPhase1.rotateClockwise = 1;
      prewash.motorPhase1.speed = 2; // regular
      prewash.motorPhase1.time = 60; //time in sec
      prewash.motorPhase2.timesExecuted = 1;
      prewash.motorPhase2.rotateClockwise = 0; // counterclockwise
      prewash.motorPhase2.speed = 2; // regular
      prewash.motorPhase2.time = 60; //time in sec

      mainwash1.takeWater = 100;
      mainwash1.heat = 100;
      mainwash1.soap = 2;
      mainwash1.motorPhase1.timesExecuted = 4;
      mainwash1.motorPhase1.rotateClockwise = 1;
      mainwash1.motorPhase1.speed = 2; // regular
      mainwash1.motorPhase1.time = 60; //time in sec
      mainwash1.motorPhase2.timesExecuted = 4;
      mainwash1.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash1.motorPhase2.speed = 2; // regular
      mainwash1.motorPhase2.time = 60; //time in sec

      mainwash2.takeWater = 50;
      mainwash2.heat = 0;
      mainwash2.soap = 0;
      mainwash2.motorPhase1.timesExecuted =  4;
      mainwash2.motorPhase1.rotateClockwise = 1;
      mainwash2.motorPhase1.speed = 2; // regular
      mainwash2.motorPhase1.time = 60; //time in sec
      mainwash2.motorPhase2.timesExecuted = 4;
      mainwash2.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash2.motorPhase2.speed = 2; // regular
      mainwash2.motorPhase2.time = 60; //time in sec
      break;
    default:
      break;
  }
  
  return Program();

}

bool WashingMachine::TempControl(int temp)
{
  if (GetTemperature() < temp)
  {
    hardware->SetHeater(true);
    return true;
  }
  else
  {
    hardware->SetHeater(false);
    return false;
  }
}

bool WashingMachine::Program()
{
  programRunning = true;
  // run all the functions in the right order.
  hardware->lockDoor(true);
  //PREWASH:
  //
  //Water pakken -> blocking tot juiste niveau
  hardware->closeSink();
  while (GetWaterlevel() < prewash.takeWater)
  {
    TempControl(prewash.heat); // alvast beginnen met opwarmen
    hardware->openDrain();
  }
  hardware->closeDrain();
  //Verwarmen -> blocking Koelt automatisch af wanneer niet aan
  while ((TempControl(prewash.heat)) == false)
  {
    TempControl(prewash.heat);
  }
  //Zeep toevoegen
  if (prewash.soap == 0)
  {
    hardware->setSoap1Led(false);
    hardware->setSoap2Led(false);
  }
  else if (prewash.soap == 1) {
    hardware->setSoap1Led(true);
  }
  else if (prewash.soap == 2) {
    hardware->setSoap2Led(true);
  }
  //Motor starten voor bepaalde tijd
  int i = 0;
  for (; i < prewash.motorPhase1.timesExecuted; i++)
  {
    hardware->SetDirection(prewash.motorPhase1.rotateClockwise);
    hardware->SetSpeed(prewash.motorPhase1.speed);
    /*
      clock_t start_time = clock();
      while((clock() - start_time) < (prewash.motorPhase1.time * 1000))
      {
    	tempControl(prewash.heat);
      }
    */
    int j = 0;
    for (; j < 60000; j++)
    {
      TempControl(prewash.heat);
    }
  }
  while (GetWaterlevel() != 0)
  {
    hardware->openSink();
  }

  //Water aflaten


  //MAINWASH:
  //
  //Water pakken -> blocking tot juiste niveau
  //Verwarmen -> blocking Koelt automatisch af wanneer niet aan
  //Zeep toevoegen
  //Motor starten voor bepaalde tijd
  //Motor starten andere kant voor bepaalde tijd
  //Herhaal motorcyclus X keer
  //Water aflaten
  //
  //Water pakken -> blocking tot juiste niveau
  //Verwarmen -> blocking Koelt automatisch af wanneer niet aan
  //Zeep toevoegen
  //Motor starten voor bepaalde tijd
  //Motor starten andere kant voor bepaalde tijd
  //Herhaal motorcyclus X keer
  //Water aflaten
  hardware->lockDoor(true);
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


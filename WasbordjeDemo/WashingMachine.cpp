#include "WashingMachine.h"




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
      hardware->setProgramLed(1);
      //zet variabele;
      prewash.takeWater = 2; // 50%
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
      //zet variabele;
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
      //zet variabele;
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
      mainwash1.motorPhase1.speed = 2; // regular
      mainwash1.motorPhase1.time = 60; //time in sec
      mainwash1.motorPhase2.timesExecuted = 4;
      mainwash1.motorPhase2.rotateClockwise = 0; // counterclockwise
      mainwash1.motorPhase2.speed = 2; // regular
      mainwash1.motorPhase2.time = 60; //time in sec

      mainwash2.takeWater = 2; // 50%
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

  programRunning = true;
  hardware->lockDoor(true);
  
  Program(prewash);
  
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

bool WashingMachine::MotorCyclus(int dir, int speed, int repeat)
{
  
}

bool WashingMachine::SetSoap(int soap)
{
  
}

bool WashingMachine::Program(wash &program)
{
  
  
  // run all the functions in the right order.
  
  //PREWASH:
  //
  //Water pakken -> blocking tot juiste niveau
  hardware->closeSink();
  Serial.println("Water pakken");
  hardware->openDrain();
  while (GetWaterlevel() < program.takeWater)
  {
    TempControl(program.heat); // alvast beginnen met opwarmen    
  }
  hardware->closeDrain();
  //Verwarmen -> blocking Koelt automatisch af wanneer niet aan
  Serial.println("Verwarmen");
  while ((TempControl(program.heat)) == false)
  {
    TempControl(program.heat);
  }
  Serial.println("Zeep pakken");
  //Zeep toevoegen
  switch(program.soap)
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
  }

  Serial.println("Motorcyclus");
  //Motor starten voor bepaalde tijd
  int i = 0;
  for (; i < program.motorPhase1.timesExecuted; i++)
  {
    hardware->SetDirection(program.motorPhase1.rotateClockwise);
    hardware->SetSpeed(program.motorPhase1.speed);
    /*
      clock_t start_time = clock();
      while((clock() - start_time) < (prewash.motorPhase1.time * 1000))
      {
    	tempControl(prewash.heat);
      }
    */
    int j = 0;
    for (; j < (program.motorPhase1.time * 10000); j++)
    {
      TempControl(program.heat);
    }
  }
  
  i = 0;
  for (; i < program.motorPhase1.timesExecuted; i++)
  {
    hardware->SetDirection(program.motorPhase2.rotateClockwise);
    hardware->SetSpeed(program.motorPhase2.speed);
    /*
      clock_t start_time = clock();
      while((clock() - start_time) < (prewash.motorPhase1.time * 1000))
      {
      tempControl(prewash.heat);
      }
    */
    int j = 0;
    for (; j < (program.motorPhase2.time * 10000); j++)
    {
      TempControl(program.heat);
    }
  }

  hardware->SetSpeed(0);

  Serial.println("Water aflaten");
  
  while (GetWaterlevel() != 0)
  {
    hardware->openSink();
  }
  hardware->closeSink();

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


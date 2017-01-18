#include "WashingMachine.h"


struct wash {
  int takeWater;
  int heat;
  int soap;
  motorPhase1 = new motorPhase();
  motorPhase2 = new motorPhase();
} ;


WashingMachine::WashingMachine(int drumSize)
  : Machine(drumSize)
  , temperature(0)
  , waterlevel(0)
{
    prewash  = new wash();
    mainwash1 = new wash();
    mainwash2 = new wash();
}

bool StartProgram(char program)
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
        mainwash2.motorPhase1.timesExecuted =  1;
        mainwash2.motorPhase1.rotateClockwise = 4;
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
    //start program();

}

bool Program()
{
  StartProgram = true;
  // run all the functions in the right order. 

}





int WashingMachine::getWaterlevel()
{
  waterlevel = hardware->getWaterLevel();
  return waterlevel;
}

int WashingMachine::getTemperature()
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


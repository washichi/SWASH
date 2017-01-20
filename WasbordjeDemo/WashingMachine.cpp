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
  , waterlevel(0)
{
}


    
bool WashingMachine::StartProgram(char program)
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
  return false;
  // run all the functions in the right order. 

  //PREWASH:
  //
  //Water pakken -> blocking tot juiste niveau
  closeSink();
  while(getWaterlevel() < prewash.takeWater)
  {
	openDrain();
  }
  closeDrain();
  //Verwarmen -> blocking Koelt automatisch af wanneer niet aan
  while(getTemperature() < prewash.heat)
  {
  	SetHeater(true);
  }
  SetHeater(false);
  //Zeep toevoegen
  if(prewash.soap == 0)
  {
  	setSoap1Led(false);
  	setSoap2Led(false)};
  }
  else if(prewash.soap == 1){setSoap1Led(true);}
  else if(prewash.soap == 2){setSoap2Led(true);}
  //Motor starten voor bepaalde tijd
  
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


#include "WashingMachine.h"

extern Centipede CS;

#define IN_W2           16
#define IN_W1           17
#define IN_T2           18
#define IN_T1           19

WashingMachine::WashingMachine(int drumSize)
  : Machine(drumSize)
  , temperature(0)
  , waterlevel(0)
{
  
}

int WashingMachine::getWaterlevel()
{
  waterlevel = (CS.digitalRead(IN_W2) << 1) | CS.digitalRead(IN_W1);
  return waterlevel;
}

int WashingMachine::getTemperature()
{
  temperature = (CS.digitalRead(IN_T2) << 1) | CS.digitalRead(IN_T1);
  return temperature;
}

void WashingMachine::TakeWater(int waterlevel)
{  
  if(waterlevel < 0)
  {
    //throw invalid_argument("Waterlevel has to be higher than 0");
  }
}

void WashingMachine::Sink()
{
  
}

void WashingMachine::Heat(int temperature)
{
  if(temperature < 0)
  {
    //throw invalid_argument("Temperature has to be greater than 0");
  }
}


#include "WashingMachine.h"



WashingMachine::WashingMachine(int drumSize)
  : Machine(drumSize)
  , temperature(0)
  , waterlevel(0)
{

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


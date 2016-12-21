#include "SteamMachine.h"

SteamMachine::SteamMachine(int drumSize)
  : Machine(drumSize)
  , temperature(0)
  , pressure(0)
{
  
}

SteamMachine::~SteamMachine()
{
  
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


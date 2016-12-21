#include "Dryer.h"

Dryer::Dryer(int drumSize)
  : Machine(drumSize)
  , temperature(0)
{
  
}

Dryer::~Dryer()
{
  
}

int Dryer::GetTemperature()
{
  return temperature;
}

void Dryer::TakeInAir()
{
  
}

void Dryer::Heat(int temperature)
{
  if(temperature < 0)
  {
    //throw invalid_argument("Temperature has to be greater than 0");
  }
}

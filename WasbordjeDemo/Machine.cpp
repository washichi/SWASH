#include "Machine.h"


Machine::Machine(int drumSize)
  : drumSize(drumSize)
  , turnedOn(false)
  , currentProgram('0')
  , programRunning(false)
{
  if(drumSize <= 0)
  {
    //throw invalid_argument("Drumsize has to be greater than 0");
  }
  hardware = new iHardwareControl();
  motor = new Motor();
}

Machine::~Machine()
{
  delete hardware;
  delete motor;
}

bool Machine::Start(char program)
{
  // geen implementatie
}

void Machine::Stop()
{
  // geen implementatie
}

char Machine::GetCurrentProgram()
{
  return currentProgram;
}

bool Machine::IsRunning()
{
  return programRunning;
}

void Machine::SafetyCheck()
{
  
}


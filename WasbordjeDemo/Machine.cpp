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
    return;
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
  // no implimentation, virtual
}

void Machine::Stop()
{
  // no implimentation, virtual
}

char Machine::GetCurrentProgram() const
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


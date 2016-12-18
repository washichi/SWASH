#include "Machine.h"

Centipede CS;

Machine::Machine(int drumSize)
  : drumSize(drumSize)
  , turnedOn(false)
  , currentProgram(0)
  , programRunning(false)
{
  if(drumSize <= 0)
  {
    //throw invalid_argument("Drumsize has to be greater than 0");
  }
}

Machine::~Machine()
{
  
}

void Machine::Start(int program)
{
  if(program < 0)
  {
    //throw invalid_argument("Program has to be greater than 0");
  }
  currentProgram = program;
  programRunning = true;
}

void Machine::Stop()
{
  programRunning = false;
}

int Machine::GetCurrentProgram()
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


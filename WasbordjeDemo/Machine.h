#ifndef MACHINE_H
#define MACHINE_H

#include "iHardwareControl.h"
#include "Motor.h"
#include "MachineType.h"
//#include "WashingMachine.h"

class Machine
{
  public:
    Machine(int drumSize);
    // post: File object is properly initialised
    // constructor needed with no parameters?
    virtual ~Machine();
    // destructor
    void Start(int program);
    // run een instantie van de juiste program class
    // dit programma moet aan deze machine gehangen worden .
    void Stop();
    // program stoppen, program "verwijderen"
    char GetCurrentProgram();
    // fase van program ophalen
    bool IsRunning();
    // waarom hebben we dit?
    // we kunnen toch gewoon kijken of er een instantie van program bestaat?
    // of is stop/start pauseren?
    void SafetyCheck();
    // motorphase struct?
    struct motorPhase
{
  int timesExecuted;
  int rotateClockwise;
  int speed;
  int time;
} ;

    iHardwareControl* hardware;

  protected:    
    Motor* motor;
    bool turnedOn;
    char currentProgram;
    bool programRunning;
    int drumSize;
};

#endif

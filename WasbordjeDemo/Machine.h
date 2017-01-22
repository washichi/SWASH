#ifndef MACHINE_H
#define MACHINE_H

#include "iHardwareControl.h"
#include "Motor.h"
#include "MachineType.h"
#include "MachineState.h"
#include "MachineCommunication.h"



class Machine
{
  public:
    Machine(int drumSize, MachineCommunication& com);
    // post: File object is properly initialised
    // constructor needed with no parameters?
    ~Machine();
    // destructor
    virtual bool Start(char program);
    // run een instantie van de juiste program class
    // dit programma moet aan deze machine gehangen worden .
    void Stop();
    // program stoppen, program "verwijderen"
    char GetCurrentProgram() const;
    // fase van program ophalen
    bool IsRunning();
    // waarom hebben we dit?
    // we kunnen toch gewoon kijken of er een instantie van program bestaat?
    // of is stop/start pauseren?
    void SafetyCheck();
    // motorphase struct?

    iHardwareControl* hardware;

  protected:    
    Motor* motor;
    bool turnedOn;
    char currentProgram;
    bool programRunning;
    int drumSize;
    MachineCommunication& machineCommunication;
};

#endif

#ifndef MACHINECONTROL_H
#define MACHINECONTROL_H

#include "iHardwareControl.h"
#include "Motor.h"
#include "Machine.h"
#include "MachineType.h"
#include "MachineState.h"
#include "MachineCommunication.h"



class MachineControl
{
  public:
    MachineControl(MachineCommunication& com, MachineType type);
    // post: File object is properly initialised
    // constructor needed with no parameters?
    ~MachineControl();
    bool machineInit();
    void CommandExecution(int command);
    // destructor

    //iHardwareControl* hardware;

  private:    
    MachineCommunication& machineCommunication;
    String machineID = "";
    char program = ' ';
    String programID = "";
    MachineState machinestate = stateUnknown;
    MachineType machinetype = typeUnknown;
};

#endif

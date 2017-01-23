#ifndef DRYER_H
#define DRYER_H

#include "Machine.h"

class Dryer: public Machine
{
  public:
    Dryer(int drumSize, MachineCommunication& com);
    virtual ~Dryer();
    int GetTemperature();
    bool Start(char program);

  private:
    struct motorPhase
    {
      int timesExecuted;
      int rotateClockwise;  //0 - 1
      int speed;            //0 - 3
      int time;
    } ;
    bool TempControl(int temp);
    int temperature;
    motorPhase dryerPhase1;
    motorPhase dryerPhase2;

    bool Program(motorPhase &program);
};

#endif

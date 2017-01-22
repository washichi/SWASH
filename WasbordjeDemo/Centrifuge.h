#ifndef CENTRIFUGE_H
#define CENTRIFUGE_H

#include "Machine.h"

class Centrifuge: public Machine
{
  public:
    Centrifuge(int drumSize, MachineCommunication& com);
    virtual ~Centrifuge();
    bool Start(char program);

  private:
    struct motorPhase
    {
      int timesExecuted;
      int rotateClockwise;  //0 - 1
      int speed;            //0 - 3
      int time;
    } ;

    motorPhase centrifugePhase1;
    motorPhase centrifugePhase2;

    bool Program(motorPhase &program);
};

#endif

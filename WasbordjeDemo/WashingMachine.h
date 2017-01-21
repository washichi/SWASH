#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "Machine.h"

class WashingMachine: public Machine
{
  public:
    WashingMachine(int drumSize);
    ~WashingMachine();
    bool Start(char program);
    int GetWaterlevel();
    int GetTemperature();

  private:
    struct motorPhase
    {
      int timesExecuted;
      int rotateClockwise;  //0 - 1
      int speed;            //0 - 3
      int time;
    } ;


    struct wash {
      int takeWater;          //0 - 3
      int heat;               //0 - 3
      int soap;               //0 - 1
      motorPhase motorPhase1;
      motorPhase motorPhase2;
    } ;

    wash prewash;
    wash mainwash1;
    wash mainwash2;
    
    int temperature;
    int waterlevel;
    bool TempControl(int temp);
    bool MotorCyclus(int dir, int speed, int repeat);
    bool SetSoap(int soap);
    bool Program(wash &program);
    void TakeWater(int waterlevel);
    void Sink();
    void Heat(int temperature);


};

#endif

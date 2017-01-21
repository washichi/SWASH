#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "iHardwareControl.h"

class Motor
{  
  public:
    Motor();
    virtual ~Motor();
    void Start(int speed, int direction);
    void Stop();
    String GetStatus() const;
    
  private:
    int speed;
    int direction;

};

#endif

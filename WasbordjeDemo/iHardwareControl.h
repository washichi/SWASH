#ifndef IHARDWARECONTROL_H
#define IHARDWARECONTROL_H

#include <Wire.h>
#include <Centipede.h>

extern Centipede CS; // create Centipede object

#define OUT_GROUP2      0
#define OUT_GROUP1      1
#define OUT_STROBE      2
#define OUT_KEYSELECT   3
#define OUT_BUZZER      4
#define OUT_HEATER      5
#define OUT_SPEED2      6
#define OUT_SPEED1      7
#define OUT_DATAC       8
#define OUT_DATAB       9
#define OUT_DATAA       10
#define OUT_MOTOR_RL    11
#define OUT_SOAP1       12
#define OUT_SINK        13
#define OUT_DRAIN       14
#define OUT_LOCK        15
#define IN_W2           16
#define IN_W1           17
#define IN_T2           18
#define IN_T1           19
#define IN_IN3          20
#define IN_IN2          21
#define IN_IN1          22
#define IN_IN0          23

class iHardwareControl
{
  public:
    iHardwareControl();
    void ResetHardware();

    //Motor control
    void SetDirection(int dir);
    void SetSpeed(int spd);

    //Water control
    int getWaterLevel();
    void openSink();
    void closeSink();
    void openDrain();
    void closeDrain();

    //Temperature control
    int getTemperature();
    void SetHeater(bool state);

    //Doorlock, program & soap LEDs
    void lockDoor(bool state);
    void setProgramLed(int program);
    void setSoap1Led(bool state);
    void setSoap2Led(bool state);

    //Buttons & switches
    boolean getDoorLockswitch();
    boolean getSoap1switch();
    boolean getSoap2switch();
    boolean getPressure();
    int getButtonPressed();

    //Coin LEDs
    void setCoin10Leds(int nrLeds);
    void setCoin50Leds(int nrLeds);
    void setCoin200Leds(int nrLeds);
    void SetCoinLeds(int coin, int nrLeds);

    void SetBuzzer(bool level);

  private:
    //Common functions
    void SetKeySelect(int value);
    void SetGroup(int group);
    void SetData(int data);
    void Strobe();

    boolean soap2LedOn;
    int currentNrCoin200Leds;
};

#endif

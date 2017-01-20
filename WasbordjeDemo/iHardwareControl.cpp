#include "iHardwareControl.h"

iHardwareControl::iHardwareControl()
{  
  ResetHardware();
}

void iHardwareControl::ResetHardware()
{
  Wire.begin(); // start I2C
  CS.initialize(); // set all registers to default
  for (int i = 0; i <= 15; i++)
  {
    CS.pinMode(i, OUTPUT);
  }
  SetGroup(0);
  Strobe();
  SetKeySelect(HIGH);
  CS.digitalWrite(OUT_BUZZER, HIGH);
  CS.digitalWrite(OUT_HEATER, HIGH);
  CS.digitalWrite(OUT_SPEED2, HIGH);
  CS.digitalWrite(OUT_SPEED1, HIGH);
  SetData(0);
  CS.digitalWrite(OUT_MOTOR_RL, LOW);
  CS.digitalWrite(OUT_SOAP1, LOW);
  CS.digitalWrite(OUT_SINK, LOW);
  CS.digitalWrite(OUT_DRAIN, LOW);
  CS.digitalWrite(OUT_LOCK, HIGH);
  soap2LedOn = false;
  currentNrCoin200Leds = 0;
}

/* 
 *  ##############################################################################
 *  MOTOR CONTROL
 *  ##############################################################################
 */
 
void iHardwareControl::SetDirection(int dir)
{
  if (dir == 0 || dir == 1)
  {
    CS.digitalWrite(OUT_MOTOR_RL, dir);
  }
  else
  {
    Serial.print("motor dir: niet ondersteund: ");
    Serial.println(dir);
  }
}

void iHardwareControl::SetSpeed(int spd)
{
  if (spd >= 0 && spd <= 3)
  {
    spd ^= 0x3;
    CS.digitalWrite(OUT_SPEED1, spd & 0x1);
    CS.digitalWrite(OUT_SPEED2, (spd >> 1) & 0x1);
  }
  else
  {
    Serial.print("SetSpeed: Niet ondersteunde snelheid: ");
    Serial.println(spd);
  }
}

/* 
 *  ##############################################################################
 *  WATER CONTROL
 *  ##############################################################################
 */
 
int iHardwareControl::getWaterLevel()
{
  return (CS.digitalRead(IN_W2) << 1) | CS.digitalRead(IN_W1);
}

void iHardwareControl::openSink()
{
  CS.digitalWrite(OUT_SINK, HIGH);
}

void iHardwareControl::closeSink()
{
  CS.digitalWrite(OUT_SINK, LOW);
}

void iHardwareControl::openDrain()
{
  CS.digitalWrite(OUT_DRAIN, HIGH);
}

void iHardwareControl::closeDrain()
{
  CS.digitalWrite(OUT_DRAIN, LOW);
}

/* 
 *  ##############################################################################
 *  TEMPERATURE CONTROL
 *  ##############################################################################
 */
 
int iHardwareControl::getTemperature()
{
  return (CS.digitalRead(IN_T2) << 1) | CS.digitalRead(IN_T1);
}

void iHardwareControl::SetHeater(bool state)
{
  CS.digitalWrite(OUT_HEATER, !state);
}

/* 
 *  ##############################################################################
 *  DOORLOCK, PROGRAM & SOAP LEDS
 *  ##############################################################################
 */
 
void iHardwareControl::lockDoor(bool state)
{
  if (state)
  {
    CS.digitalWrite(OUT_LOCK, HIGH);
  }
  else
  {
    CS.digitalWrite(OUT_LOCK, LOW);
  }
}

void iHardwareControl::setProgramLed(int program)
{
  if (program >= 0 && program <= 3)
  {
    const int ProgramGroup = 0x3;
    int programLedMask = 1 << (program - 1);
    SetGroup(ProgramGroup);
    SetData(programLedMask);
  }
  else
  {
    Serial.print("setProgramLed: niet ondersteund niveau: ");
    Serial.println(program);
  }
}

void iHardwareControl::setSoap1Led(bool state)
{
  if (state)
  {
    CS.digitalWrite(OUT_SOAP1, HIGH);
  }
  else
  {
    CS.digitalWrite(OUT_SOAP1, LOW);
  }
}

void iHardwareControl::setSoap2Led(bool state)
{
  const int Coin200Group = 0x1;
  int led200Mask = (1 << currentNrCoin200Leds) - 1;
  if (state)
  {
    led200Mask |= 0x4;
  }
  SetGroup(Coin200Group);
  SetData(led200Mask);
  soap2LedOn = state;
}

/* 
 *  ##############################################################################
 *  BUTTONS & SWITCHES
 *  ##############################################################################
 */

boolean iHardwareControl::getDoorLockswitch()
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN3) == HIGH;
}

boolean iHardwareControl::getSoap1switch()
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN1) == HIGH;
}

boolean iHardwareControl::getSoap2switch()
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN2) == HIGH;
}

boolean iHardwareControl::getPressure()
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN0) == HIGH;
}

int iHardwareControl::getButtonPressed()
{
  const unsigned char CodeStartBtn = 0x1;
  const unsigned char CodeCoin200Btn = 0x2;
  const unsigned char CodeCoin50Btn = 0x4;
  const unsigned char CodeCoin10Btn = 0x8;
  const unsigned char CodeProgramBtn = 0x9;
  const unsigned char CodeClearBtn = 0xE;

  SetKeySelect(HIGH);
  int in3 = CS.digitalRead(IN_IN3);
  int in2 = CS.digitalRead(IN_IN2);
  int in1 = CS.digitalRead(IN_IN1);
  int in0 = CS.digitalRead(IN_IN0);
  unsigned char btnCode = ((in3 & 0x1) << 3) | ((in2 & 0x1) << 2) | ((in1 & 0x1) << 1) | (in0 & 0x1);
  int button = -1;
  switch (btnCode)
  {
    case CodeStartBtn:   button = 1; break;
    case CodeCoin200Btn: button = 200; break;
    case CodeCoin50Btn:  button = 50; break;
    case CodeCoin10Btn:  button = 10; break;
    case CodeProgramBtn: button = 2; break;
    case CodeClearBtn:   button = 3; break;
    default: /* no button pressed */ break;
  }

  return button;
}

/* 
 *  ##############################################################################
 *  COIN LEDS
 *  ##############################################################################
 */

void iHardwareControl::setCoin10Leds(int nrLeds) //WORKING (op bovenste led na)
{
  const int Coin10Group = 0x0;
  SetCoinLeds(Coin10Group, nrLeds);
}

void iHardwareControl::setCoin50Leds(int nrLeds) //NOT WORKING (200 gaat aan + SOAP2)
{
  const int Coin50Group = 0x2;
  SetCoinLeds(Coin50Group, nrLeds);
}

void iHardwareControl::setCoin200Leds(int nrLeds) //NOT WORKING (50 gaat aan op bovenste na)
{
  const int Coin200Group = 0x1;
  if ((nrLeds >= 0) && (nrLeds <= 2))
  {
    int ledMask = (1 << nrLeds) - 1;
    if (soap2LedOn)
    {
      ledMask |= 0x4;
    }
    SetGroup(Coin200Group);
    SetData(ledMask);
    Strobe();
    currentNrCoin200Leds = nrLeds;
  }
  else
  {
    Serial.print("setCoin200Leds: niet ondersteund niveau: ");
    Serial.println(nrLeds);
  }
}

void iHardwareControl::SetCoinLeds(int coin, int nrLeds)
{
  if ((nrLeds >= 0) && (nrLeds <= 3))
  {
    SetGroup(coin);
    SetData((1 << nrLeds) - 1);
    Strobe();
  }
  else
  {
    Serial.print("setCoinLeds: niet ondersteund niveau: ");
    Serial.println(nrLeds);
  }
}

/* 
 *  ##############################################################################
 *  COMMON FUNCTIONS
 *  ##############################################################################
 */

void iHardwareControl::SetKeySelect(int value)
{
  const int KeySelect = 3;
  CS.digitalWrite(KeySelect, value);
}

void iHardwareControl::SetGroup(int group)
{
  const int Group2 = 0;
  const int Group1 = 1;
  CS.digitalWrite(Group1, group & 0x01);
  CS.digitalWrite(Group2, (group >> 1) & 0x01);
}

void iHardwareControl::SetData(int data)
{
  const int DataC = 8;
  const int DataB = 9;
  const int DataA = 10;
  CS.digitalWrite(DataA, data & 0x01);
  CS.digitalWrite(DataB, (data >> 1) & 0x01);
  CS.digitalWrite(DataC, (data >> 2) & 0x01);
}

void iHardwareControl::Strobe()
{
  const int Strobe = 2;
  CS.digitalWrite(Strobe, LOW);
  delay(80);
  CS.digitalWrite(Strobe, HIGH);
  delay(10);
  CS.digitalWrite(Strobe, LOW);
}

/* 
 *  ##############################################################################
 *  NOT WORKING
 *  ##############################################################################
 */

void iHardwareControl::SetBuzzer(bool level)
{
  CS.digitalWrite(OUT_BUZZER, !level);
  Serial.println("BUZZER");
}

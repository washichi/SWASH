#include <Wire.h>
#include <Centipede.h>

Centipede CS; // create Centipede object

boolean soap2LedOn;
int currentNrCoin200Leds;

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

void ResetHardware()
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
 
void SetDirection(int dir)
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

void SetSpeed(int spd)
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
 
int getWaterLevel()
{
  return (CS.digitalRead(IN_W2) << 1) | CS.digitalRead(IN_W1);
}

void openSink()
{
  CS.digitalWrite(OUT_SINK, HIGH);
}

void closeSink()
{
  CS.digitalWrite(OUT_SINK, LOW);
}

void openDrain()
{
  CS.digitalWrite(OUT_DRAIN, HIGH);
}

void closeDrain() //WORKING
{
  CS.digitalWrite(OUT_DRAIN, LOW);
}

/* 
 *  ##############################################################################
 *  TEMPERATURE CONTROL
 *  ##############################################################################
 */
 
int getTemperature()
{
  return (CS.digitalRead(IN_T2) << 1) | CS.digitalRead(IN_T1);
}

void SetHeater(bool state) //WORKING
{
  CS.digitalWrite(OUT_HEATER, !state);
}

/* 
 *  ##############################################################################
 *  DOORLOCK, PROGRAM & SOAP LEDS
 *  ##############################################################################
 */
 
void lockDoor(bool state)
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

void setProgramLed(int program)
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

void setSoap1Led(bool state) //WORKING
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

void setSoap2Led(bool state) //WORKING
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

boolean getDoorLockswitch() //WORKING
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN3) == HIGH;
}

boolean getSoap1switch() //WORKING
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN1) == HIGH;
}

boolean getSoap2switch() //WORKING
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN2) == HIGH;
}

boolean getPressure() //WORKING
{
  SetKeySelect(LOW);
  return CS.digitalRead(IN_IN0) == HIGH;
}

int getButtonPressed() //WORKING
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

void setCoin10Leds(int nrLeds) //WORKING (op bovenste led na)
{
  const int Coin10Group = 0x0;
  SetCoinLeds(Coin10Group, nrLeds);
}

void setCoin50Leds(int nrLeds) //NOT WORKING (200 gaat aan + SOAP2)
{
  const int Coin50Group = 0x2;
  SetCoinLeds(Coin50Group, nrLeds);
}

void setCoin200Leds(int nrLeds) //NOT WORKING (50 gaat aan op bovenste na)
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

void SetCoinLeds(int coin, int nrLeds)
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

void SetKeySelect(int value)
{
  const int KeySelect = 3;
  CS.digitalWrite(KeySelect, value);
}

void SetGroup(int group)
{
  const int Group2 = 0;
  const int Group1 = 1;
  CS.digitalWrite(Group1, group & 0x01);
  CS.digitalWrite(Group2, (group >> 1) & 0x01);
}

void SetData(int data)
{
  const int DataC = 8;
  const int DataB = 9;
  const int DataA = 10;
  CS.digitalWrite(DataA, data & 0x01);
  CS.digitalWrite(DataB, (data >> 1) & 0x01);
  CS.digitalWrite(DataC, (data >> 2) & 0x01);
}

void Strobe()
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

void SetBuzzer(bool level)
{
  CS.digitalWrite(OUT_BUZZER, !level);
  Serial.println("BUZZER");
}

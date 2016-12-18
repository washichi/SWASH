#include "Motor.h"

#include <Wire.h>
#include <Centipede.h>

extern Centipede CS;

#define OUT_SPEED2      6
#define OUT_SPEED1      7
#define OUT_MOTOR_RL    11

Motor::Motor()
  : speed(0)
  , direction(0)
{
  
}

Motor::~Motor()
{
  
}

void Motor::Start(int speed, int direction)
{
  if(speed < 0 && speed > 3)
  {
    Serial.print("Motor Start: Speed out of range: ");
    Serial.println(speed);
    return;
  }
  if(direction != 0 || direction != 1)
  {
    Serial.print("Motor Start: direction out of range: ");
    Serial.println(direction);
    return;
  }

  this->direction = direction;
  CS.digitalWrite(OUT_MOTOR_RL, this->direction);

  this->speed = speed;
  this->speed ^= 0x3;
  CS.digitalWrite(OUT_SPEED1, this->speed & 0x1);
  CS.digitalWrite(OUT_SPEED2, (this->speed >> 1) & 0x1);  
}

void Motor::Stop()
{
  Start(0, 0);
}

String Motor::GetStatus()
{
  String status = "Speed: " + speed; 
  status += ", direction: ";
  status += direction;
  
  return status;
}


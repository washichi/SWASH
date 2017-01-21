#include "Motor.h"

iHardwareControl* hardware;

Motor::Motor()
  : speed(0)
  , direction(0)
{
  hardware = new iHardwareControl();
}

Motor::~Motor()
{
  delete hardware;
}

void Motor::Start(int speed, int direction)
{
  if (speed < 0 && speed > 3)
  {
    Serial.print("Motor Start: Speed out of range: ");
    Serial.println(speed);
    return;
  }
  if (direction != 0 || direction != 1)
  {
    Serial.print("Motor Start: direction out of range: ");
    Serial.println(direction);
    return;
  }
  this->speed = speed;
  this->direction = direction;
  hardware->SetDirection(this->direction);
  hardware->SetSpeed(this->speed);
}

void Motor::Stop()
{
  this->speed = 0;
  this->direction = 0;
  hardware->SetDirection(this->direction);
  hardware->SetSpeed(this->speed);
}

String Motor::GetStatus() const
{
  String status = "Speed: " + speed;
  status += ", direction: ";
  status += direction;

  return status;
}


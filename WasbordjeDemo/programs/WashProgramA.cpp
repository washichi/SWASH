

#include "WashProgramA.h"

WashProgramA::WashProgramA()
{
  	//check money (360)

	//lock door
  	lockDoor(true);
  
	//prewash

	//– take water (fill 50%)
	openDrain();
  	while (getWaterLevel() != 2)
  	{
    	;//WAITING untill 50%
  	}
  	closeDrain();
	//no heating
	//add soap 1
	setSoap1Led(true);
	//rotate clockwise, regular speed, 1minute
	 SetDirection(0);
	 SetSpeed(1);
	 delay(60000); //WAIT for 1 minute
	//rotate counter clockwise, regular speed, 1 minute
	 SetSpeed(0); // STOP MOTOR
	 SetDirection(1);
	 SetSpeed(1);
	 delay(60000); //WAIT for 1 minute
	//sink (dirty) water
	  openSink();
	  while (getWaterLevel() != 0)
	  {
	    ;//WAITING
	  }
	  closeSink();
	//main wash

	//take water (fill 50%)
	openDrain();
  	while (getWaterLevel() != 2)
  	{
    	;//WAITING untill 50%
  	}
  	closeDrain();
	//heat (50%)
	CS.digitalWrite(OUT_HEATER, !state);
	while(getTemeprature() != 2)
	{
		;//WAITING
	}
	//add soap 2
	CS.digitalWrite(OUT_SOAP2, HIGH);	//wanneer moet deze weer uit?
	
	//repeat rotating 1 time
	for(int i = 0; i < 2; i++)			// voor motor kan ik gewoon motor aaanroepen.
	{
		//rotate clockwise, regular speed, 1 minute
		CS.digitalWrite(OUT_SPEED1, spd & 0x0);
		CS.digitalWrite(OUT_MOTOR_RL, dir);
		CS.digitalWrite(OUT_SPEED1, spd & 0x1);
		delay(60000);
		//rotate counterclockwise regular speed, 1 minute
		CS.digitalWrite(OUT_SPEED1, spd & 0x0);
		CS.digitalWrite(OUT_MOTOR_LR, dir);
		CS.digitalWrite(OUT_SPEED1, spd & 0x1);
		delay(60000);
	}

	
	//sink (dirty) water
	CS.digitalWrite(OUT_SINK, HIGH);
	while (getWaterLevel() != 0)
	 {
	    ;//WAITING
	 }
	CS.digitalWrite(OUT_SINK, LOW);
	//take water (fill 50%)
	openDrain();
  	while (getWaterLevel() != 2)
  	{
    	;//WAITING untill 50%
  	}
  	closeDrain();
	//no heating 
	//repeat rotating 1 time
	for(int i = 0; i < 2; i++)
	{
		//rotate clockwise, regular speed, 1 minute,
		Motor::Start(1, 1);
		delay(60000);
		Motor::Stop();
		//rotate counterclockwise regular speed, 1 minute,
		Motor::Start(1, 0);
		delay(60000);
		Motor::Stop();
	}

	//sink (dirty) water
	CS.digitalWrite(OUT_SINK, HIGH);
	while (getWaterLevel() != 0)
	 {
	    ;//WAITING
	 }
	CS.digitalWrite(OUT_SINK, LOW);


	//Centrifugation,
		// hebben we hier een aparte klasse voor? is dit in een wasmachine? waarom bestaat er dan een centrifuge? 
	//keep sinking the water, 
	//rotate clockwise, highest speed, 30 seconds,
	//rotate counterclockwise highest speed, 30 seconds, 
	//repeat rotating 1 times

	//Unlock
	return;
}

WashProgramA::~WashProgramA()
{
  
}


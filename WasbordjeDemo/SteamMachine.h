#ifndef STEAMMACHINE_H
#define STEAMMACHINE_H

#include "Machine.h"

class SteamMachine: public Machine
{	
	public:
		SteamMachine(int drumSize, MachineCommunication& com);
		virtual ~SteamMachine();
		int GetPressure();
		int getTemperature();
    bool Start(char program);


		
	private:
		int temperature;
		int pressure;
   bool TempControl(int temp);
		void ProduceSteam();
		void Heat(int temperature);
       struct motorPhase
    {
      int timesExecuted;
      int rotateClockwise;  //0 - 1
      int speed;            //0 - 3
      int time;
    } ;
    motorPhase steamPhase1;
    motorPhase steamPhase2;

    bool Program(motorPhase &program);
};

#endif

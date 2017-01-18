#include "MachineCommunication.h"

// te bepalen voor uploaden naar Arduino:
String machinetype = "washingmachine";
int whoami = NULL;
IPAddress ip(10, 0, 0, 45);
IPAddress server(10, 0, 0 , 15);
int port = 5001; // port 5001 is unused in TCP

MachineCommunication* machineCommunication;

bool Whoami()
{
	  switch (machinetype)
  {
    case "washingmachine":
    whoami = 001;
    break;

    case "dryer":
    whoami = 002;
    break;

    case "steamer":
    whoami = 003;
    break;

    case "centrifuge":
    whoami = 004;
    break;

    default:
    //machine not recognized.
    return false;
    break;
	}

	return true;
}

void setup()
{

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Connecting...");

  machineCommunication = new MachineCommunication(ip, server, port);

    // Initialize the ethernet device
    if (Ethernet.begin(mac) != 1)
    {
      Ethernet.begin(mac, ip);  //ip needed if the PC is the server (pc doesn't have dhcp to give the Arduino an IP)
    }
    Serial.println(Ethernet.localIP());

    // Connect to the server
    while (!client.connect(server, 5001))
    {
      Serial.println("connection failed");
    }
    Serial.println("connected");
	if(Whoami() == false)
	{
		// whoami not recognized
		Serial.println("WHOAMI not recognized");
		return;
	}
    machineCommunication->SendCommand("#"+ whoami + "$");
	Serial.println("WHOAMI sended");
 
}

void CheckCommand(int command)
{
  switch (command)
  {
    case 015:
    	//wasprogramma A
     	//hearbeat iets? : machineCommunication->SendCommand("#Door opened$");
      break;
    case 016:
		//wasprogramma B
      break;
    case 017:
    	//wasprogramma C	
      break;
    case 018:
    	//Dryprogram A	
      break;
    case 019:
    	//Dryprogram B
      break;
    case 020:
    	//Dryprogram C
      break; 
    case 021:
    	//Steamprogram A	
      break; 
    case 022:
    	//Steamprogram B
      break; 
    case 023:
    	//Steamprogram C
      break; 
    case 024:
    	//Centrifugeprogram A
      break; 
    case 025:
    	//Centrifugeprogram B
      break; 
    case 026:
    	//Centrifugeprogram C	
      break; 
    case 999:
    	//machinetest
      break;              
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}


void loop()
{
  int command = machineCommunication->ReceiveCommand();
  CheckCommand(command);

}


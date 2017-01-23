#include <stdio.h>
//#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include <libxml/xinclude.h>
#include <libxml/tree.h>
#include <string>
#include <vector>
#include <map>
#include "header.h"
#include "GarmentController.h"
#include "MachineController.h"

#include "header.h"

#define SERVER_PORT 5001
#define TRUE 1
#define FALSE 0
#define MAXLEN 550
#define MESSLEN 6

int i, len, msq_id, artCount, resource, on=1;
int listen_sd, max_sd, new_sd;
int desc_ready, end_server = FALSE;
int close_conn, FirstConnection, SecondConnection;
int ThirdConnection;
int j;

char buffer[MAXLEN];
//char message[MESSLEN];
char process;

struct sockaddr_in addr;
struct timeval timeout;

fd_set master_set, working_set;
pthread_t   threadID; 

MachineController* machineController;
GarmentController* garmentController;

void ConnectSockets(void);
void UpdateProcess(void);

void UpdateProcess()  
{
	printf("update status here");
	printf("again process is: ");
}

void ConnectSockets()
{
	listen_sd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (listen_sd < 0)
	{
		perror("socket() failed");
		exit(-1);
	}	
	resource = setsockopt(listen_sd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	
	if (resource < 0)
	{
		perror("setsockopt() failed");
		close(listen_sd);
		exit(-1);
	}
		
	resource = ioctl(listen_sd, FIONBIO, (char *)&on);
	
	if (resource < 0)
	{
		perror("ioctl() failed");
		close(listen_sd);
		exit(-1);
	}
		
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(SERVER_PORT);
	
	resource = bind(listen_sd, (struct sockaddr *)&addr, sizeof(addr));
	
	if (resource < 0)
	{
		perror("bind() failed");
		close(listen_sd);
		exit(-1);
	}
		
	resource = listen(listen_sd, 32);
	
	if (resource < 0)
	{
		perror("listen() failed");
		close(listen_sd);
		exit(-1);
	}
	
	FD_ZERO(&master_set);
	max_sd = listen_sd;
	FD_SET(listen_sd, &master_set);
	printf("Select can now listen");
	
    timeout.tv_sec = 3 * 60;
	timeout.tv_usec = 0;
}

int main (int argc, char *argv[])
{
	j = 0;
	machineController = new MachineController();
	garmentController = new GarmentController(machineController);
	ConnectSockets();
	
	if (pthread_detach (pthread_self ()) != 0)
    {
        perror ("pthread_detach(a)");
    }
    
    do
	{
		memcpy(&working_set, &master_set, sizeof(master_set));
		printf("waiting on select()...\n");
		resource = select(max_sd + 1, &working_set, NULL, NULL, &timeout);
				
		if (resource < 0)
		{
			perror(" select() failed");
			break;
		}
		if (resource == 0)
		{
			printf(" select() timed out. End program. \n");
			break;
		}
		desc_ready = resource;
		
		for (i=0; i <= max_sd && desc_ready > 0; ++i)
		{
			if (FD_ISSET(i, &working_set))
			{
				desc_ready -= 1;
				
				if (i == listen_sd)
				{
					do
					{
						new_sd = accept(listen_sd, NULL, NULL);
						
						if (new_sd < 0)
						{
							if (errno != EWOULDBLOCK)	
							{
								perror(" accept() failed");
								end_server = TRUE;
							}
							
							break;
						}
						printf(" New incoming connection - %d\n", new_sd);
						FD_SET(new_sd, &master_set);
						
						if (new_sd > max_sd)
						{
							max_sd = new_sd;
						}
					}
					while (new_sd != -1);
					
				}
				else
				{
					printf(" Descriptor %d is readable\n", i);
					printf("%i \n", i);
					
					if(FirstConnection < 1)
					{					
						FirstConnection = i;
					}
					if(FirstConnection > 1 && SecondConnection < 1)
					{
						SecondConnection = i;
					}
					if(FirstConnection > 1 && SecondConnection > 1 && ThirdConnection < 1)
					{
						ThirdConnection = i;
					}
					
					close_conn = FALSE;
					do
					{
						resource = recv(i, buffer, sizeof(buffer), 0);
						int stringi = sizeof(buffer);
						
						artCount = strlen(buffer);
						buffer[artCount] = '\0';
						
						if (resource < 0)
						{
							if (errno != EWOULDBLOCK)
							{
								perror(" recv() failed");
								close_conn = TRUE;
							}
							
							break;
						}
						if (resource == 0)
						{
							printf(" Connection closed\n");
							close_conn = TRUE;
							break;
						}
						
						len = resource;
						
						len = len - 2;
						
						printf("%s\n", buffer);
						printf(" %i bytes were received\n", len);
				
		
						if(strstr(buffer, "001") != NULL)
						{
							j++;
							printf("machine is a washer\n");
							char message[MESSLEN] = "#027$";
							printf("message send %s \n", message);	
							
							machineController->AddMachine("WAS", j);
							machineController->Test();
													
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						
						if(strstr(buffer, "002") != NULL)
						{
							j++;
							printf("machine is a dryer\n");
							char message[MESSLEN] = "#028$";
							printf("message send %s \n", message);		
							
							machineController->AddMachine("DRY", j);
							machineController->Test();
												
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						
						if(strstr(buffer, "003") != NULL)
						{
							j++;
							printf("machine is a steamer\n");
							char message[MESSLEN] = "#029$";
							printf("message send %s \n", message);	
							
							machineController->AddMachine("STE", j);
													
							resource = send(FirstConnection, message, len, 0);;
							break;
						}
						
						if(strstr(buffer, "004") != NULL)
						{
							j++;
							printf("machine is a centrifuge\n");
							char message[MESSLEN] = "#030$";
							printf("message send %s \n", message);	
							
							machineController->AddMachine("CEN", j);
													
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						if(strstr(buffer, "005") != NULL)
						{
							j++;
							printf("program is started\n");
							char message[MESSLEN] = "#005$";
							printf("message send %s \n", message);							
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						if(strstr(buffer, "032") != NULL)
						{
							printf("washer program is done \n");
							
							machineController->FinishMachine(1);
							int finished = garmentController->ProcessFinishedGarments();
							garmentController->Test();
							
							if(finished > 0)
							{
								char c = finished;
								//std::string test = "#066$" + c;
								char message[MESSLEN] = "ORDER";							
								resource = send(FirstConnection, message, len, 0);
							}
							
							break;
						}
							if(strstr(buffer, "035") != NULL)
						{
							printf("centrifuge program is done\n");
							
							machineController->FinishMachine(2);
							garmentController->ProcessFinishedGarments();
							garmentController->Test();
							
							char message[MESSLEN] = "#056$";
							printf("message send %s \n", message);		
													
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						if(strstr(buffer, "555") != NULL)
						{
							printf("Garment was send\n");
							FILE *fp;
							
							char jemoeder[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><garment><customerid>540</customerid><material>Linen</material><color>White</color><weight>20.250</weight><washer>1</washer><dryer>0</dryer><steamer>0</steamer><centrifuge>0</centrifuge><garmentsinorder>1</garmentsinorder></garment>";
							
							printf("%s\n", jemoeder);

							fp = fopen("final.xml", "w+");
							fputs(jemoeder, fp);
							fclose(fp);
							
												
							char inputfname[128] = "final.xml";							
							garmentController->AddGarment(inputfname);
							garmentController->ProcessGarments();
							garmentController->Test();
							break;
						}
							
						
						if (resource < 0)
						{
							perror(" send() failed");
							close_conn = TRUE;
							break;
						}
						
						break;
						
					}
					
					while (TRUE);
					if (close_conn)
					{
						close(i);
						FD_CLR(i, &master_set);
						
						if (i == max_sd)
						{
							while (FD_ISSET(max_sd, &master_set) == FALSE)
							{
								max_sd -= 1;
							}
						}
					}
				}
			}
		}
	}
	
	while (end_server == FALSE);
	
	for(i = 0; i <= max_sd; ++i)
	{
		if (FD_ISSET(i, &master_set))
		close(i);
	}
}

/* 
 * 
 * GEDACHTE: Maak 2 message queues, 1 voor clients->server en 1 voor server->clients, met 1 messagequeue moet je ook nog gaan wachten totdat de server de messagequeue geopent heeft en blabla, is gewoon makkelijker om die apart te houden
- 2 MessageQueues maken
- Server non-blocking laten luisteren en schrijven
- Zet XML van UI om in .xml bestand -> zet dan de filename op de messagequeue, zo leest mijn programma de .xml uit en dan hebben we meteen een logging systeem voor alle garments
- Ontvang berichten van clients en zet deze op de clients->server MQ
- Ontvang berichten van server->clients MQ en stuur deze naar de toebehorende verbinding
- Onderscheid maken tussen meerdere machines van hetzelfde type, de machines sturen alleen "ik ben wasmachine" dus wij moeten onderscheid gaan maken tussen meerdere machines.  MAAR HOE? GEEN IDEE
 * 
 * 
 * 
 * 
 * */


#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <mqueue.h>

#define SERVER_PORT 5001

#define TRUE 1
#define FALSE 0
#define ARRAYSIZE 60
#define MAXLEN 80
#define EXTRA 5
#define MAXINPUT MAXLEN+EXTRA+2
#define MSGSIZE 20

int i, len, resource, on=1;
int listen_sd, max_sd, new_sd;
int desc_ready, end_server = FALSE;
int close_conn;
	
char buffer[MAXLEN];
struct sockaddr_in addr;
struct timeval timeout;
struct machinePara;

fd_set master_set, working_set;
pthread_t   threadID; 

static void *ReadWriteToSockets(void * arg); 

void ConnectSockets(void);

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


main (int argc, char *argv[])
{
	ConnectSockets();	
	
	if(pthread_create(&threadID, NULL, ReadWriteToSockets, NULL ) != 0)
		{
			perror ("unable to create thread");
		}
	
	pthread_join(threadID, NULL);
	
	printf("IK BEN REINIER");
	
	while (end_server == FALSE);
	
	for(i = 0; i <= max_sd; ++i)
	{
		if (FD_ISSET(i, &master_set))
		close(i);
	}
}
	
	
static void *
ReadWriteToSockets (void * threadArgs)
{
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
					printf(" listening socket is readable\n");
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
					close_conn = FALSE;
					do
					{
						resource = recv(i, buffer, sizeof(buffer), 0);
						
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
						printf("  %s bytes were received\n", buffer);
						
						/*
						
						char *protocolString = memmem()
						
						if (buffer == )
						{						
							fgets(inputForm, len+1, stdin);
							char mq_name[MAXLEN] = "/_mq_mq_";
							mqd_t mq_fd = -1;
							mq_fd = mq_open (mq_name, O_WRONLY);
							mq_send (mq_fd, inputForm, sizeof(char)*MSGSIZE, 0);
						}
						*/

						char message[5] = "#015$";
						printf("message to send:%s\n", message);
						
						resource = send(i, message, 5, 0);

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
	while (TRUE);
	return(NULL);
}
	

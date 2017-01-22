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

#define SERVER_PORT 5001

#define TRUE 1
#define FALSE 0
#define to_quit FALSE

int i, len, resource, on=1;
int listen_sd, max_sd, new_sd;
int desc_ready, end_server = FALSE;
int close_conn;
	
char buffer[80];
char lastMessage[80];
char message[80];

struct sockaddr_in addr;
struct timeval timeout;
struct machinePara;

fd_set master_set, working_set;
pthread_t   threadID; 

static void *ReceiveMessage(void * arg);
static void *SendMessage(void * arg);
static void *WaitonSelect(void * arg);

void CreateSockets(void);
void startAllThreads(void);
void createMachineStruct(int);

main (int argc, char *argv[])
{
	printf("yes");
	CreateSockets();
	startAllThreads();
	printf("no");
}

void CreateSockets()
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
	
}

void createMachineStruct(int id)
{
}

void startAllThreads()
{	
	while (TRUE)
	{
    if(pthread_create(&threadID, NULL, ReceiveMessage, NULL) != 0)
	{
    	perror ("unable to create thread");
	}
	pthread_join(threadID, NULL);
}
	
}
	

static void *ReceiveMessage (void * threadArgs)
{
	if (pthread_detach (pthread_self ()) != 0)
    {
        perror ("pthread_detach(a)");
    }
    
    //printf("see me rolling, they hatin");
    //pthread_exit(NULL);

    return (NULL);
}

static void  *SendMessage (void * threadArgs)
{
	
}

static void *WaitonSelect(void * threadArgs)
{
	
}



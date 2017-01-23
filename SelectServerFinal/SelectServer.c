#include "header.h"

#define SERVER_PORT 5001
#define TRUE 1
#define FALSE 0
#define MAXLEN 80
#define MESSLEN 5

int i, len, msq_id, artCount, resource, on=1;
int listen_sd, max_sd, new_sd;
int desc_ready, end_server = FALSE;
int close_conn, FirstConnection, SecondConnection;
int ThirdConnection;

char buffer[MAXLEN];
//char message[MESSLEN];
char process;

struct sockaddr_in addr;
struct timeval timeout;

fd_set master_set, working_set;
pthread_t   threadID; 

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

main (int argc, char *argv[])
{
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
							printf("machine is a washer\n");
							char message[MESSLEN] = "#027$";
							printf("message send %s \n", message);							
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						
						if(strstr(buffer, "002") != NULL)
						{
							printf("machine is a dryer\n");
							char message[MESSLEN] = "#028$";
							printf("message send %s \n", message);							
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						
						if(strstr(buffer, "003") != NULL)
						{
							printf("machine is a steamer\n");
							char message[MESSLEN] = "#029$";
							printf("message send %s \n", message);							
							resource = send(FirstConnection, message, len, 0);;
							break;
						}
						
						if(strstr(buffer, "004") != NULL)
						{
							printf("machine is a centrifuge\n");
							char message[MESSLEN] = "#030$";
							printf("message send %s \n", message);							
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						if(strstr(buffer, "004") != NULL)
						{
							printf("program is started\n");
							char message[MESSLEN] = "#005$";
							printf("message send %s \n", message);							
							resource = send(FirstConnection, message, len, 0);
							break;
						}
						if(strstr(buffer, "555") != NULL)
						{
							printf("Garment was send\n");
							FILE *fp;
							char buff[255];

							fp = fopen("/home/student/Public/testt.xml", "w+");
							fputs(buffer, fp);
							fclose(fp);
												
							pid_t pid;
							double priority;
							double messagesize;
							msq_id = OpenMessageQueue();

								printf("File is being send\n");

								while(1)
								{
									char inputfname[128] = "testt.xml";							
									startClient(inputfname, 1);
									
									Mesg * writermsg = (Mesg *) malloc(sizeof(Mesg));
									Mesg * readermsg = (Mesg *) malloc(sizeof(Mesg));

									if (read_message(msq_id, 1, readermsg) >= 0)
									{
										if((pid = fork()) < 0)
										{
											fprintf(stderr, "pid = fork() error\n");
											exit(1);
										}

										if(pid == 0)
										{
											sscanf(readermsg->mesg_data, "%s %ld %lf", writermsg->mesg_data, &writermsg->mesg_type, &priority);
											messagesize = MAXMESSAGEDATA * (priority / 10) * 2;
											writermsg->mesg_type = readermsg->pid;											

											fp = fopen(writermsg->mesg_data, "r");
											if(fp != NULL)
											{
												writermsg->fileTransferCompleted = 0;
												while(fread(writermsg->mesg_data, sizeof(char), messagesize - 1, fp) > 0)
												{
													if((send_message(msq_id, writermsg)) == -1)
													{
														fprintf(stderr, "server send_message error: fread\n");
														exit(1);
													}
													memset(writermsg->mesg_data, 0, messagesize);
													usleep(350);
												}
												
												strcpy(writermsg->mesg_data, "File transfer completed.\n");
												writermsg->fileTransferCompleted = 1;

												send_message(msq_id, writermsg);
												memset(writermsg->mesg_data, 0, messagesize);
												
												printf("File transfer completed to pid[%ld] with priority %.0lf.\n\n", writermsg->mesg_type, priority);
												fclose(fp);
											}
											else
											{
												writermsg->fileTransferCompleted = 1;
												memset(writermsg, 0, MAXMESSAGEDATA);
												strcpy(writermsg->mesg_data, "fopen error: file does not exist.\n");

												if((send_message(msq_id, writermsg)) == -1)
												{
													fprintf(stderr, "server send_message error: fopen error\n");
													exit(1);
												}
												memset(writermsg, 0, MAXMESSAGEDATA);
											}
										}
									}
									free(writermsg);
									free(readermsg);
								}
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

int send_message( int msg_qid, Mesg *qbuf )
{
    int length, result;

    length = sizeof(Mesg) - sizeof(long);
    if ((result = msgsnd(msg_qid, qbuf, length, 0)) == -1)
    {
        return (-1);
    }
    return (result);
}


int read_message (int qid, long type, Mesg *qbuf )
{ 
    int result, length; 

    length = sizeof(Mesg) - sizeof(long);
    
    if ((result = msgrcv ( qid, qbuf, length, type, 0)) == -1) 
    { 
        return (-1); 
    } 
    return (result); 
}

int OpenMessageQueue()
{
    int msq_id;
    if ((msq_id = msgget (MESSAGEQUEUEKEY, IPC_CREAT|0660)) < 0)
    {
        fprintf(stderr, "client: msgget error\n");
        exit(1);
    }
    return msq_id;
}

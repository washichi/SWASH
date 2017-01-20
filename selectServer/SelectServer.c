#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 5001

#define TRUE 1
#define FALSE 0

main (int argc, char *argv[])
{
	int i, len, resource, on=1;
	int listen_sd, max_sd, new_sd;
	int desc_ready, end_server = FALSE;
	int close_conn;
	
	char buffer[80];
	
	struct sockaddr_in addr;
	struct timeval timeout;
	
	fd_set master_set, working_set;
	
	// create AF_INET stream socket to receive incoming connections
	// AF_INET is used to designate the type of addressess that your socket can communicate with
	// socket(int family, int type, int protocol);
	// socket() returns a token that represents local end of connection also known as a socket descriptor
	// socket(AF_INET, SOCK_STREAM, 0); --> 0 tells the socket to choose the correct protocol based on the socket type
	
	listen_sd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (listen_sd < 0)
	{
		perror("socket() failed");
		exit(-1);
	}
	
	// allow socket descriptor to be reuseable
	// setsockopt sets the socket options
	// setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
	// set the option specified by the option_name at protocol level specified by the level argument
	// SO_REUSEADDR specifies that the rules used in validating addresses supplied to bind() should allow reuse of local addresses.
	// this option takes a int value (vandaar on)
	
	resource = setsockopt(listen_sd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	
	if (resource < 0)
	{
		perror("setsockopt() failed");
		close(listen_sd);
		exit(-1);
	}
	
	// set socket to be nonblocking.
	// all sockets for incoming connection will be nonblocking because of inherit from the listening socket
	// ioctl manipulates underlying device parameters of special files
	// teminals may be controlled with ioctl() requests
	// int ioctl(open file descriptor, device-dependent requestcode, pointer to memory)
	
	// icoctl() maybe not the best method..... fcntl() is more standardized and available across platforms
	
	resource = ioctl(listen_sd, FIONBIO, (char *)&on);
	
	if (resource < 0)
	{
		perror("ioctl() failed");
		close(listen_sd);
		exit(-1);
	}
	
	// bind the socket
	// memset(pointer to block of memory, value to be set, number of bytes to set the value
	// htonl converts unsigned integer hostlong from host byte order to network byte order
	// htons converts a u_short from hosts to TCP/IP network byte order
	
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
	
	// set the listen back log
	
	resource = listen(listen_sd, 32);
	
	if (resource < 0)
	{
		perror("listen() failed");
		close(listen_sd);
		exit(-1);
	}
	
	//initialize the master fd_set
	
	FD_ZERO(&master_set);
	max_sd = listen_sd;
	FD_SET(listen_sd, &master_set);
	
	// initialize the timeval struct to 3 minutes. If no activiy after 3 minutes this program will end.
	
	timeout.tv_sec = 3 * 60;
	timeout.tv_usec = 0;
	
	// Loop waiting for incoming connects or for incoming data on any of the connected sockets
	
	do
	{
		// copy master fd_set to working fd_set
		
		memcpy(&working_set, &master_set, sizeof(master_set));
		
		// call select() and wait 5 minutes to complete
		
		printf("waiting on select()...\n");
		resource = select(max_sd + 1, &working_set, NULL, NULL, &timeout);
		
		// check to see if the select call failed
				
		if (resource < 0)
		{
			perror(" select() failed");
			break;
		}
		
		// check to see if the 5 minute time out expired
		
		if (resource == 0)
		{
			printf(" select() timed out. End program. \n");
			break;
		}
		
		//one or more descriptors are readable. Determine wich ones they are
		
		desc_ready = resource;
		
		for (i=0; i <= max_sd && desc_ready > 0; ++i)
		{
			//check if descriptor is ready
			
			if (FD_ISSET(i, &working_set))
			{
				//descriptor was found that is readable, one less has to be looked for
				
				desc_ready -= 1;
				
				if (i == listen_sd)
				{
					printf(" listening socket is readable\n");
					
					//accept all incoming connectons that are queued up
					
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
						
						// add new incoming connection to the master read set
						
						printf(" New incoming connection - %d\n", new_sd);
						FD_SET(new_sd, &master_set);
						
						if (new_sd > max_sd)
						{
							max_sd = new_sd;
						}
					}
					
					//loop back up and accept another incoming connection.
					
					while (new_sd != -1);
					
				}
				
				// existing connection must be readable
				
				else
				{
					printf(" Descriptor %d is readable\n", i);
					close_conn = FALSE;
					
					//receive all incoming data on this socket
					
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
						
						//check to see if connection has been closed
						
						if (resource == 0)
						{
							printf(" Connection closed\n");
							close_conn = TRUE;
							break;
						}
						
						// data was received send bytes back
						
						len = resource;
						printf(" %d bytes received: \n", len);
						
						// echo data back to client
						
						resource = send(i, buffer, len, 0);
						
						if (resource < 0)
						{
							perror(" send() failed");
							close_conn = TRUE;
							break;
						}
						
					}
					
					while (TRUE);
					
					// if close_conn flag was turned on then the active connection needs to be cleaned up
					// remove descriptor from master set
					
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
	
	//clean up the sockets that are open
	
	for(i = 0; i <= max_sd; ++i)
	{
		if (FD_ISSET(i, &master_set))
		close(i);
	}
}
	
	


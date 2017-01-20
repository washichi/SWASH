#include "Communication.h"
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>
#include "errno.h"

int socketfd;
struct sockaddr_in serveraddr;
//   struct hostent *server;

char buffer[1024];
int portno = 5001; //poortnummer afspreken voor server

Communication::Communication()
{


    //TCP connection implementation
    //What type of data comes in?

    //Create the socket
    //ZET IETS IN BUFFER


}


bool Communication::Connect()
{
    int socketfd;//, portno;
    struct sockaddr_in serveraddr;
 //   struct hostent *server;

    //std::memset ((char *) &serveraddr, 0, sizeof(serveraddr));
    std::memset (buffer, '0', sizeof(buffer));

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd < 0)
    {
        std::cout << "error opening socket\n";
        return false;
    }
    //server = gethostbyname(//??);



    serveraddr.sin_family = AF_INET;

    serveraddr.sin_port = htons(portno);

    serveraddr.sin_addr.s_addr = inet_addr("10.0.0.15");


    //create connection with the server
    if(connect(socketfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        std::cout << "error connecting\n";
        std::cout << strerror(errno);
        return false;
    }
    else
    {
        std::cout << "Connected";
        return true;
    }
}

bool Communication::Write()
{
    char buffer[] = "1234";

    if(write(socketfd, buffer, strlen(buffer)) < 0)
    {
            std::cout << "error writing to socket\n";
            return false;
    }
    std::memset (buffer, '0', sizeof(buffer));
    return true;
}

bool Communication::WriteFirst()
{
    int n = 0;
    char buffer[] = "1234";
    n = write(socketfd, buffer, strlen(buffer));
    if(n<0)
    {
            std::cout << "error writing to socket\n";
            return false;
    }
    std::memset (buffer, '0', sizeof(buffer));
    return true;
}

void Communication::Read()
{
    int n = 0;
    n = read(socketfd, buffer, 255/*MaxSize*/);
    if(n < 0)
    {
            std::cout << "Error reading from socket\n";
    }
    else
    {
        std::cout << n;
    }
}

void Communication::Close()
{
    close(socketfd);
}

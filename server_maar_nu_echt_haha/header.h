#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/msg.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <mqueue.h>
#include <stdio.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAXMESSAGEDATA (4096-16) /* don't want sizeof(Mesg) > 4096 */
#define MESGHDRSIZE (sizeof(Mesg) - MAXMESSAGEDATA)
#define MESSAGEQUEUEKEY 1

typedef struct
{
    long    mesg_type; /* message type */
    char    mesg_data [MAXMESSAGEDATA];
    int     mesg_len; /* #bytes in mesg_data */
    int     fileTransferCompleted;
    pid_t   pid;
} Mesg;

// Client Prototypes
void startClient(char*);


#endif

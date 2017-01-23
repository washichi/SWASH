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

pthread_t clientThreadId;

// Client Prototypes
void startClient(char*);
void *client_thread(void * id);
void exit_message();
int OpenMessageQueue();

// Server Prototypes
void startServer();
void catch_int(int signo);
void catch_cleanup(int signo);

// Read/Write Prototypes
void mqstat_print (key_t mkey, int mqid, struct msqid_ds *mstat);
int read_message (int qid, long type, Mesg *qbuf );
int send_message( int msg_qid, Mesg *qbuf ) ;

#endif

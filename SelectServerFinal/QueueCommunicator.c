#include "header.h"

void startClient(char* inputfname, int priority)
{
    int msq_id;
    pid_t pid = getpid();

    pthread_t clientThreadId;

    printf("QueueCommunicator started\n");

    msq_id = OpenMessageQueue();

    Mesg *msg = (Mesg*) malloc(sizeof(Mesg));
    msg->mesg_type = 1;
    sprintf(msg->mesg_data, "%s %d %d", inputfname, pid, priority);
    msg->mesg_len = strlen(msg->mesg_data);
    msg->fileTransferCompleted = 0;
    msg->pid = pid;

    if ((send_message(msq_id, msg)) == -1)
    {
        fprintf(stderr, "client: send_message error\n");
        exit(1);
    }
    printf("QueueCommunicator is nearly done\n");

    pthread_create(&clientThreadId, NULL, client_thread, (void *)&msq_id);
    pthread_join(clientThreadId, NULL);
    
    
    free(msg);
    printf("QueueCommunicator is done\n");
}

void *client_thread(void * id)
{
    int msq_id = *(int*)id;
    pid_t pid = getpid();

    Mesg *readermsg = (Mesg*) malloc(sizeof(Mesg));
    printf("%d\n", readermsg->fileTransferCompleted);
    while(1)
    {
        if(readermsg->fileTransferCompleted == 1)
        {
            break;
        }
        
        read_message(msq_id, pid, readermsg);
        printf("%s", readermsg->mesg_data);

    }
    free(readermsg);

    return NULL;
}

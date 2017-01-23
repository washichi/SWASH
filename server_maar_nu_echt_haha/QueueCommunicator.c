#include "header.h"

void startClient(char* inputfname)
{
    int msq_id;
    pid_t pid = getpid();

    clientThreadId;

    printf("QueueCommunicator started\n");

    msq_id = OpenMessageQueue();

    printf("QueueCommunicator is nearly done\n");

    //pthread_create(&clientThreadId, NULL, client_thread, (void *)&msq_id);
    //pthread_join(clientThreadId, NULL);
    
    
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

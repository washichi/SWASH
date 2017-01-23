CC=gcc
FLAGS=-W -Wall
LFLAGS=-pthread -lrt
OUTPUTFILENAME=BESTSERVERALIVE

main: SelectServer.o	QueueCommunicator.o
	$(CC) $(LFLAGS) SelectServer.o QueueCommunicator.o -o $(OUTPUTFILENAME)

clean:
	rm -f *.o core.* $(OUTPUTFILENAME)

QueueCommunicator.o: QueueCommunicator.c
	$(CC) $(FLAGS) -c QueueCommunicator.c

SelectServer.o: SelectServer.c
	$(CC) $(FLAGS) -c SelectServer.c

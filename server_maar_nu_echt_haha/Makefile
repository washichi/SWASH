CC=g++
CFLAGS=-pedantic -O3 -Icode -c -I/usr/local/include/libxml2
LDFLAGS=-lpthread -lrt -lxml2 -L/usr/local/lib
SOURCES=main.cpp IMachine.cpp MachineFactory.cpp Wasmachine.cpp Dryer.cpp Steamer.cpp Centrifuge.cpp GarmentController.cpp Garment.cpp MachineController.cpp QueueCommunicator.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=washserver

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

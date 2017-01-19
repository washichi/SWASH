CC=g++
CFLAGS=-Wall -Werror -pedantic -O3 -Icode -c -I/usr/local/include/libxml2
LDFLAGS=-lpthread -lxml2 -L/usr/local/lib
SOURCES=main.cpp Garment.cpp CustomerController.cpp Customer.cpp MachineController.cpp Machine.cpp WashprogramController.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=washserver

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

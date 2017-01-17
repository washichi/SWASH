CC=g++
CFLAGS=-Wall -Werror -pedantic -O3 -Icode -c -I/usr/local/include/libxml2
LDFLAGS=-lpthread -lxml2 -L/usr/local/lib
SOURCES=main.cpp Garment.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=xmlparser

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

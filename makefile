CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=HTable.h MechPart.cpp TreeHashTableDemo.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=assignment3

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core

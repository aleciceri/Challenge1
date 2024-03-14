CC = g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -Wall -I. -I../../../Examples/pacs-examples/Examples/include
LDFLAGS ?= -L../../../Examples/pacs-examples/Examples/lib
LIBS ?=-lmuparser

SOURCES = main.cpp functions.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $< $(LIBS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CC) -c $(CPPFLAGS) $(CXXFLAGS) $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

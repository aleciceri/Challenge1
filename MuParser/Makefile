CC = g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -Wall -I. -I../../../Examples/pacs-examples/Examples/include
LDFLAGS ?= -L../../../Examples/pacs-examples/Examples/lib
LIBS ?= -lmuparser

SOURCES = main.cpp functions.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main
HEADERS = functions.hpp

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(LIBS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

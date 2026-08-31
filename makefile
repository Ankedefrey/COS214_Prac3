# Makefile for EventFlow - COS214 Prac 3
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = task2
SOURCES = CompositeTest.cpp \
          EventComponent.cpp \
          EventGroup.cpp \
          EventControl.cpp \
          RaceEvent.cpp \
          RaceZone.cpp \
          CourseSector.cpp \
          StartGate.cpp \
          TimingPoint.cpp \
          MedicalTent.cpp \
          AidStation.cpp \
          MarshalTeam.cpp \
          Notice.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
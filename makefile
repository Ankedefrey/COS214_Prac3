# Makefile for EventFlow - COS214 Prac 3
#Running "make" builds the executable "eventflow"

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = eventflow

OBJECTS = EventComponent.o EventGroup.o EventControl.o RaceEvent.o RaceZone.o CourseSector.o StartGate.o TimingPoint.o MedicalTent.o AidStation.o MarshalTeam.o Notice.o main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

EventComponent.o: EventComponent.cpp EventComponent.h
	$(CXX) $(CXXFLAGS) -c EventComponent.cpp

EventGroup.o: EventGroup.cpp EventGroup.h
	$(CXX) $(CXXFLAGS) -c EventGroup.cpp

EventControl.o: EventControl.cpp EventControl.h
	$(CXX) $(CXXFLAGS) -c EventControl.cpp

RaceEvent.o: RaceEvent.cpp RaceEvent.h
	$(CXX) $(CXXFLAGS) -c RaceEvent.cpp

RaceZone.o: RaceZone.cpp RaceZone.h
	$(CXX) $(CXXFLAGS) -c RaceZone.cpp

CourseSector.o: CourseSector.cpp CourseSector.h
	$(CXX) $(CXXFLAGS) -c CourseSector.cpp

StartGate.o: StartGate.cpp StartGate.h
	$(CXX) $(CXXFLAGS) -c StartGate.cpp

TimingPoint.o: TimingPoint.cpp TimingPoint.h
	$(CXX) $(CXXFLAGS) -c TimingPoint.cpp

MedicalTent.o: MedicalTent.cpp MedicalTent.h
	$(CXX) $(CXXFLAGS) -c MedicalTent.cpp

AidStation.o: AidStation.cpp AidStation.h
	$(CXX) $(CXXFLAGS) -c AidStation.cpp

MarshalTeam.o: MarshalTeam.cpp MarshalTeam.h
	$(CXX) $(CXXFLAGS) -c MarshalTeam.cpp

Notice.o: Notice.cpp Notice.h
	$(CXX) $(CXXFLAGS) -c Notice.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
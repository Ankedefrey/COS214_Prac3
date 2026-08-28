#include "TimingPoint.h"

#include "Notice.h"

#include <iostream>
#include <stdexcept>

TimingPoint::TimingPoint(const std::string& name,
                         int number,
                         int cutoff,
                         int capacity)
    : EventComponent(name, capacity),
      checkpointNumber(number),
      cutoffTime(cutoff),
      isRecording(false),
      backupMode(false) {
}

void TimingPoint::open() {
    throw "Not yet implemented";
}

void TimingPoint::close() {
    throw "Not yet implemented";
}

void TimingPoint::reportStatus() const {
    throw "Not yet implemented";
}

int TimingPoint::getCapacity() const {
    throw "Not yet implemented";
}

int TimingPoint::getCurrentLoad() const {
    throw "Not yet implemented";
}

void TimingPoint::update(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

bool TimingPoint::recordRunner(int runnerNumber, int arrivalTime) {
    (void) runnerNumber;
    (void) arrivalTime;
    throw "Not yet implemented";
}

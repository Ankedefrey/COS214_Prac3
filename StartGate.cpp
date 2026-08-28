#include "StartGate.h"

#include "Notice.h"

#include <iostream>
#include <stdexcept>

StartGate::StartGate(const std::string& name, int batchSize)
    : EventComponent(name, batchSize),
      batchSize(batchSize),
      isOpenForStart(false) {
}

void StartGate::open() {
    throw "Not yet implemented";
}

void StartGate::close() {
    throw "Not yet implemented";
}

void StartGate::reportStatus() const {
    throw "Not yet implemented";
}

int StartGate::getCapacity() const {
    throw "Not yet implemented";
}

int StartGate::getCurrentLoad() const {
    throw "Not yet implemented";
}

void StartGate::update(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

bool StartGate::admitRunners(int count) {
    (void) count;
    throw "Not yet implemented";
}

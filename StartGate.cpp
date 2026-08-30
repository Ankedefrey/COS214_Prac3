#include "StartGate.h"

#include "Notice.h"

#include <iostream>

StartGate::StartGate(const std::string& name, int batchSize)
    : EventComponent(name, batchSize),
    batchSize(batchSize),
    isOpenForStart(false) {
}

/**
 * @brief Opens the gate and permits controlled runner starts.
 */
void StartGate::open() {
    openState = true;
    isOpenForStart = true;
}

/**
 * @brief Closes the gate and prevents new runner starts.
 */
void StartGate::close() {
    openState = false;
    isOpenForStart = false;
    currentLoad = 0;
}

void StartGate::reportStatus() const {
    throw "Not yet implemented";
}
/**
 * @brief Returns the maximum allowed batch size
 * @return maximum rumner of runners allowed in ons batch
 */
int StartGate::getCapacity() const {
    return batchSize;
}

/**
 * @brief Returns the number of runners in the current batch
 * @return maximum current runner load
 */
int StartGate::getCurrentLoad() const {
    return currentLoad;
}

void StartGate::update(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

bool StartGate::admitRunners(int count) {
    (void) count;
    throw "Not yet implemented";
}

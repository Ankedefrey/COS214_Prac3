#include "AidStation.h"

#include "Notice.h"

#include <iostream>
#include <stdexcept>

AidStation::AidStation(const std::string& name,
                       int capacity,
                       int stock,
                       int threshold)
    : EventComponent(name, capacity),
      stockLevel(stock),
      lowStockThreshold(threshold),
      isServing(false) {
}

void AidStation::open() {
    throw "Not yet implemented";
}

void AidStation::close() {
    throw "Not yet implemented";
}

void AidStation::reportStatus() const {
    throw "Not yet implemented";
}

int AidStation::getCapacity() const {
    throw "Not yet implemented";
}

int AidStation::getCurrentLoad() const {
    throw "Not yet implemented";
}

void AidStation::update(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

void AidStation::serveRunner(int unitsUsed) {
    (void) unitsUsed;
    throw "Not yet implemented";
}

bool AidStation::isStockLow() const {
    throw "Not yet implemented";
}

void AidStation::restock(int amount) {
    (void) amount;
    throw "Not yet implemented";
}

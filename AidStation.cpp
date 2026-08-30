#include "AidStation.h"

#include "Notice.h"

#include <iostream>

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
    switch(notice.getType()){
        //secure supplies but continue assisting runners
            //suppliesSecured = true
            //isServing = true
        case WEATHER_ALERT:
        case PAUSE:
        case SECTOR_CLOSED:
        case RESUME:
        case OPEN:
        case EVACUATE:
        default:
            break;
    }
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

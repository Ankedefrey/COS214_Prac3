#include "MedicalTent.h"

#include "Notice.h"

#include <iostream>

MedicalTent::MedicalTent(const std::string& name, int beds)
    : EventComponent(name, beds),
      bedsAvailable(beds),
      isActive(false) {
}

void MedicalTent::open() {
    throw "Not yet implemented";
}

void MedicalTent::close() {
    throw "Not yet implemented";
}

void MedicalTent::reportStatus() const {
    throw "Not yet implemented";
}

int MedicalTent::getCapacity() const {
    throw "Not yet implemented";
}

int MedicalTent::getCurrentLoad() const {
    throw "Not yet implemented";
}

void MedicalTent::update(const Notice& notice) {
    switch(notice.getType()){
        //remains open and increases readiness
            //emergencyReady = true
            //isActive = true
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

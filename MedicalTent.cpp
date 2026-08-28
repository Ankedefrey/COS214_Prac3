#include "MedicalTent.h"

#include "Notice.h"

#include <iostream>
#include <stdexcept>

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
    (void) notice;
    throw "Not yet implemented";
}

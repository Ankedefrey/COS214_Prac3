#include "MarshalTeam.h"

#include "Notice.h"

#include <iostream>
#include <stdexcept>

MarshalTeam::MarshalTeam(const std::string& name, int size)
    : EventComponent(name, size),
      teamSize(size),
      isDeployed(false) {
}

void MarshalTeam::open() {
    throw "Not yet implemented";
}

void MarshalTeam::close() {
    throw "Not yet implemented";
}

void MarshalTeam::reportStatus() const {
    throw "Not yet implemented";
}

int MarshalTeam::getCapacity() const {
    throw "Not yet implemented";
}

int MarshalTeam::getCurrentLoad() const {
    throw "Not yet implemented";
}

void MarshalTeam::update(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

Notice MarshalTeam::createHazardNotice(const std::string& message,
                                       int severity) {
    throw "Not yet implemented";
}

void MarshalTeam::redeploy() {
    throw "Not yet implemented";
}

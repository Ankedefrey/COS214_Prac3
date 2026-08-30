#include "MarshalTeam.h"

#include "Notice.h"

#include <iostream>

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
    switch(notice.getType()){
        //Redirects runners around the danger
            //redirectRunners = true
            //isDeployed = true
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

Notice MarshalTeam::createHazardNotice(const std::string& message,
                                       int severity) {
    throw "Not yet implemented";
}

void MarshalTeam::redeploy() {
    throw "Not yet implemented";
}

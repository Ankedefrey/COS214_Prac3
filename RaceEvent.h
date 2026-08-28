#ifndef RACEEVENT_H
#define RACEEVENT_H

#include "EventGroup.h"

#include <string>

class RaceEvent : public EventGroup {
public:
    explicit RaceEvent(const std::string& name);
};

#endif

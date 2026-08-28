#ifndef RACEZONE_H
#define RACEZONE_H

#include "EventGroup.h"

#include <string>

class RaceZone : public EventGroup {
public:
    explicit RaceZone(const std::string& name);
};

#endif

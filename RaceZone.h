#ifndef RACEZONE_H
#define RACEZONE_H

#include "EventGroup.h"

#include <string>

/**
 * @brief Concrete Composite: a large area of the event that groups one or more course sectors and/or
 * directly-owned units such as a shared medical tent.
 */

class RaceZone : public EventGroup {
public:
    explicit RaceZone(const std::string& name);
};

#endif

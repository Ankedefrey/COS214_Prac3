#ifndef RACEEVENT_H
#define RACEEVENT_H

#include "EventGroup.h"

#include <string>

/**
 * @brief Concrete Composite: the root of the whole event tree.
 *
 * A RaceEvent is an EventGroup with no behaviour of its own beyond what EventGroup already provides,
 * it exists as a distinct type so the root of the tree is self-documenting in code and in the ownership diagram.
 */

class RaceEvent : public EventGroup {
public:
    explicit RaceEvent(const std::string& name);
};

#endif

/**
 * @brief Concrete Composite: the root of the whole event tree.
 *
 * A RaceEvent is an EventGroup with no behaviour of its own beyond what EventGroup already provides,
 * it exists as a distinct type so the root of the tree is self-documenting in code and in the ownership diagram.
 */

#include "RaceEvent.h"

/// @brief Constructs the root event with the given name.
RaceEvent::RaceEvent(const std::string& name)
    : EventGroup(name) {
}

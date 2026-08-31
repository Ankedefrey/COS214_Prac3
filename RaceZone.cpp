/**
 * @brief Concrete Composite: a large area of the event that groups one or more course sectors and/or
 * directly-owned units such as a shared medical tent.
 * @author Anke de Frey
 */
#include "RaceZone.h"

/// @brief Constructs a zone with the given name.
RaceZone::RaceZone(const std::string& name)
    : EventGroup(name) {
}

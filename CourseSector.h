#ifndef COURSESECTOR_H
#define COURSESECTOR_H

#include "EventGroup.h"
#include "TerrainType.h"

#include <string>

/**
 * @brief Concrete Composite: a sector of the course with a specific
 *        terrain type, grouping the leaf units that operate within it
 */

class CourseSector : public EventGroup {
private:
    TerrainType terrainType;

public:
    CourseSector(const std::string& name, TerrainType terrainType);

    TerrainType getTerrainType() const;
};

#endif

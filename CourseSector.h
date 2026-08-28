#ifndef COURSESECTOR_H
#define COURSESECTOR_H

#include "EventGroup.h"
#include "TerrainType.h"

#include <string>

class CourseSector : public EventGroup {
private:
    TerrainType terrainType;

public:
    CourseSector(const std::string& name, TerrainType terrainType);

    TerrainType getTerrainType() const;
};

#endif

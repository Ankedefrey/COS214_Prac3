#include "CourseSector.h"

CourseSector::CourseSector(const std::string& name,
                           TerrainType terrainType)
    : EventGroup(name),
      terrainType(terrainType) {
}

TerrainType CourseSector::getTerrainType() const {
    return terrainType;
}

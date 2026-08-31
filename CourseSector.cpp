/**
 * @brief Concrete Composite: a sector of the course with a specific
 *        terrain type, grouping the leaf units that operate within it
 * @author Anke de Frey
 */
#include "CourseSector.h"

/**
     * @brief Constructs a course sector.
     * @param name Human-readable identifier.
     * @param terrainType The kind of terrain this sector covers.
     */
CourseSector::CourseSector(const std::string& name, TerrainType terrainType)
    : EventGroup(name), terrainType(terrainType) {
}

/// @return The terrain type of this sector.
TerrainType CourseSector::getTerrainType() const {
    return terrainType;
}

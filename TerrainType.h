#ifndef TERRAINTYPE_H
#define TERRAINTYPE_H

/**
 * @brief The kind of ground a CourseSector covers.
 * Exposed via CourseSector::getTerrainType(), available for event rules
 * that should differ by terrain.
 */
enum TerrainType {
    GRAVEL,
    FOREST,
    TAR
};

#endif

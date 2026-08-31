/**
 * @file main.cpp
 * @brief Builds the EventFlow ownership tree, wires the Observer cascade on top of it and runs a demonstration:
 * Composite construction, Observer registration, three-plus notification types, a notification cascading through a three-plus runtime levels,
 * a registration change, a runtime reorganisation that updates both ownership and observer registration,
 * composite traversal and a clean exit.
 *
 * Nesting:
 * Level 1: RaceEvent (Root)
 * Level 2: RaceZones (startFinishZone, courseZone)
 * Level 3: CourseSectors (tarStartSector, forestSector, gravelSector)
 * Level 4: Leaf units (StartGate, TimingPoint, MedicalTent, AidStation, MarshalTeam)
 *
 * @author Anke de Frey
 */

#include "EventControl.h"
#include "RaceEvent.h"
#include "RaceZone.h"
#include "CourseSector.h"
#include "StartGate.h"
#include "TimingPoint.h"
#include "MedicalTent.h"
#include "AidStation.h"
#include "MarshalTeam.h"
#include "TerrainType.h"
#include "NoticeType.h"
#include "Notice.h"

#include <iostream>

int main(){
    EventControl control; // Create the EventControl that owns the root
    
    // COMPOSITE CONSTRUCTION

    //BUILDING THE EVENT TREE
    //Level 1: The Root Race Event
    RaceEvent* race = new RaceEvent("Mixed Terrain Race 2026");
    
    //Level 2: Race Zones
    RaceZone* startFinishZone = new RaceZone("Start-Finish Zone");
    RaceZone* courseZone = new RaceZone("Course Zone");
    
    //Level 3: Course Sectors
    CourseSector* tarStartSector = new CourseSector("Tar Start Sector", TAR);
    CourseSector* forestSector = new CourseSector("Forest Sector", FOREST);
    CourseSector* gravelSector = new CourseSector("Gravel Sector", GRAVEL);
    
    //Level 4: Leaf Units
    // Tar Start Sector units
    StartGate* startGate = new StartGate("Main Start Gate", 50);
    TimingPoint* startTiming = new TimingPoint("Start Timing Point", 1, 1800, 100);
    
    //Start-Finish Zone units (directly attached, not in a sector)
    MedicalTent* mainMedical = new MedicalTent("Main Medical Tent", 20);
    
    //Forest Sector units
    AidStation* forestAid = new AidStation("Forest Aid Station", 30, 100, 20);
    MarshalTeam* forestMarshal = new MarshalTeam("Forest Marshal Team", 5);
    
    //Gravel Sector units
    AidStation* gravelAid = new AidStation("Gravel Aid Station", 25, 80, 15);
    TimingPoint* gravelTiming = new TimingPoint("Gravel Timing Point", 2, 3600, 80);
    MarshalTeam* gravelMarshal = new MarshalTeam("Gravel Marshal Team", 4);
    
    //Build the Ownership Tree
    // Level 1 -> Level 2: Race owns Zones
    race->addChild(startFinishZone);
    race->addChild(courseZone);
    
    // Level 2 -> Level 3: Zones own Sectors
    startFinishZone->addChild(tarStartSector);
    // mainMedical is directly under startFinishZone (also level 3)
    startFinishZone->addChild(mainMedical);
    
    courseZone->addChild(forestSector);
    courseZone->addChild(gravelSector);
    
    // Level 3 -> Level 4: Sectors own Leaf units
    tarStartSector->addChild(startGate);
    tarStartSector->addChild(startTiming);
    
    forestSector->addChild(forestAid);
    forestSector->addChild(forestMarshal);
    
    gravelSector->addChild(gravelAid);
    gravelSector->addChild(gravelTiming);
    gravelSector->addChild(gravelMarshal);
    
    //Set the root in EventControl
    control.setRaceRoot(race);

    //OBSERVER REGISTRATION - wire the notification cascade
    //eventControl to raceZone to CourseSector to leaf

    control.attach(startFinishZone);
    control.attach(courseZone);

    startFinishZone->attach(tarStartSector);
    startFinishZone->attach(mainMedical);
    courseZone->attach(gravelSector);

    tarStartSector->attach(startGate);
    tarStartSector->attach(startTiming);
    forestSector->attach(forestAid);
    forestSector->attach(forestMarshal);
    gravelSector->attach(gravelAid);
    gravelSector->attach(gravelTiming);
    gravelSector->attach(gravelMarshal);




}
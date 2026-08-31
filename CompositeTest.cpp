/**
 * @file main.cpp
 * @brief Demonstrating a sample event with at least three levels of nesting for Task 2. 
 * @author Jezelle Govender
 * 
 * The nesting I have created it as follows: 
 * Level 1: RaceEvent (Root)
 * Level 2: RaceZones (startFinishZone, courseZone)
 * Level 3: CourseSectors (tarStartSector, forestSector, gravelSector)
 * Level 4: Leaf units (StartGate, TimingPoint, MedicalTent, AidStation, MarshalTeam)
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

#include <iostream>
#include <memory>

int main() {
    EventControl control; // Create the EventControl that owns the root
    
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
    
    //Build the Ownership Tree now
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
    
    std::cout << "  EVENT STRUCTURE WAS BUILT SUCCESSFULLY  " << std::endl;
    std::cout << std::endl;
  

    std::cout << "DEMONSTRATING THE COMPOSITE PATTERN:" << std::endl;
    
    // 1. Report status of the entire event (recursive traversal)
    std::cout << "\n1. Reporting status of entire race:" << std::endl;
    std::cout << std::endl;
    control.getRaceRoot()->reportStatus();
    
    // 2. Open the entire event- recursive open
    std::cout << "\n2. Opening the entire race:" << std::endl;
    std::cout << std::endl;
    control.getRaceRoot()->open();
    
    std::cout << "\n3. Total Event Capacity:" << std::endl;
    std::cout << std::endl;
    int totalCapacity = control.getRaceRoot()->getCapacity();
    std::cout << "Total race capacity: " << totalCapacity << std::endl;
    
    std::cout << "\n4. Total Event Current Load:" << std::endl;
    int totalLoad = control.getRaceRoot()->getCurrentLoad();
    std::cout << "Total race load: " << totalLoad << std::endl;
    
    // 5. Demonstrate specific leaf operations
    std::cout << "\n5. Demonstrating Leaf Operations:" << std::endl;
    
    // Admit runners through start gate
    std::cout << "\n  Admitting runners through start gate:" << std::endl;
    startGate->admitRunners(25);
    startGate->admitRunners(30); // This should trigger the capacity alert
    
    // Serve runners at aid stations
    std::cout << "\n  Serving runners at forest aid station:" << std::endl;
    forestAid->serveRunner(5);
    forestAid->serveRunner(3);
    
    // Record runners at timing points
    std::cout << "\n  Recording runners at timing points:" << std::endl;
    startTiming->recordRunner(101, 1200);
    startTiming->recordRunner(102, 1900); // Should trigger cutoff alert
    
    // 6. Test Composite traversal - get capacity of a specific sector
    std::cout << "\n6. Sector-specific Operations:" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Gravel sector capacity: " << gravelSector->getCapacity() << std::endl;
    std::cout << "Forest sector capacity: " << forestSector->getCapacity() << std::endl;
    std::cout << "Tar start sector capacity: " << tarStartSector->getCapacity() << std::endl;
    

    std::cout << "  DEMONSTRATION IS COMPLETE  " << std::endl;
    std::cout << "\nThe EventGroup destructor will now clean up all owned children..." << std::endl;
    
    return 0;
}
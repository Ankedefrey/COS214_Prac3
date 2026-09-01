# COS214_Prac3
# EventFlow - Mixed Terrain Race 2026

## Team Members
- Jezelle Govender u25176383
- Anke de Frey u24611400
- Kayla Falconer u25006747

## Event Concept
EventFlow coordinates the Mixed Terrain Race 2026, a single-day running event across tar, forest and gravel terrain. It provides a live view of operational areas and distributes notices about capacity, weather, hazards, evacuations and missed cutoffs without needing to know each unit’s concrete type.

The race contains a Start-Fisnish Zone, holding the Tar Start Sector and Main Medical tent, and a Course Zone, holding the Forest and Gravel Sectors. This creates the hierarchy:
RaceEvent -> RaceZone -> CourseSector -> event units
EventControl owns the tree's root and introduces notices that cascade through registered zones, sectors and units.

## Building and Running
```
make
./eventflow
make clean  # removes all object files and the executable
```
## Doxygen

```
doxygen Doxyfile
```
This produces a 'docs/html' directory
- open 'docs/html/index.html' in a browser to view the generated documentation.

## Architecture Overview
 
EventFlow is built on two collaborating GoF design patterns.

## Composite Pattern:
The Composite pattern models the event as a part-whole tree: EventComponent is the abstract Component, EventGroup is the Composite (RaceEvent, RaceZone, CourseSector), and five concrete Leaf classes carry out the actual work at the bottom of the tree. Every leaf reacts differently to the same operations and notices — each has a genuinely distinct role and internal state:
 
- **StartGate** — Controls the start of the race and admits runners in batches. Pauses admissions during weather alerts.
- **TimingPoint** — Records runner passages and checkpoint times, enforcing a cutoff. Switches to backup mode rather than stopping outright during weather/safety alerts.
- **MedicalTent** — Provides emergency medical services. Deliberately remains active during evacuations and weather alerts, when other units are pausing or closing.
- **AidStation** — Feeds and hydrates runners; tracks its own stock levels and serving load, and monitors for low supply.
- **MarshalTeam** — Handles safety and crowd control on the course; manages hazards and can itself report one.

## Observer Pattern:
The Observer pattern lets the event's control structures push notices (weather alerts, capacity warnings, evacuations, etc.) down through the tree without any Subject ever needing to know the concrete type of what it's talking to.

- Subject (Subject) — abstract interface for observers to attach/detach, and for a subject to issue notices to them.
- Observer (Observer) — abstract interface for anything that reacts to a notice.
- ConcreteSubject (EventControl) — creates and issues notices to its registered observers.
- ConcreteSubject (EventGroup) — forwards notices it receives to all of its own registered observers (its children).
- ConcreteObserver (RaceEvent) — represents the whole race, owned by EventControl, receives notices from it and forwards them to its RaceZones.
- ConcreteObserver (RaceZone) — represents a major operational area, receives notices from RaceEvent and forwards them to its CourseSectors.
- ConcreteObserver (CourseSector) — represents a specific terrain zone, receives notices from RaceZone and forwards them to its leaf observers.
- ConcreteObserver (StartGate) — manages runner admissions, reacts to notices.
- ConcreteObserver (MedicalTent) — provides and prepares medical services during emergencies.
- ConcreteObserver (MarshalTeam) — provides safety and route management, responds to hazards.
- ConcreteObserver (AidStation) — serves runners with hydration/nutrition, monitors its own stock levels.
- ConcreteObserver (TimingPoint) — records runner passages and checks cutoff times.

EventGroup plays both ConcreteSubject and ConcreteObserver at once — it is told about a notice from its own parent (Observer role) and separately forwards that notice to its own children (Subject role), via two independent lists (children for ownership, observers for notification).

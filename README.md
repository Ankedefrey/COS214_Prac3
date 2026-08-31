# COS214_Prac3

## Team Members
- Jezelle Govender u25176383
- Anke de Frey u24611400
- Kayla Falconer u25006747

## Composite Pattern (Jezelle):
Leaves- each have meaningfully different output/behaviour:

AidStation- Feeds and hydrates runners. It states are stock levels and serving. 
MarsahlTeam- Safety and crowd control, it manages hazards.
MedicalTent - Emergency medical services. Remains active during emergencies.
StartGate - Controls the race starts. Pauses during weather alerts. 
TimingPoint - Records runner times. Switches to backup mode.

## Observer Pattern (Kayla):
Subject: Subject - provides the interface for observers to attach/detach/receive notices from the concrete subjects

Observer: Observer - defines the interface for objects observe a subject

ConcreteSubject: EventControl and EventGroup
- EventControl: Creates and issues notices to its registered observer (RaceEvent)
- EventGroup: Forwards notices to all registered observers (children)
  
ConcreteObserver: RaceEvent, RaceZone, CourseSector, StartGate, MedicalTent, MarshalTeam, AidStation, TimingPoint
- RaceEvent: Represents the whole race - owned by EventControl and receives notices from EventControl and forwards them to RaceZone
- RaceZone: Represents major operational areas - receives notices from RaceEvent and forwards them to CourseSector
- CourseSector: Represents specific terrain zones of the race - receives notices from RaceZone and forwards them to leaf observers (StartGate, MedicalTent, MarshalTeam, AidStation, TimingPoint)
- StartGate: Controls the start of the race. Manages runner admissions and reacts to notices
- MedicalTent: Provides and prepares services for medical emergencies during the race
- MarshalTeam: Provides safety and route management by directing runners. Responds to hazards
- AidStation: Serves runner by providing hydration and nutrition to the runners. Monitor stock levels
- TimingPoint: Records runner passages and checks cutoff times

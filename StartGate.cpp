#include "StartGate.h"

#include "Notice.h"

#include <iostream>

StartGate::StartGate(const std::string& name, int batchSize)
    : EventComponent(name, batchSize),
    batchSize(batchSize),
    isOpenForStart(false) {
}

/**
 * @brief Opens the gate and permits controlled runner starts.
 */
void StartGate::open() {
    openState = true;
    isOpenForStart = true;
}

/**
 * @brief Closes the gate and prevents new runner starts.
 */
void StartGate::close() {
    openState = false;
    isOpenForStart = false;
    currentLoad = 0;
}

void StartGate::reportStatus() const {
    throw "Not yet implemented";
}
/**
 * @brief Returns the maximum allowed batch size
 * @return maximum rumner of runners allowed in ons batch
 */
int StartGate::getCapacity() const {
    return batchSize;
}

/**
 * @brief Returns the number of runners in the current batch
 * @return maximum current runner load
 */
int StartGate::getCurrentLoad() const {
    return currentLoad;
}

/**
 * @brief Updates medical readiness in response to a pushed notice
 * @param notice Notice pushed by the Subject
 */
void StartGate::update(const Notice& notice) {
    switch(notice.getType()){
        //pauses new starts
            //isOpenForStart = false
        case WEATHER_ALERT:
        case PAUSE:
        case SECTOR_CLOSED:
            isOpenForStart = false;
            break;
        case RESUME:
            if(openState){
                isOpenForStart = true;
            }
            break;
        case OPEN:
            open();
            break;
        case CLOSE:
        case EVACUATE:
            close();
            break;
        default:
            break;
    }
}

//4.3
/**
 * @brief Want to admit runner to a batch but checks if back too full or no one to join or not open to start.
 * @param count Number of runners requesting access/admission
 * @return true if complete batch was admitted, otherwise false.
 */
bool StartGate::admitRunners(int count) {
    //conditional capacity rule
    //no one to start or NOTOpen or bigger than batch
    if(!isOpenForStart || count < 0 || currentLoad + count > batchSize){
        return false;
    }
    //increment the count
    currentLoad += count;
    return true;
}

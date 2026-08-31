/**
 * @file TimingPoint.cpp
 * @brief Implementation of TimingPoint that records runners times and monitors the cutoff times.
 * @author Jezelle Govender
 */
#include "TimingPoint.h"
#include "Notice.h"

#include <iostream>
#include <stdexcept>

TimingPoint::TimingPoint(const std::string& name, int number, int cutoff, int capacity)
    : EventComponent(name, capacity),
    checkpointNumber(number),
    cutoffTime(cutoff),
    isRecording(false),
    backupMode(false) {
}

/**
 * @brief opens the timing point and starts recording
 */
void TimingPoint::open() {
    if(!openState) {
    openState = true;
    isRecording = true;
    std::cout << "Timing Point: " << name << " opened and recording." << std::endl;
    }
}

/**
 * @brief closes the timing point and stops recording
 */
void TimingPoint::close() {
    if(openState) {
    openState = false;
    isRecording = false;
    std::cout << "Timing Point: " << name << " has closed and stopped recording." << std::endl;
    }
}

/**
 * @brief Reports the current status of the timing point
 */
void TimingPoint::reportStatus() const {
    std::cout << "Timing Point: " << name << " Status:" << std::endl;
    std::cout << "  State: " << (openState ? "OPEN" : "CLOSED") << std::endl;
    std::cout << "  Recording: " << (isRecording ? "YES" : "NO") << std::endl;
    std::cout << "  Backup Mode: " << (backupMode ? "YES" : "NO") << std::endl;
    std::cout << "  Checkpoint Number: " << checkpointNumber << std::endl;
    std::cout << "  Cutoff Time: " << cutoffTime << std::endl;
    std::cout << "  Runners Recorded: " << currentLoad << std::endl;
}

int TimingPoint::getCapacity() const {
    return capacity;
}

int TimingPoint::getCurrentLoad() const {
    return currentLoad;
}

/**
 * @brief handles event notifications that affect the timepoint, it switches to backup mode during emergencies.
 * @param notice the notice being processed
 */
void TimingPoint::update(const Notice& notice) {
    switch (notice.getType()) {
        case WEATHER_ALERT:
            std::cout << "Timing Point: " << name << " is switching to backup mode while continuing recording." << std::endl;
            if (isRecording) {
                backupMode = true;
                std::cout << "  Primary equipment protected. Operating in backup mode." << std::endl;
            }
            break;
            
        case PAUSE:
            std::cout << "Timing Point: " << name << " pausing recording but maintaining data." << std::endl;
            isRecording = false;
            break;
            
        case RESUME:
            std::cout << "Timing Point: " << name << " is resuming recording." << std::endl;
            if (openState) {
                isRecording = true;
            }
            break;
            
        case CUTOFF_ALERT:
            std::cout << "Timing Point: " << name << " received cutoff alert." << std::endl;
            if (currentLoad > 0) {
                std::cout << "  " << currentLoad << " runners recorded before cutoff." << std::endl;
            }
            break;
            
        case EVACUATE:
            std::cout << "Timing Point: " << name << " maintaining backup records during evacuation." << std::endl;
            backupMode = true;
            break;
        
        case ROUTE_CHANGE:
            std::cout << "Timing Point: " << name << " relocating to match the new route." << std::endl;
            break;

        case HAZARD_ALERT:
            std::cout << "Timing Point: " << name << " continuing to record from a safe distance." << std::endl;
            backupMode = true;
            break;
            
        default:
            std::cout << "Timing Point: " << name << " received notice: " << notice.getMessage() << std::endl;
            break;
    }
}


/**
 * @brief Records a runner's arrival time at the timing point if within cutoff, else issue an alert
 * @param runnerNumber A unique identifier of the runner
 * @param arrivalTime The time the runner arrived at this checkpoint
 * @return true if the runner was recorded, or false if they missed the cutoff.
 */
bool TimingPoint::recordRunner(int runnerNumber, int arrivalTime) {
    if (!isRecording) {
        std::cout << "Timing Point: " << name << " not recording - cannot record runner "  << runnerNumber << std::endl;
        return false;
    }
    
    if (arrivalTime <= cutoffTime) { // Check if the arrival is within cutoff time
        currentLoad++; // Record normally
        std::cout << "Timing Point: " << name << " recorded runner " << runnerNumber << " at time " << arrivalTime << " (within cutoff of " << cutoffTime << ")" << std::endl;
        return true;
    } else {
        // Runner missed cutoff - so issue a CUTOFF_ALERT
        std::cout << "Timing Point: " << name << " CUTOFF_ALERT: Runner " << runnerNumber << " arrived at " << arrivalTime << " (cutoff was " << cutoffTime << ")" << std::endl;
        return false;
    }
}

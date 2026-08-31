/**
 * @file StartGate.cpp
 * @brief Implementation of StartGate that manages the start of the race and runners admissions
 * @author Jezelle Govender
 */
#include "StartGate.h"
#include "Notice.h"

#include <iostream>
#include <stdexcept>

StartGate::StartGate(const std::string& name, int batchSize)
    : EventComponent(name, batchSize),
      batchSize(batchSize),
      isOpenForStart(false) {
}

/**
 * @brief Opens the start gate, and lets  runners start the race
 */
void StartGate::open() {
    if (!openState) {
        openState = true;
        isOpenForStart = true;
        std::cout << "Start Gate: " << name << " has opened. Runners may now start." << std::endl;
    }
}

/**
 * @brief Closes the start gate
 */
void StartGate::close() {
    if (openState) {
        openState = false;
        isOpenForStart = false;
        std::cout << "Start Gate: " << name << " has closed. No new starts are allowed." << std::endl;
    }
}

/**
 * @brief Reports the current status of the start gate
 */
void StartGate::reportStatus() const {
    std::cout << "Start Gate: " << name << " Status:" << std::endl;
    std::cout << "  State: " << (openState ? "OPEN" : "CLOSED") << std::endl;
    std::cout << "  Open for Start: " << (isOpenForStart ? "YES" : "NO") << std::endl;
    std::cout << "  Batch Size: " << batchSize << std::endl;
    std::cout << "  Runners Started: " << currentLoad << std::endl;
    std::cout << "  Capacity: " << capacity << std::endl;
}

int StartGate::getCapacity() const {
    return capacity;
}

int StartGate::getCurrentLoad() const {
    return currentLoad;
}

/**
 * @brief Handles the event notifications, the startgate pauses the start during weather alerts and emergencies
 * @param notice the notice being processed
 */
void StartGate::update(const Notice& notice) {
    switch (notice.getType()) {
        case WEATHER_ALERT:
            std::cout << "Start Gate: " << name << " received weather alert. Pausing starts."
                      << std::endl;
            if (notice.getSeverity() > 1) {
                std::cout << "  High severity weather - gate is closed for starts." << std::endl;
                isOpenForStart = false;
            } else {
                std::cout << "  Low severity weather - monitoring the conditions." << std::endl;
                isOpenForStart = false; // Pause as a safety precaution
            }
            break;
            
        case PAUSE:
            std::cout << "Start Gate: " << name << " is pausing starts." << std::endl;
            isOpenForStart = false;
            break;
            
        case RESUME:
            std::cout << "Start Gate '" << name << "is now resuming starts." << std::endl;
            if (openState) {
                isOpenForStart = true;
            }
            break;
            
        case EVACUATE:
            std::cout << "Start Gate: " << name << " is closed during evacuation." << std::endl;
            isOpenForStart = false;
            break;
            
        case CAPACITY_ALERT:
            std::cout << "Start Gate: " << name << " has received a capacity alert." << std::endl;
            if (currentLoad >= capacity) {
                std::cout << "  Warning: Gate at maximum capacity." << std::endl;
            }
            break;
            
        default:
            std::cout << "Start Gate: " << name << " received notice: " << notice.getMessage() << std::endl;
            break;
    }
}

/**
 * @brief Admits a group of runners through the start gate, with a condition-based decision
 * @param count the number of runners to admit
 * @return true if runners are admitted, false if capacity would be exceeded, or if the gate is closed
 */
bool StartGate::admitRunners(int count) {
    if (!isOpenForStart || count < 0 || (currentLoad + count) > batchSize) {
       
        if ((currentLoad + count) > batchSize) {  //if capacity is exceeded
            std::cout << "Start Gate: " << name << " CAPACITY_ALERT: Cannot admit " << count << " runners (current load: " << currentLoad << ", batch size: " << batchSize << ")" << std::endl;
            
            // Optional fragment check: If severity is high, prepare medical tent or deploy marshals
            if ((currentLoad + count) > batchSize * 2) { // Severity level 2 condition
                std::cout << "  High severity capacity issue - recommended: prepare medical tent or deploy marshals." << std::endl;
            }
        }
        return false;
    }
    
    // if the admission succeeds
    currentLoad += count;
    std::cout << "Start Gate: " << name << " admitted " << count << " runners. Total started: " << currentLoad << std::endl;
    return true;
}

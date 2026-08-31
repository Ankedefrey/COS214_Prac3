/**
 * @file MedicalTent.cpp
 * @brief Implementation of the MedicalTent that provides emergency medical services in the race.
 * @author Jezelle Govender
 */
#include "MedicalTent.h"
#include "Notice.h"

#include <iostream>
#include <stdexcept>

MedicalTent::MedicalTent(const std::string& name, int beds)
    : EventComponent(name, beds),
      bedsAvailable(beds),
      isActive(false) {
}

void MedicalTent::open() {
    if (!openState) {
        openState = true;
        isActive = true;
        std::cout << "Medical Tent: " << name  << " activated with " << bedsAvailable << " beds available." << std::endl;
    }
}

void MedicalTent::close() {
    if (openState) {
        openState = false;
        isActive = false;
        std::cout << "Medical Tent: " << name << " deactivated." << std::endl;
    }
}

/**
 * @brief Reports the current status of the medical tent.
 */
void MedicalTent::reportStatus() const {
    std::cout << "Medical Tent: " << name << " Status:" << std::endl;
    std::cout << "  State: " << (openState ? "ACTIVE" : "INACTIVE") << std::endl;
    std::cout << "  Active: " << (isActive ? "YES" : "NO") << std::endl;
    std::cout << "  Beds Available: " << bedsAvailable << std::endl;
    std::cout << "  Beds Occupied: " << currentLoad << std::endl;
    std::cout << "  Capacity: " << capacity << std::endl;
}

/**
 * @brief Gets the maximum capacity beds of the medical tent.
 */
int MedicalTent::getCapacity() const {
    return capacity;
}

/**
 * @brief Gets the current load on the medical tent.
 */
int MedicalTent::getCurrentLoad() const {
    return currentLoad;
}

/**
 * @brief Handles event notifications affecting the medical tent.
 * @param notice The notice being processed
 */
void MedicalTent::update(const Notice& notice) {
    switch (notice.getType()) {
        case WEATHER_ALERT:
            std::cout << "Medical Tent: " << name << " remains active and reports increased emergency readiness." << std::endl;
            if (notice.getSeverity() > 1) {
                std::cout << "  High severity weather - preparing additional medical resources." << std::endl;
                currentLoad = capacity / 2; // Half capacity used for preparedness
                std::cout << "  " << currentLoad << " beds prepared for potential casualties." << std::endl;
            } else {
                std::cout << "  Monitoring weather conditions - standby mode." << std::endl;
            }
            break;
            
        case EVACUATE:
            std::cout << "Medical Tent: " << name << "' remains active during evacuation." << std::endl;
            if (openState && isActive) {
                std::cout << "  Medical staff ready for evacuation casualties." << std::endl;
            }
            break;
            
        case CAPACITY_ALERT:
            std::cout << "Medical Tent: " << name << " received capacity alert." << std::endl;
            if (currentLoad > capacity * 0.8) {
                std::cout << "  WARNING: Medical tent: " << name << " approaching capacity (" << currentLoad << "/" << capacity << " beds occupied)." << std::endl;
            }
            break;
            
        case HAZARD_ALERT:
            std::cout << "Medical Tent: " << name << " preparing for potential casualties from hazard." << std::endl;
            if (notice.getSeverity() >= 2) {
                std::cout << "  High severity hazard - activating the emergency protocols."<< std::endl;
            }
            break;
            
        default:
            std::cout << "Medical Tent: " << name << " received notice: " << notice.getMessage() << std::endl;
            break;
    }
    // Medical tent remains active regardless of most notices, as it must be ready for emergencies
}

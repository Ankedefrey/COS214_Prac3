/**
 * @file AidStation.cpp
 * @brief This is an implementation of the AidStation that provides hydration and nutrition to runners during the race. 
 * @author Jezelle Govender
 */

#include "AidStation.h"
#include "Notice.h"

#include <iostream>
#include <stdexcept>

AidStation::AidStation(const std::string& name, int capacity, int stock, int threshold): EventComponent(name, capacity),
      stockLevel(stock),
      lowStockThreshold(threshold),
      isServing(false) {
}

/**
 * @brief this just opens the aid station and beings to start serving runners
 */
void AidStation::open() {
    if(!openState) {
        openState = true;
        isServing = true;
        std::cout << "Aid Station: " << name << " is now open and serving runners." << std::endl;
    
    }
}

void AidStation::close() {
    if(openState == true) {
        openState = false;
        isServing = false;
        std::cout << "Sorry, Aid Station: " << name << " is closed for today." <<std::endl;
    }
}

void AidStation::reportStatus() const {
    std::cout << "Aid Station: " << name << " Status: " << std::endl;
    std::cout << "  State: " << (openState ? "Open" : "Closed") << std::endl;
    std::cout << "  Serving: " << (isServing ? "Yes" : "No") << std::endl;
    std::cout << "  Capacity: " << capacity << std::endl;
    std::cout << "  The current load: " << currentLoad << std::endl;
    std::cout << "  The stock level: " << stockLevel << std::endl;
    std::cout << "  Low stock threshold: " << lowStockThreshold << std::endl;
}


/**
 * @brief returns the maximum capacity of the aid station
 */
int AidStation::getCapacity() const {
    return capacity;
}

int AidStation::getCurrentLoad() const {
    return currentLoad;
}


/**
 * @brief This handles event notifications that affect the aid station
 * The different notice types trigger diff behaviors such as:
 * -Weather_Alert: Secures stock while continuing service
 * -Pause: Stops the service temporarily 
 * -Resume: Resumes the normal service
 * -Supply_Alert: Triggers to restock 
 * -Capacity_Alert: Checks if aid station has reached the maximum amount of people.
 * -Close: Stps service and closes the aid station
 * 
 * @param notice The notice that's being processed 
 */
void AidStation::update(const Notice& notice) {
    switch (notice.getType()) {
    case WEATHER_ALERT:
        std::cout << "Aid Station: " << name << " is securing stock while still maintaining services. " << std::endl;
        restock(10); 
        isServing = true;
        break;

    case PAUSE:
        std::cout << "Aid Station: " << name << " is pausing service while still keeping the stock protected." << std::endl;
        isServing = false;
        break;

    case RESUME:
        std::cout << "Aid Station: " << name << " has now resumed services." << std::endl;
        isServing = true;
        openState = true;
        break;

    case SUPPLY_ALERT:
        std::cout << "Aid Station: " << name << " has received the supply alert, and is now checking stock levels. " << std::endl;
        if(isStockLow()) {
            std::cout << " Stock is running low! Requesting a resupply." << std::endl;
            restock(50); //an emergency restock
        }
        break;

    case CAPACITY_ALERT:
        std::cout << "Aid Station: " << name << " has received a capacity alert." << std::endl;
        if(currentLoad >= capacity) {
            std::cout << " At full capacity. Notifying for additional support." << std::endl;
        }
        break;

    case CLOSE:
        std::cout << " Aid Station: " << name << " is now closed." << std::endl;
        close();
        break;

    default:
        std::cout << "Aid Station: " << name << " received notice: " << notice.getMessage() << " (Type: " << notice.getType() << ")" << std::endl;
        break;
    }
}

/**
 * @brief Serving a runner at the aid station
 * @param unitsUsed the amount of supplies that a runner consumes
 */
void AidStation::serveRunner(int unitsUsed) {
    if(!openState || !isServing) {
        std::cout << "Aid Station: " << name << " cannot serve the runner, as the station is not operational." << std::endl;
        return;
    }

    if (stockLevel < unitsUsed) {
        std::cout << "Aid Station: " << name  << " has insufficient stock to serve runner." << std::endl;
        return;
    }
    
    if (currentLoad >= capacity) {
        std::cout << "Aid Station: " << name << " is at capacity - cannot serve more runners." << std::endl;
        return;
    }

    stockLevel -= unitsUsed;
    currentLoad++;
    std::cout << "Aid Station: " << name << " has served runner. Stock level now: " << stockLevel << ", Load: " << currentLoad << std::endl;
    
    if (isStockLow()) {
        std::cout << "  WARNING: The stock level is low (" << stockLevel << " units remaining)." << std::endl;
    }
}


/**
 * @brief Checks if the aid station's stock is below the threshold.
 * 
 * @return true if stock level is below threshold, false otherwise
 */
bool AidStation::isStockLow() const {
    return stockLevel < lowStockThreshold;
}

/**
 * @brief Restocks the aid station with additional supplies.
 * 
 * @param amount The amount of supplies to add
 */
void AidStation::restock(int amount) {
    stockLevel += amount;
    std::cout << "Aid Station: " << name << " restocked with " << amount << " units. New stock level: " << stockLevel << std::endl;
}

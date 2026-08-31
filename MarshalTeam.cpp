/**
 * @file MarshalTeam.cpp
 * @brief Concrete Leaf: a team of marshals responsible for runner safety.
 * This is an implementation of MarshalTeam that provides safety during the race.
 *
 * GoF role: ConcreteComponent (Composite) and ConcreteObserver (Observer),
 * with an extra ability of its own,
 * it can originate a HAZARD_ALERT Notice via createHazardNotice() rather than only ever reacting to
 * notices issued by EventControl.
 *
 * @author Jezelle Govender
 */

#include "MarshalTeam.h"
#include "Notice.h"

#include <iostream>


/**
     * @brief Constructs a marshal team.
     * @param name Human-readable identifier.
     * @param size Number of marshals in the team (also used as capacity).
     */
MarshalTeam::MarshalTeam(const std::string& name, int size)
    : EventComponent(name, size), teamSize(size), isDeployed(false) {
}

/**
 * @brief Deploys the marshal team for active duty.
 */
void MarshalTeam::open() {
    if (!openState) {
        openState = true;
        isDeployed = true;
        std::cout << "Marshal Team '" << name << "' deployed with " << teamSize << " marshals." << std::endl;
    }
}

/**
 * @brief This recalls the marshal team from active duty.
 */
void MarshalTeam::close() {
    if (openState) {
        openState = false;
        isDeployed = false;
        std::cout << "Marshal Team '" << name << "' recalled." << std::endl;
    }
}

/**
 * @brief Reports the current status of the marshal team.
 */
void MarshalTeam::reportStatus() const {
    std::cout << "Marshal Team '" << name << "' Status:" << std::endl;
    std::cout << "  State: " << (openState ? "DEPLOYED" : "RECALLED") << std::endl;
    std::cout << "  Deployed: " << (isDeployed ? "YES" : "NO") << std::endl;
    std::cout << "  Team Size: " << teamSize << std::endl;
    std::cout << "  Current Load: " << currentLoad << std::endl;
}

/// @return The team's size.
int MarshalTeam::getCapacity() const {
    return teamSize;
}

/// @return How many marshals are currently assigned to a task.
int MarshalTeam::getCurrentLoad() const {
    return currentLoad;
}

/**
 * @brief Handles event notifications affecting the marshal team.
 *
 * Different notice types trigger different behaviors:
 * - WEATHER_ALERT: Redirects runners away from danger
 * - HAZARD_ALERT: Responds to hazards with appropriate actions
 * - EVACUATE: Assists in evacuation procedures
 * - ROUTE_CHANGE: Implements route changes
 *
 * @param notice The notice being processed
 */
void MarshalTeam::update(const Notice& notice) {
    switch (notice.getType()) {
        case WEATHER_ALERT:
            if (notice.getSeverity() > 1) {
                std::cout << "Marshal Team '" << name << "' redirecting runners away from danger zones." << std::endl;
                redeploy();
                // Redirect the runners based on severity
                std::cout << "  High severity weather alert - runners redirected to safe routes." << std::endl;
            } else {
                std::cout << "Marshal Team '" << name << "' monitoring weather conditions and advising runners." << std::endl;
            }
            break;
            
        case HAZARD_ALERT:
            std::cout << "Marshal Team '" << name << "' responding to hazard: " << notice.getMessage() << std::endl;
            if (notice.getSeverity() >= 2) {
                std::cout << "  High severity hazard - immediate rerouting of runners." << std::endl;
                redeploy();
            } else {
                std::cout << "  Low severity hazard - monitoring situation." << std::endl;
            }
            break;
            
        case EVACUATE:
            std::cout << "Marshal Team '" << name << "' assisting in evacuation procedures." << std::endl;
            isDeployed = true;
            std::cout << "  Marshals directing runners to evacuation points." << std::endl;
            break;
            
        case ROUTE_CHANGE:
            std::cout << "Marshal Team '" << name << "' implementing route change: " << notice.getMessage() << std::endl;
            redeploy();
            std::cout << "  Marshals repositioned to support new route." << std::endl;
            break;
            
        case SECTOR_CLOSED:
            std::cout << "Marshal Team '" << name << "' securing closed sector: " << notice.getMessage() << std::endl;
            if (isDeployed) {
                std::cout << "  Marshals blocking access to closed sector." << std::endl;
            }
            break;
            
        case CUTOFF_ALERT:
            std::cout << "Marshal Team '" << name << "' responding to cutoff alert." << std::endl;
            if (isDeployed) {
                std::cout << "  Marshals assisting runners behind cutoff pace." << std::endl;
            }
            break;
            
        default:
            std::cout << "Marshal Team '" << name << "' received notice: " << notice.getMessage() << std::endl;
            break;
    }
}

/**
 * @brief Creates a hazard notice for reporting dangerous situations.
 * 
 * @param message Description of the hazard
 * @param severity Severity level of 1-3, where 3 is most severe
 */
Notice MarshalTeam::createHazardNotice(const std::string& message, int severity) {
    std::cout << "Marshal Team '" << name << "' reporting hazard: " << message << " (Severity: " << severity << ")" << std::endl;
    return Notice(HAZARD_ALERT, message, severity);
}

/**
 * @brief Moves the marshal team to new positions.
 */
void MarshalTeam::redeploy() {
    std::cout << "Marshal Team '" << name << "' redeploying marshals to new positions." << std::endl;
    currentLoad = teamSize; // All marshals now assigned
    //teamSize is total no. of marshals in team, and currentLoad is how many marshalls are currently assigned to tasks.
    std::cout << "  All " << teamSize << " marshals redeployed to new positions." << std::endl;
}


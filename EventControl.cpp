/**
 * @file EventControl.cpp
 * @brief GoF ConcreteSubject: the central control point for the event.
 *
 * Implementation of the EventControl (ConcreteSubject) that manages race root and issues notifications
 * @author Kayla Falconer
 */

#include "EventControl.h"

#include "EventComponent.h"
#include "Notice.h"

#include <algorithm>
#include <iostream>

/**
 * @brief Constructs an EventControl with no race root
 */
EventControl::EventControl()
    : raceRoot(nullptr) {
}

/**
 * @brief Registers an observer to receive notifications from EventControl
 * @param observer The observer to register
 * 
 * @note Duplicate registrations and null pointers are ignored
 */
void EventControl::attach(Observer* observer) {
    if(observer == nullptr)
    {
        return;
    }

    // check for any duplicates
    auto it = std::find(observers.begin(), observers.end(), observer);
    if(it == observers.end())
    {
        observers.push_back(observer);
        std::cout << "EventControl: Observer attached" << std::endl;
    }
}

/**
 * @brief Removes a registered observer from EventControl
 * @param observer The observer to deregister
 *
 * @note The observer is not deleted, but removed from the list
 */

void EventControl::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
        std::cout << "EventControl: Observer detached" << std::endl;
    }
}

/**
 * @brief Notifies all registered observers with given notice
 * @param notice The notice to send to all observers
 */
void EventControl::notify(const Notice& notice) {
    if(observers.empty() == true)
    {
        return;
    }
    
    // Create a snapshot, copy, to handle changes during notifications
    std::vector<Observer*> snapshot = observers;
    
    std::cout << "EventControl: " << snapshot.size() << " observers notified" << std::endl;
    
    // notify all the observers in the snapshot
    for(Observer* observer : snapshot)
    {
        if(observer != nullptr)
        {
            observer->update(notice);
        }
    }
}

/**
 * @brief Creates and issues a notice of the given type
 * @param type The type of notice
 * @param message Description of the notice
 * @param severity Severity level
 */
void EventControl::issueNotice(NoticeType type, const std::string& message, int severity) {
    Notice notice(type, message, severity);
    std::cout << "EventControl: Issuing notice: " << message << " with severity: " << severity << std::endl;
    notify(notice);
}

/**
 * @brief Issues an existing notice - overloading
 * @param notice The notice to send
 */
void EventControl::issueNotice(const Notice& notice) {
    std::cout << "EventControl: Issuing notice: " << notice.getMessage() << " with severity: " << notice.getSeverity() << std::endl;
    notify(notice);
}

/**
 * @brief Sets the root of the race tree
 * @param root The root EventComponent (RaceEvent) to manage
 *
 * @note If a new root is set, the old one is deleted
 */
void EventControl::setRaceRoot(EventComponent* root) {
    if(raceRoot != nullptr && raceRoot != root)
    {
        std::cout << "EventControl: Warning: root already exists --> deleting old root" << std::endl;

        delete raceRoot;
    }
    raceRoot = root;

    if(root != nullptr)
    {
        std::cout << "EventControl: Race root set to " << root->getName() << std::endl;
    }
}

/**
 * @brief Get current race root
 * @return The root EventComponent or nullptr if none is set
 */
EventComponent* EventControl::getRaceRoot() const {
    return raceRoot;
}

/**
 * @brief Destroys the EventControl and deletes the race root
 */
EventControl::~EventControl() {
    std::cout << "EventControl: Destructor (deleting race root)" << std::endl;
    // Registration is non-owning, so clear it before deleting the root.
    observers.clear();  // observers are non-owning, so don't delete them. 
    delete raceRoot;
    raceRoot = nullptr;
}

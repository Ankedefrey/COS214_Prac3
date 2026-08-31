/**
 * @file EventGroup.cpp
 * @brief Implementation of the EventGroup that manages EventComponent children and deals with ownership
 * @author Jezelle Govender
 */
#include "EventGroup.h"
#include "Notice.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

EventGroup::EventGroup(const std::string& name)
    : EventComponent(name, 0) {
}
/**
 * @brief Adds a child component to this group, taking ownership
 * @param child the child component to adopt
 */
void EventGroup::addChild(EventComponent* child) {
    if (child != nullptr) {
        children.push_back(child);
        std::cout << "EventGroup: " << name << " has adopted child '" << child->getName() << "'" << std::endl;
    }
}

/**
 * @brief Releases ownership of a child component without deleting it.
 * @param child child component to release
 * @return The released pointer, or nullptr if not found
 */
EventComponent* EventGroup::releaseChild(EventComponent* child) {
    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end()) {
        children.erase(it);
        std::cout << "EventGroup: " << name << " has released child '" << child->getName() << "'" << std::endl;
        return child;
    }
    return nullptr;
}

/**
 * @brief Transfers a child to a new parent group
 * @param child child component to transfer
 * @param newParent new parent group
 * @return true if transfer was successful, else false 
 */
bool EventGroup::transferChild(EventComponent* child, EventGroup* newParent) {
    if(child == nullptr || newParent == nullptr) {
        return false;
    }

    EventComponent* released = releaseChild(child);  //release from the current parent
    if (released == nullptr) {
        std::cout << "EventGroup: " << name << " failed to transfer child: not found" << std::endl;
        return false;
    }
    
    // Adopt by a new parent
    newParent->addChild(released);
    std::cout << "EventGroup: " << name << " transferred child '" << child->getName() << "' to '" << newParent->getName() << "'" << std::endl;
    return true;
}

/**
 * @brief opens the group and all children, and delegates to all children
 */
void EventGroup::open() {
     if (!openState) {
        openState = true;
        std::cout << "EventGroup: " << name << " has opened." << std::endl;
        
        for (EventComponent* child : children) {  //Delegate to all children
            child->open();
        }
    }
}

void EventGroup::close() {
    if (openState) {
        openState = false;
        std::cout << "EventGroup: " << name << " closed." << std::endl;
        
        for (EventComponent* child : children) {
            child->close();
        }
    }
}

/**
 * @brief Reports the status of the group and all children
 */
void EventGroup::reportStatus() const {
    std::cout << "EventGroup: " << name << " Status:" << std::endl;
    std::cout << "  State: " << (openState ? "OPEN" : "CLOSED") << std::endl;
    std::cout << "  Children Count: " << children.size() << std::endl;
    std::cout << "  Observers Count: " << observers.size() << std::endl;
    std::cout << "  Total Capacity: " << getCapacity() << std::endl;
    std::cout << "  Total Load: " << getCurrentLoad() << std::endl;
   
    for (const EventComponent* child : children) {
        child->reportStatus();
    }
}

int EventGroup::getCapacity() const {
    int total = 0;
    for (const EventComponent* child : children) {
        total += child->getCapacity();
    }
    return total;
}

int EventGroup::getCurrentLoad() const {
    int total = 0;
    for (const EventComponent* child : children) {
        total += child->getCurrentLoad();
    }
    return total;
}

/**
 * @brief Updates the group state and forwards notices to children
 * First updates own state, then notifies all observers
 * @param notice notice to process and forward
 */
void EventGroup::update(const Notice& notice) {
    // Update only group-level state relevant to the notice
    std::cout << "EventGroup: " << name << " received notice: " << notice.getMessage() << std::endl;
    
    notify(notice); // Just forward to the observers
}

/**
 * @brief Registers an observer to receive notifications
 * @param observer The observer to register
 */
void EventGroup::attach(Observer* observer) {
    if (observer == nullptr) {
        return;
    }
    
    // check for any duplicates
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it == observers.end()) {
        observers.push_back(observer);
        std::cout << "EventGroup: " << name << " attached observer" << std::endl;
    }
}

/**
 * @brief Deregisters an observer from receiving any notifications
 * @param observer the observer to deregister
 */
void EventGroup::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
        std::cout << "EventGroup: " << name << " detached observer" << std::endl;
    }
}

/**
 * @brief Notifies all registered observers with the given notice
 * @param notice The notice to send to all observers
 */
void EventGroup::notify(const Notice& notice) {
    if (observers.empty()) {
        return;
    }
    
    // Create a snapshot, copy, to handle changes during notifications
    std::vector<Observer*> snapshot = observers;
    
    std::cout << "EventGroup: " << name << " notifying " << snapshot.size() << " observers" << std::endl;
    
    // notify all the observers in the snapshot
    for (Observer* observer : snapshot) {
        if (observer != nullptr) {
            observer->update(notice);
        }
    }
}

/**
 * @brief Destroys the EventGroup and recursively deletes all owned children.
 */
EventGroup::~EventGroup() {
      std::cout << "EventGroup: " << name << " destructor: deleting " << children.size() << " children" << std::endl;

    for (EventComponent* child : children) {  // delete all the owned children
        delete child;
    }
    children.clear();
    observers.clear(); // observers are non-owning, so don't delete them. 
}

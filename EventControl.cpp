#include "EventControl.h"

#include "EventComponent.h"
#include "Notice.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

EventControl::EventControl()
    : raceRoot(nullptr) {
}

void EventControl::attach(Observer* observer) {
    if(observer == nullptr)
    {
        return;
    }

    auto it = std::find(observers.begin(), observers.end(), observer);
    if(it == observers.end())
    {
        observers.push_back(observer);
        std::cout << "EventControl: Observer attached" << std::endl;
    }
}

void EventControl::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
        std::cout << "EventControl: Observer detached" << std::endl;
    }
}

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

void EventControl::issueNotice(NoticeType type,
                               const std::string& message,
                               int severity) {
    Notice notice(type, message, severity);
    std::cout << "EventControl: Issuing notice: " << message << " with severity: " << severity << std::endl;
    notify(notice);
}

void EventControl::issueNotice(const Notice& notice) {
    std::cout << "EventControl: Issuing notice: " << notice.getMessage() << " with severity: " << notice.getSeverity() << std::endl;
    notify(notice);
}

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

EventComponent* EventControl::getRaceRoot() const {
    return raceRoot;
}

EventControl::~EventControl() {
    std::cout << "EventControl: Destructor (deleting race root)" << std::endl;
    // Registration is non-owning, so clear it before deleting the root.
    observers.clear();
    delete raceRoot;
    raceRoot = nullptr;
}

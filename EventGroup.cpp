#include "EventGroup.h"

#include "Notice.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

EventGroup::EventGroup(const std::string& name)
    : EventComponent(name, 0) {
}

void EventGroup::addChild(EventComponent* child) {
    (void) child;
    throw "Not yet implemented";
}

EventComponent* EventGroup::releaseChild(EventComponent* child) {
    (void) child;
    throw "Not yet implemented";
}

bool EventGroup::transferChild(EventComponent* child,
                               EventGroup* newParent) {
    (void) child;
    (void) newParent;
    throw "Not yet implemented";
}

void EventGroup::open() {
    throw "Not yet implemented";
}

void EventGroup::close() {
    throw "Not yet implemented";
}

void EventGroup::reportStatus() const {
    throw "Not yet implemented";
}

int EventGroup::getCapacity() const {
    throw "Not yet implemented";
}

int EventGroup::getCurrentLoad() const {
    throw "Not yet implemented";
}

void EventGroup::update(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

//Task 3.1

void EventGroup::attach(Observer* observer) {
    if(observer == nullptr)
    {
        return;  //never store null
    }

    for(Observer* o : observers)
    {
        if(o == observer)  //look for duplicates
        {
            return;  //avoid storing duplicate
        }
    }

    observers.push_back(observer);  //append to list
}

//forgets address, not deletion (or it will result in double delete later)
void EventGroup::detach(Observer* observer) {
    if(observer == nullptr)
    {
        return;
    }

    std::vector<Observer*>::iterator it = observers.begin();
    while(it != observers.end())
    {
        if(*it == observer)  //search for pointer in list
        {
            observers.erase(it);  //remove pointer from list
            return;
        }

        ++it;
    }
}

void EventGroup::notify(const Notice& notice) {
    std::vector<Observer*> snapshot = observers;  //copy list into temporary snapshot
    //live looping list could result in skipping people, hitting people twice, or blowing up the iterator

    for(Observer* o : snapshot)
    {
        if(o != nullptr)
        {
            o->update(notice);  //update each pointer
        }
    }
}

EventGroup::~EventGroup() {
    throw "Not yet implemented";
}

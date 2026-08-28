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

void EventGroup::attach(Observer* observer) {
    (void) observer;
    throw "Not yet implemented";
}

void EventGroup::detach(Observer* observer) {
    (void) observer;
    throw "Not yet implemented";
}

void EventGroup::notify(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

EventGroup::~EventGroup() {
    throw "Not yet implemented";
}

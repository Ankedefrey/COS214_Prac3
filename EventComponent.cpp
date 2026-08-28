#include "EventComponent.h"

EventComponent::EventComponent(const std::string& name, int capacity)
    : name(name),
      openState(false),
      capacity(capacity),
      currentLoad(0) {
}

std::string EventComponent::getName() const {
    return name;
}

bool EventComponent::isOpen() const {
    return openState;
}

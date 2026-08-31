/**
 * @brief GoF Component role for the Composite pattern.
 *
 * EventComponent is the common interface for every part of the event tree,
 * whether it's a single operational unit or a group containing further components.
 * Code that just wants to open/close/report on/query part of the event can hold
 * an EventComponent* without knowing which concrete kind it is.
 *
 * EventComponent also implements Observer, so every component in the tree
 * is capable of receiving notices,
 * this is a separate collaboration from Composite, and is why some subclasses (EventGroup) additionally
 * implement Subject: a component can both receive notices from above and forward them to interested parties below.
 *
 * @author Anke de Frey
 */
#include "EventComponent.h"

/**
     * @brief Constructs a component with a name and an optional capacity.
     * @param name Human-readable identifier shown in status output.
     * @param capacity Maximum capacity of this single component.
     * Composite subclasses (EventGroup) ignore this constructor argument and
     * compute their capacity recursively from their children instead.
     */
EventComponent::EventComponent(const std::string& name, int capacity)
    : name(name), openState(false), capacity(capacity), currentLoad(0) {
}

/// @return This component's name.
std::string EventComponent::getName() const {
    return name;
}

/// @return True if this component is currently open.
bool EventComponent::isOpen() const {
    return openState;
}

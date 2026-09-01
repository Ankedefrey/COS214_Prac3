#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include "Observer.h"

#include <string>

/**
 * @brief GoF ConcreteSubject: the central control point for the event.
 *
 */


class EventComponent : public Observer {
protected:
    std::string name;
    bool openState;
    int capacity;
    int currentLoad;

public:
    explicit EventComponent(const std::string& name, int capacity = 0);

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;
    virtual int getCurrentLoad() const = 0;
    virtual void update(const Notice& notice) = 0;

    std::string getName() const;
    bool isOpen() const;

    virtual ~EventComponent() = default;
};

#endif

#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Subject.h"

#include <string>
#include <vector>

/**
 * @brief GoF Composite role, and also a concrete Subject.
 * Implementation of the EventGroup that manages EventComponent children and deals with ownership.
 */

class EventGroup : public EventComponent, public Subject {
private:
    std::vector<EventComponent*> children;
    std::vector<Observer*> observers;

public:
    explicit EventGroup(const std::string& name);

    void addChild(EventComponent* child);
    EventComponent* releaseChild(EventComponent* child);
    bool transferChild(EventComponent* child, EventGroup* newParent);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int getCurrentLoad() const override;
    void update(const Notice& notice) override;

    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notify(const Notice& notice) override;

    ~EventGroup() override;
};

#endif

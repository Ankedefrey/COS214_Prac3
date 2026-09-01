#ifndef MEDICALTENT_H
#define MEDICALTENT_H

#include "EventComponent.h"

#include <string>

/**
 * @brief GoF role: ConcreteComponent (Composite) and ConcreteObserver (Observer).
 * Deliberately stays active through most notices (including EVACUATE and
 * WEATHER_ALERT) where other leaves pause or close, since a medical tent
 * needs to remain available for casualties precisely when other units are
 * suspending service.
 */

class MedicalTent : public EventComponent {
private:
    int bedsAvailable;
    bool isActive;

public:
    MedicalTent(const std::string& name, int beds);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int getCurrentLoad() const override;
    void update(const Notice& notice) override;
};

#endif

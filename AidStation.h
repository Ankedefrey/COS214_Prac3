#ifndef AIDSTATION_H
#define AIDSTATION_H

#include "EventComponent.h"

#include <string>

/**
 * @brief Concrete Leaf: a hydration/nutrition station serving runners.
 * GoF role: ConcreteComponent (Composite) and ConcreteObserver (Observer,
 * inherited via EventComponent)
 * it reacts to notices such as WEATHER_ALERT, SUPPLY_ALERT, EVACUATE and HAZARD_ALERT differently from
 * every other leaf type in the system.
 */

class AidStation : public EventComponent {
private:
    int stockLevel;
    int lowStockThreshold;
    bool isServing;

public:
    AidStation(const std::string& name, int capacity, int stock, int threshold);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int getCurrentLoad() const override;
    void update(const Notice& notice) override;

    void serveRunner(int unitsUsed);
    bool isStockLow() const;
    void restock(int amount);
};

#endif

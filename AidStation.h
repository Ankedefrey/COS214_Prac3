#ifndef AIDSTATION_H
#define AIDSTATION_H

#include "EventComponent.h"

#include <string>

class AidStation : public EventComponent {
private:
    int stockLevel;
    int lowStockThreshold;
    bool isServing;

public:
    AidStation(const std::string& name,
               int capacity,
               int stock,
               int threshold);

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

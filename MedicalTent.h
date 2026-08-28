#ifndef MEDICALTENT_H
#define MEDICALTENT_H

#include "EventComponent.h"

#include <string>

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

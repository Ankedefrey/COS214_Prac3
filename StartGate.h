#ifndef STARTGATE_H
#define STARTGATE_H

#include "EventComponent.h"

#include <string>

/**
 * @brief GoF role: ConcreteComponent (Composite) and ConcreteObserver (Observer).
 */

class StartGate : public EventComponent {
private:
    int batchSize;
    bool isOpenForStart;

public:
    StartGate(const std::string& name, int batchSize);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int getCurrentLoad() const override;
    void update(const Notice& notice) override;

    bool admitRunners(int count);
};

#endif

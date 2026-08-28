#ifndef TIMINGPOINT_H
#define TIMINGPOINT_H

#include "EventComponent.h"

#include <string>

class TimingPoint : public EventComponent {
private:
    int checkpointNumber;
    int cutoffTime;
    bool isRecording;
    bool backupMode;

public:
    TimingPoint(const std::string& name,
                int number,
                int cutoff,
                int capacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int getCurrentLoad() const override;
    void update(const Notice& notice) override;

    bool recordRunner(int runnerNumber, int arrivalTime);
};

#endif

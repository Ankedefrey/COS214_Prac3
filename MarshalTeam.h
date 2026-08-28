#ifndef MARSHALTEAM_H
#define MARSHALTEAM_H

#include "EventComponent.h"
#include "Notice.h"

#include <string>

class MarshalTeam : public EventComponent {
private:
    int teamSize;
    bool isDeployed;

public:
    MarshalTeam(const std::string& name, int size);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int getCurrentLoad() const override;
    void update(const Notice& notice) override;

    Notice createHazardNotice(const std::string& message, int severity);
    void redeploy();
};

#endif

#ifndef MARSHALTEAM_H
#define MARSHALTEAM_H

#include "EventComponent.h"
#include "Notice.h"

#include <string>

/**
 * @brief GoF role: ConcreteComponent (Composite) and ConcreteObserver (Observer),
 * with an extra ability of its own,
 * it can originate a HAZARD_ALERT Notice via createHazardNotice() rather than only ever reacting to
 * notices issued by EventControl.

 */

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

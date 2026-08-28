#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "NoticeType.h"
#include "Subject.h"

#include <string>
#include <vector>

class EventComponent;
class Notice;
class Observer;

class EventControl : public Subject {
private:
    std::vector<Observer*> observers;
    EventComponent* raceRoot;

public:
    EventControl();

    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notify(const Notice& notice) override;

    void issueNotice(NoticeType type,
                     const std::string& message,
                     int severity = 1);
    void issueNotice(const Notice& notice);

    void setRaceRoot(EventComponent* root);
    EventComponent* getRaceRoot() const;

    ~EventControl() override;
};

#endif

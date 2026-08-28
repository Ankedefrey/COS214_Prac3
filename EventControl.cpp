#include "EventControl.h"

#include "EventComponent.h"
#include "Notice.h"

#include <algorithm>
#include <stdexcept>

EventControl::EventControl()
    : raceRoot(nullptr) {
}

void EventControl::attach(Observer* observer) {
    (void) observer;
    throw "Not yet implemented";
}

void EventControl::detach(Observer* observer) {
    (void) observer;
    throw "Not yet implemented";
}

void EventControl::notify(const Notice& notice) {
    (void) notice;
    throw "Not yet implemented";
}

void EventControl::issueNotice(NoticeType type,
                               const std::string& message,
                               int severity) {
    Notice notice(type, message, severity);
    notify(notice);
}

void EventControl::issueNotice(const Notice& notice) {
    notify(notice);
}

void EventControl::setRaceRoot(EventComponent* root) {
    if (raceRoot != nullptr && raceRoot != root) {
        throw "Not yet implemented";
    }
    raceRoot = root;
}

EventComponent* EventControl::getRaceRoot() const {
    return raceRoot;
}

EventControl::~EventControl() {
    // Registration is non-owning, so clear it before deleting the root.
    observers.clear();
    delete raceRoot;
    raceRoot = nullptr;
}

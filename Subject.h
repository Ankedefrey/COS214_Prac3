#ifndef SUBJECT_H
#define SUBJECT_H

class Notice;
class Observer;

class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(const Notice& notice) = 0;
    virtual ~Subject() = default;
};

#endif

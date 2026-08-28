#ifndef OBSERVER_H
#define OBSERVER_H

class Notice;

class Observer {
public:
    virtual void update(const Notice& notice) = 0;
    virtual ~Observer() = default;
};

#endif

#ifndef OBSERVER_H
#define OBSERVER_H

class Notice;

/**
 * @brief GoF Observer role: anything that wants to react to a Notice.
 *
 * Any class that needs to be told about events happening elsewhere in the
 * EventFlow tree implements this interface and registers itself with a
 * Subject via Subject::attach().
 * A single object may be attached to more than one Subject at a time.
 */

class Observer {
public:
    /**
     * @brief Called by a Subject to deliver a Notice.
     *
     * This design uses the "push" style of Observer: the Subject passes
     * the full Notice (type, message and severity) directly into this
     * call, so the Observer never needs to query the Subject for state.
     *
     * @param notice The notice describing what happened. The reference is
     * only valid for the duration of this call.
     */
    virtual void update(const Notice& notice) = 0;

    /**
     * @brief Virtual destructor so derived Observers destroy correctly through a base-class pointer.
     */
    virtual ~Observer() = default;
};

#endif

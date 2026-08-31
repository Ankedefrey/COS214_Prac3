#ifndef SUBJECT_H
#define SUBJECT_H

class Notice;
class Observer;

/**
 * @brief GoF Subject role: something that can be observed
 * A Subject keeps a list of registered Observer pointers and notifies them
 * when something changes.
 * The Subject never owns the Observers it stores,
 * every pointer here is non-owning.
 * An Observer must be detached (or must outlive the Subject) before it is destroyed,
 * otherwise the Subject is left holding a dangling pointer.
 */
class Subject {
public:
    /**
     * @brief Registers an observer for future notifications.
     *
     * Implementations must ignore a nullptr and ignore an observer that is
     * already registered (no duplicate entries).
     *
     * @param observer Observer to register. This Subject does not take
     * ownership; the caller remains responsible for the observer's
     * lifetime and must detach() it before deleting it.
     */
    virtual void attach(Observer* observer) = 0;

    /**
     * @brief Deregisters an observer so it no longer receives notifications.
     *
     * Implementations must do nothing (not throw or crash) if the given
     * observer was never registered.
     *
     * @param observer Observer to remove. Never deleted by this call, the
     * Subject only forgets the pointer, it never owned it.
     */
    virtual void detach(Observer* observer) = 0;

    /**
     * @brief Notifies every currently registered observer.
     *
     * Implementations should notify a snapshot of the registration list,
     * not the live list, so an observer that attaches or detaches itself
     * from inside update() cannot corrupt the notification in progress.
     *
     * @param notice The notice to deliver to every observer.
     */
    virtual void notify(const Notice& notice) = 0;

    /**
     * @brief Virtual destructor so derived Subjects destroy correctly through a base-class pointer.
     */
    virtual ~Subject() = default;
};

#endif

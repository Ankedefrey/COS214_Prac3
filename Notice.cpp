/**
 * @brief The message passed from a Subject to its Observers.
 *
 * This is the payload used by this project's "push" Observer
 * implementation: it carries everything an Observer needs
 * (what happened, a human-readable description, and how serious it is) so the Observer
 * never needs to call back into the Subject to ask for more information.
 */
#include "Notice.h"

/**
     * @brief Constructs a Notice.
     * @param type The category of notice, see NoticeType.
     * @param message Human-readable description shown in status output.
     * @param severity How serious this notice is. Higher means more severe,
     * concrete Observers may branch on this
     */
Notice::Notice(NoticeType type, const std::string& message, int severity)
    : type(type), message(message), severity(severity) {
}

/// @return The category of this notice.
NoticeType Notice::getType() const {
    return type;
}

/// @return The human-readable description of this notice.
std::string Notice::getMessage() const {
    return message;
}

/// @return The severity level of this notice.
int Notice::getSeverity() const {
    return severity;
}

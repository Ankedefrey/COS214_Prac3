#include "Notice.h"

Notice::Notice(NoticeType type,
               const std::string& message,
               int severity)
    : type(type),
      message(message),
      severity(severity) {
}

NoticeType Notice::getType() const {
    return type;
}

std::string Notice::getMessage() const {
    return message;
}

int Notice::getSeverity() const {
    return severity;
}

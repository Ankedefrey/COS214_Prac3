#ifndef NOTICE_H
#define NOTICE_H

#include "NoticeType.h"

#include <string>

class Notice {
private:
    NoticeType type;
    std::string message;
    int severity;

public:
    Notice(NoticeType type,
           const std::string& message,
           int severity = 1);

    NoticeType getType() const;
    std::string getMessage() const;
    int getSeverity() const;
};

#endif

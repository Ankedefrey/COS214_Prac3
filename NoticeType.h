#ifndef NOTICETYPE_H
#define NOTICETYPE_H

/**
 * @brief The kinds of notice EventControl (or any Subject) can issue.
 *
 * Covers ordinary operational changes (OPEN, CLOSE, ROUTE_CHANGE, SECTOR_CLOSED),
 * capacity-related changes (CAPACITY_ALERT, SUPPLY_ALERT, CUTOFF_ALERT)
 * and
 * safety-related changes (WEATHER_ALERT, EVACUATE, HAZARD_ALERT, PAUSE, RESUME).
 */

enum NoticeType {
    OPEN, ///< An area or unit is opening.
    CLOSE, ///< An area or unit is closing.
    CAPACITY_ALERT, ///< A unit is at or near its maximum capacity.
    WEATHER_ALERT, ///< A weather condition affecting the event.
    PAUSE, ///< Temporarily suspend activity.
    RESUME, ///< Resume activity after a pause.
    EVACUATE, ///< Evacuate the affected area immediately.
    ROUTE_CHANGE, ///< The course/route has changed.
    SECTOR_CLOSED, ///< A specific sector has been closed off.
    CUTOFF_ALERT, ///< A time cutoff has been reached or missed.
    SUPPLY_ALERT, ///< Supplies/stock need attention.
    HAZARD_ALERT ///< A hazard has been reported.
};

#endif

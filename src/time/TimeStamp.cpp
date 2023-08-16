/**
 * @file TimeStamp.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/time/TimeStamp.hpp"

namespace dt {
    /**
     * @brief @c TimeStamp constructor.
     * @param h
     *          The hour.
     * @param m
     *          The minute.
     * @param s
     *          The second.
     * @param milli
     *          The millisecond
     */
    TimeStamp::TimeStamp(int h, int m, int s, int milli) {
        if (isValidTime(h, m, s, milli)) {
            hour = h;
            minute = m;
            second = s;
            millisecond = milli;
        }
    }

    /**
     * @brief @c TimeStamp constructor.
     * @param timeStamp
     *          The string representation of the time stamp.
     */
    TimeStamp::TimeStamp(const std::string& timeStamp) {
        parse(timeStamp);
    }

    /**
     * @brief Adds a specified number of hours to the time.
     * @param hours
     *          The number of hours to add.
     */
    void TimeStamp::addHours(int hours) {
        hour += hours;
        adjustHour();
    }

    /**
     * @brief Adds a specified number of minutes to the time.
     * @param minutes
     *          The number of hours to add.
     */
    void TimeStamp::addMinutes(int minutes) {
        minute += minutes;
        adjustMinute();
    }

    /**
     * @brief Adds a specified number of minutes to the time.
     * @param seconds
     *          The number of seconds to add.
     */
    void TimeStamp::addSeconds(int seconds) {
        second += seconds;
        adjustSecond();
    }

    /**
     * @brief Adds a specified number of milliseconds to the time
     * @param milliseconds
     *          The number of milliseconds to add.
     */
    void TimeStamp::addMilliseconds(int milliseconds) {
        millisecond += milliseconds;
        adjustMillisecond();
    }

    /**
     * @brief Overrides the time and sets it to the current time.
     */
    void TimeStamp::setToCurrentTime() {
        std::string timeStamp{DateTimeUtils::getCurrentTimeStr()};
        parse(timeStamp);
    }

    /**
     * @brief Sets the time stamp to a new time.
     * @param h
     *          The hour.
     * @param m
     *          The minute.
     * @param s
     *          The second.
     * @param milli
     *          The millisecond.
     * @throws InvalidTimeException
     *          if the time is invalid.
     */
    void TimeStamp::setTime(int h, int m, int s, int milli) {
        if (isValidTime(h, m, s, milli)) {
            hour = h;
            minute = m;
            second = s;
            millisecond = milli;
        } else {
            throw InvalidTimeException("Invalid time set. Check formatting.");
        }
    }

    /**
     * @brief Gets the hour.
     * @return The hour.
     */
    int TimeStamp::getHour() const {
        return hour;
    }

    /**
     * @brief Gets the minute.
     * @return The minute.
     */
    int TimeStamp::getMinute() const {
        return minute;
    }

    /**
     * @brief Gets the second.
     * @return The second.
     */
    int TimeStamp::getSecond() const {
        return second;
    }

    /**
     * @brief Gets the millisecond.
     * @return The millisecond.
     */
    int TimeStamp::getMillisecond() const {
        return millisecond;
    }

    /**
     * @brief Converts the time stamp to a string.
     * @return The time stamp as a string.
     */
    std::string TimeStamp::toString() const {
        std::stringstream ss;
        ss << formatTimeStampComponent(hour) << consts::TIME_SEPARATOR;
        ss << formatTimeStampComponent(minute) << consts::TIME_SEPARATOR;
        ss << formatTimeStampComponent(second) << consts::TIME_SEPARATOR;
        ss << formatMillisecondComponent(millisecond);
        return ss.str();
    }

    /**
     * @brief Compares two date objects to determine if the current time stamp is earlier than the given time stamp.
     * @param other
     *          The time stamp to compare to.
     * @return @c true if the current time stamp is earlier than the given time stamp, @c false otherwise.
     */
    bool TimeStamp::operator<(const TimeStamp& other) const {
        return DateTimeUtils::toMilliseconds(*this) < DateTimeUtils::toMilliseconds(other);
    }

    /**
     * @brief Compares two date objects to determine if the current time stamp is later than the given time stamp.
     * @param other
     *          The time stamp to compare to.
     * @return @c true if the current time stamp is later than the given time stamp, @c false otherwise.
     */
    bool TimeStamp::operator>(const TimeStamp& other) const {
        return other < *this;
    }

    /**
     * @brief Compares two date objects to determine if the current time stamp is less than or equal to the given time stamp.
     * @param other
     *          The time stamp to compare to.
     * @return @c true if the current time stamp is less than or equal to the given time stamp, @c false otherwise.
     */
    bool TimeStamp::operator<=(const TimeStamp& other) const {
        return !(other < *this);
    }

    /**
     * @brief Compares two date objects to determine if the current time stamp is greater than or equal to the given time stamp.
     * @param other
     *          The time stamp to compare to.
     * @return @c true if the current time stamp is greater than or equal to the given time stamp, @c false otherwise.
     */
    bool TimeStamp::operator>=(const TimeStamp& other) const {
        return !(*this < other);
    }

    /**
     * @brief Compares two date objects to determine if the they are equal.
     * @param other
     *          The time stamp to compare to.
     * @return @c true if the two time stamps are equal, @c false otherwise.
     */
    bool TimeStamp::operator==(const TimeStamp& other) const {
        return DateTimeUtils::toMilliseconds(*this) == DateTimeUtils::toMilliseconds(other);
    }

    /**
     * @brief Compares two date objects to determine if they are not equal.
     * @param other
     *          The time stamp to compare to.
     * @return @c true if the two time stamps are not equal, @c false otherwise.
     */
    bool TimeStamp::operator!=(const TimeStamp& other) const {
        return !(*this == other);
    }

    /**
     * @brief Checks if the time passed is valid.
     * @param h
     *          The hour.
     * @param m
     *          The minute.
     * @param s
     *          The second.
     * @param milli
     *          The millisecond.
     * @return @c true if the time is valid, @c false otherwise.
     */
    bool TimeStamp::isValidTime(int h, int m, int s, int milli) {
        if (h < consts::HOUR_MIN || h > consts::HOUR_MAX) {
            return false;
        }
        if (m < consts::MINUTE_MIN || m > consts::MINUTE_MAX) {
            return false;
        }
        if (s < consts::SECOND_MIN || s > consts::SECOND_MAX) {
            return false;
        }
        if (milli < consts::MILLISECOND_MIN || milli > consts::MILLISECOND_MAX) {
            return false;
        }
        return true;
    }

    /**
     * @brief Adjusts the hour component after hours have been added/subtracted to ensure that it is valid.
     */
    void TimeStamp::adjustHour() {
        if (hour == consts::HOUR_ADJUST) {
            hour = consts::HOUR_MIN;
        } else if (hour > consts::HOUR_ADJUST) {
            hour = consts::HOUR_MIN + (hour - consts::HOUR_ADJUST);
        } else if (hour < consts::HOUR_MIN) {
            hour = consts::HOUR_ADJUST - std::abs(hour);
        }
    }

    /**
     * @brief Adjusts the minute component after minutes have been added/subtracted to ensure that it is valid.
     */
     void TimeStamp::adjustMinute() {
        if (minute == consts::MINUTE_ADJUST) {
            minute = consts::MINUTE_MIN;
            ++hour;
        } else if (minute > consts::MINUTE_ADJUST) {
            minute = consts::MINUTE_MIN + (minute - consts::MINUTE_ADJUST);
            ++hour;
        } else if (minute < consts::MINUTE_MIN) {
            minute = consts::MINUTE_ADJUST - std::abs(minute);
            --hour;
        }
        adjustHour();
    }

    /**
     * @brief Adjusts the second component after seconds have been added/subtracted to ensure that it is valid.
     */
    void TimeStamp::adjustSecond() {
        if (second == consts::SECOND_ADJUST) {
            second = consts::SECOND_MIN;
            ++minute;
        } else if (second > consts::SECOND_ADJUST) {
            second = consts::SECOND_MIN + (second - consts::SECOND_ADJUST);
          ++minute;
        } else if (second < consts::SECOND_MIN) {
            second = consts::SECOND_ADJUST - std::abs(second);
            --minute;
        }
        adjustMinute();
    }

    /**
     * @brief Adjusts the millisecond component after milliseconds have been added/subtracted to ensure that it is valid.
     */
    void TimeStamp::adjustMillisecond() {
        if (millisecond == consts::MILLISECOND_ADJUST) {
            millisecond = consts::MILLISECOND_MIN;
            ++second;
        } else if (millisecond > consts::MILLISECOND_ADJUST) {
            millisecond = consts::MILLISECOND_MIN + (millisecond - consts::MILLISECOND_ADJUST);
            ++second;
        } else if (millisecond < consts::MILLISECOND_MIN) {
            millisecond = consts::MILLISECOND_ADJUST - std::abs(millisecond);
            --second;
        }
        adjustSecond();
    }

    /**
     * @brief Parses a string representation of a time stamp.
     *
     * <b>Note:</b> Time stamp must be in the format: @c HH:MM:SS::MSMSMS. <br>
     * <b>Example:</b> @c dt::TimeStamp time{"01:01:01:001"};
     * @param timeStamp
     *          The string representation of a time stamp to parse.
     * @throws DateParseException
     *          If the string representation of the time stamp doesn't match a certain pattern.
     */
    void TimeStamp::parse(const std::string& timeStamp) {
        static std::string timeStampPattern{"^\\d{2}:\\d{2}:\\d{2}:\\d{3}"};

        if (std::regex regexPattern{timeStampPattern}; std::regex_match(timeStamp, regexPattern)) {
            convertStrToTimeStamp(timeStamp);
            return;
        }
        std::string message{"Error parsing time: '" + timeStamp + "'. Check formatting."};
        throw DateParseException(message);
    }

    /**
     * @brief Extracts the time components from a valid string representation of a time stamp. The hour, minute,
     * second and millisecond components are set if the time is valid.
     * @param timeStamp
     *          The string representation of the time.
     * @throws InvalidTimeException
     *
     */
    void TimeStamp::convertStrToTimeStamp(const std::string& timeStamp) {
        // XX:XX:XX:XXXX
        // 0123456789012
        int h{std::stoi(timeStamp.substr(0, 2))};
        int m{std::stoi(timeStamp.substr(3, 2))};
        int s{std::stoi(timeStamp.substr(6, 2))};
        int ms{std::stoi(timeStamp.substr(9, 4))};

        if (isValidTime(h, m, s, ms)) {
            hour = h;
            minute = m;
            second = s;
            millisecond = ms;
        } else {
            std::string message{"Error parsing time: '" + timeStamp + "'. Time is invalid."};
            throw InvalidTimeException(message);
        }
    }

    /**
     * @brief Formats a time component by adding leading '0' if the component is below 10.
     * @param component
     *          The component to format.
     * @return The formatted component.
     */
    std::string TimeStamp::formatTimeStampComponent(int component) const {
        return (component < 10) ? consts::LEADING_ZERO + std::to_string(component) : std::to_string(component);
    }

    /**
     * @brief Formats the millisecond time component by adding either one of two leading '0' if it is below 10/100.
     * @param millisecondComponent
     *          The millisecond component.
     * @return The formatted millisecond component.
     */
    std::string TimeStamp::formatMillisecondComponent(int millisecondComponent) const {
        if (millisecondComponent < 100) {
            if (millisecondComponent < 10) {
                return "00" + std::to_string(millisecondComponent);
            }
            return consts::LEADING_ZERO + std::to_string(millisecondComponent);
        }
        return std::to_string(millisecondComponent);
    }

    /**
     * @brief Overloaded stream output operator.
     * @param os
     *          The output stream.
     * @param timeStamp
     *          The time stamp object to output.
     * @return The output stream.
     */
    std::ostream& operator<<(std::ostream& os, const TimeStamp& timeStamp) {
        os << timeStamp.toString();
        return os;
    }
}
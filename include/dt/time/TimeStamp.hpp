/**
 * @file TimeStamp.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_TIMESTAMP_HPP
#define DATEANDTIME_LIB_TIMESTAMP_HPP

#include <cstdint>
#include <regex>
#include <sstream>
#include <ostream>

#include "../Constants.hpp"
#include "../utils/DateTimeUtils.hpp"
#include "../exceptions/InvalidTimeException.hpp"
#include "../exceptions/TimeParseException.hpp"

namespace dt {
    /**
     * @brief @c TimeStamp class.
     *
     * This class represents a particular point in time on the 24h clock in the format: @c HH-MM-SS-MSMSMS.
     * @namespace @c dt
     */
    class TimeStamp {
    public:
        TimeStamp() = default;
        TimeStamp(int h, int m, int s, int milli);
        TimeStamp(const std::string& timeStamp);
        ~TimeStamp() = default;

        void addHours(int hours);
        void addMinutes(int minutes);
        void addSeconds(int seconds);
        void addMilliseconds(int milliseconds);

        void setToCurrentTime();
        void setTime(int h, int m, int s, int milli);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        int getMillisecond() const;
        std::string toString() const;

        bool operator<(const TimeStamp& other) const;
        bool operator>(const TimeStamp& other) const;
        bool operator<=(const TimeStamp& other) const;
        bool operator>=(const TimeStamp& other) const;
        bool operator==(const TimeStamp& other) const;
        bool operator!=(const TimeStamp& other) const;
        friend std::ostream& operator<<(std::ostream& os, const TimeStamp& timeStamp);

    private:
        bool isValidTime(int h, int m, int s, int milli);
        void adjustHour();
        void adjustMinute();
        void adjustSecond();
        void adjustMillisecond();
        void parse(const std::string& timeStamp);
        void convertStrToTimeStamp(const std::string& timeStamp);

        std::string formatTimeStampComponent(int component) const;
        std::string formatMillisecondComponent(int millisecondComponent) const;

        int hour{0};
        int minute{0};
        int second{0};
        int millisecond{0};
    };
}

#endif //DATEANDTIME_LIB_TIMESTAMP_HPP

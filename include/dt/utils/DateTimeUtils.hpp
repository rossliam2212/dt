/**
 * @file DateTimeUtils.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 31/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_DATETIMEUTILS_HPP
#define DATEANDTIME_LIB_DATETIMEUTILS_HPP

#include <chrono>
#include <iomanip>

#include "../date/Date.hpp"
#include "../time/TimeStamp.hpp"

namespace dt {
    class Date;
    class TimeStamp;

    /**
     * @brief @c DateTimeUtils class.
     *
     * Contains useful date and time utility functions as well as functions that can be used with the @c Date &
     * @c TimeStamp classes.
     * @namespace @c dt
     */
    class DateTimeUtils {
    public:
        DateTimeUtils() = default;
        ~DateTimeUtils() = default;

        static std::string getDayOfWeek(const std::string& date);
        static int daysBetween(const Date& first, const Date& second);
        static int monthsBetween(const Date& first, const Date& second);
        static int yearsBetween(const Date& first, const Date& second);
        static bool isValidDate(int day, int month, int year);
        static bool isLeapYear(int year);
        static int daysInMonth(int year, int month);
        static int daysInYear(int year);
        static int dayOfYear(const Date& date);
        static int daysToMinutes(int days);
        static long long daysToSeconds(int days);
        static int daysToHours(int days);
        static std::string getMonthShortStr(int month);
        static std::string getMonthLongStr(int month);

        static std::vector<Date> parseDateStrings(const std::vector<std::string>& dates);
        static long long toMilliseconds(const TimeStamp& timeStamp);

        static std::string getCurrentTimeStr();

    private:
        static int daysSinceReferenceDate(const Date& date);
        static int monthsSinceReferenceDate(const Date& date);
        static bool isValidDay(int day, int month, int year);
        static bool isValidMonth(int month);
        static bool isValidYear(int year);
    };
}

#endif //DATEANDTIME_LIB_DATETIMEUTILS_HPP

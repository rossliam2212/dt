/**
 * @file DateTimeUtils.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 31/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/utils/DateTimeUtils.hpp"

namespace dt {
    /**
     * @brief Gets the day of the that corresponds with the date passed.
     *
     * <b>Note:</b> The date must be match ones of the following patterns:
     * <ul>
     *  <li>@c XX-XX-XXXX</li>
     *  <li>@c XX/XX/XXXX</li>
     *  <li>@c XXXX-XX-XX</li>
     *  <li>@c XXXX/XX/XX</li>
     * </ul>
     * @param date
     *          The date, as a string.
     * @return The day of the week that corresponds with the date passed.
     */
    std::string DateTimeUtils::getDayOfWeek(const std::string& date) {
        try {
            Date tmp{date};
            return tmp.getDayOfWeek();
        } catch (const DateParseException& dateParseException) {
            std::cerr << dateParseException.what() << "\n";
        } catch (const InvalidDateException& invalidDateException) {
            std::cerr << invalidDateException.what() << "\n";
        }
        return "";
    }

    /**
     * @brief Gets the number of days between two dates.
     * @param first
     *          The first date.
     * @param second
     *          The second date.
     * @return The number of days between the two dates.
     */
    int DateTimeUtils::daysBetween(const dt::Date& first, const dt::Date& second) {
        int firstNumDays{daysSinceReferenceDate(first)};
        int secondNumDays{daysSinceReferenceDate(second)};

        return std::abs(firstNumDays - secondNumDays);
    }

    /**
     * @brief Gets the number of months between two dates to the nearest month.
     * @param first
     *          The first date.
     * @param second
     *          The second date.
     * @return The number of months between the two dates to the nearest month.
     */
    int DateTimeUtils::monthsBetween(const dt::Date& first, const dt::Date& second) {
        int firstNumMonths{monthsSinceReferenceDate(first)};
        int secondNumMonths{monthsSinceReferenceDate(second)};

        return std::abs(firstNumMonths - secondNumMonths);
    }

    /**
     * @brief Gets the number of years between two dates.
     * @param first
     *          The first date.
     * @param second
     *          The second date.
     * @return The number of years between the two dates.
     */
    int DateTimeUtils::yearsBetween(const dt::Date& first, const dt::Date& second) {
        if (first.getYear() == second.getYear()) {
            return 0;
        } else if (first.getYear() > second.getYear()) {
            return first.getYear() - second.getYear();
        } else {
            return second.getYear() - first.getYear();
        }
    }

    /**
     * @brief Checks if a date is valid.
     * @param day
     *          The day.
     * @param month
     *          The month.
     * @param year
     *          The year.
     * @return @c true if the date is valid, @c false otherwise.
     */
    bool DateTimeUtils::isValidDate(int day, int month, int year) {
        return isValidDay(day, month, year) &&
                isValidMonth(month) &&
                isValidYear(year);
    }

    /**
     * @brief Checks if the year passed is a leap year.
     * @param y
     *          The year to check.
     * @return @c true if the year is a leap year, @c false otherwise.
     */
    bool DateTimeUtils::isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }


    /**
     * @brief Returns the number of days in a given month of a specific year, accounting for leap years.
     * @param y
     *          The year.
     * @param m
     *          The month.
     * @return The number of days in the specified month.
     */
    int DateTimeUtils::daysInMonth(int year, int month) {
        static const std::array<int, 13> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int daysInMonth{days[month]};

        // Handle leap year (February has 29 days)
        if (month == 2 && isLeapYear(year)) {
            daysInMonth = 29;
        }
        return daysInMonth;
    }

    /**
     * @brief Gets the number of days in a given year, accounting for leap years.
     * @param year
     *          The year.
     * @return The number of the days in the year.
     */
    int DateTimeUtils::daysInYear(int year) {
        return isLeapYear(year) ? 366 : 365;
    }

    /**
     * @brief Converts a given number of days to minutes.
     * @param days
     *          The number of days to convert t minutes
     * @return The number of days in minutes.
     */
    int DateTimeUtils::daysToMinutes(int days) {
        return days <= 0 ? 0 : days * 24 * 60;
    }

    /**
     * @brief Converts a given number of days to seconds.
     * @param days
     *          The number of days to convert to seconds.
     * @return The number of days in seconds.
     */
    long long DateTimeUtils::daysToSeconds(int days) {
        return days <= 0 ? 0 : static_cast<long long>(days) * 24 * 60 * 60;
    }

    /**
     * @brief Converts a given number of days to hours.
     * @param days
     *          The number of days to convert to hours.
     * @return The number of days in hours.
     */
    int DateTimeUtils::daysToHours(int days) {
        return days <= 0 ? 0 : days * 24;
    }

    /**
     * @brief Gets the short hand version of a month as a string.
     * @param month
     *          The month.
     * @return The short hand version of the month as a string.
     */
    std::string DateTimeUtils::getMonthShortStr(int month) {
        switch (month) {
            case 1:
                return "Jan";
            case 2:
                return "Feb";
            case 3:
                return "Mar";
            case 4:
                return "Apr";
            case 5:
                return "May";
            case 6:
                return "Jun";
            case 7:
                return "Jul";
            case 8:
                return "Aug";
            case 9:
                return "Sep";
            case 10:
                return "Oct";
            case 11:
                return "Nov";
            case 12:
                return "Dec";
        }
    }

    /**
     * @brief Gets the month as a string.
     * @param month
     *          The month.
     * @return The month as a string.
     */
    std::string DateTimeUtils::getMonthLongStr(int month) {
        switch (month) {
            case 1:
                return "January";
            case 2:
                return "February";
            case 3:
                return "March";
            case 4:
                return "April";
            case 5:
                return "May";
            case 6:
                return "June";
            case 7:
                return "July";
            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12:
                return "December";
        }
    }

    /**
     * @brief Gets the day of the year for the given date.
     * @param date
     *          The date to get the day of the year for.
     * @return The day of the year.
     */
    int DateTimeUtils::dayOfYear(const dt::Date& date) {
        int dayOfYear{date.getDay()};
        for (int i{1}; i < date.getMonth(); ++i) {
            dayOfYear += daysInMonth(date.getYear(), i);
        }
        return dayOfYear;
    }

    /**
     * @brief Parses a vector of string representations of dates to a vector of date objects.
     * @param dates
     *          The vector of strings.
     * @return A vector of dates.
     */
    std::vector<Date> DateTimeUtils::parseDateStrings(const std::vector<std::string>& dates) {
        std::vector<Date> result;
        result.reserve(dates.size());

        for (const auto& d : dates) {
            try {
                result.emplace_back(d);
            } catch (const DateParseException& ex) {
                std::cerr << ex.what() << "\n";
            } catch (...) {
                std::cerr << "Error parsing date: Unknown exception\n";
            }
        }
        return result;
    }

    /**
     * @brief Converts a time stamp to milliseconds.
     * @param timeStamp
     *          The time stamp to convert.
     * @return The time stamp as milliseconds.
     */
    long long DateTimeUtils::toMilliseconds(const dt::TimeStamp& timeStamp) {
        long long totalMilliseconds = timeStamp.getMillisecond();
        totalMilliseconds += static_cast<long long>(timeStamp.getSecond()) * 1000;
        totalMilliseconds += static_cast<long long>(timeStamp.getMinute()) * 60 * 1000;
        totalMilliseconds += static_cast<long long>(timeStamp.getHour()) * 60 * 60 * 1000;
        return totalMilliseconds;
    }

    /**
     * @brief Gets the current time as a string.
     * @return The current time as a string.
     */
    std::string DateTimeUtils::getCurrentTimeStr() {
        static const std::string pattern{"%H:%M:%S:"};

        std::stringstream ss;
        std::chrono::system_clock::time_point now{std::chrono::system_clock::now()};
        std::time_t now_c{std::chrono::system_clock::to_time_t(now)};
        const std::tm* timePtr{std::localtime(&now_c)};
        ss << std::put_time(timePtr, pattern.c_str());

        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;
        ss << std::setfill('0') << std::setw(3) << milliseconds;

        return ss.str();
    }

    /**
     * @brief Calculates the number of days between a given date and a reference date: @c 01-01-1583.
     * @param date
     *          The date to calculate from.
     * @return The number of days between the given date and the reference date.
     */
    int DateTimeUtils::daysSinceReferenceDate(const dt::Date& date) {
        static const Date referenceDate{1, 1, 1583};
        int days{0};

        for (int i{referenceDate.getYear()}; i < date.getYear(); ++i) {
            days += daysInYear(i);
        }
        days += dayOfYear(date) - dayOfYear(referenceDate);
        return days;
    }

    /**
     * @brief Calculates the number of months between a given date and a reference date: @c 01-01-1583.
     * @param date
     *          The date to calculate from.
     * @return The number of months between the given date and the reference date.
     */
    int DateTimeUtils::monthsSinceReferenceDate(const dt::Date& date) {
        static const Date referenceDate{1, 1, 1583};
        int months{0};

        for (int i{referenceDate.getYear()}; i < date.getYear(); ++i) {
            months += 12;
        }
        months += date.getMonth() - referenceDate.getMonth();
        return months;
    }

    /**
     * @brief Checks if a day is valid based on the month and year.
     * @param day
     *          The day to check.
     * @param month
     *          The month.
     * @param year
     *          The year.
     * @return @c true if the day is valid, @c false otherwise.
     */
    bool DateTimeUtils::isValidDay(int day, int month, int year) {
        // TODO Add Unit Test
        int daysInMonth{consts::MAX_NUMBER_DAYS_IN_A_MONTH};
        if (month == (int)consts::Month::April || month == (int)consts::Month::June ||
            month == (int)consts::Month::September || month == (int)consts::Month::November) {
            daysInMonth = 30;
        } else if (month == (int)consts::Month::February) {
            daysInMonth = isLeapYear(year) ? consts::FEBRUARY_LEAP_YEAR_DAYS : consts::FEBRUARY_LEAP_YEAR_DAYS - 1;
        }

        if (day < 1 || day > daysInMonth) {
            return false;
        }
        return true;
    }

    /**
     * @brief Checks if a month is valid.
     * @param month
     *          The month to check.
     * @return @c true if the month is valid, @c false otherwise.
     */
    bool DateTimeUtils::isValidMonth(int month) {
        return month >= (int)consts::Month::January && month <= (int)consts::Month::December;
    }

    /**
     * @brief Checks if a year is valid.
     * @param year
     *          The year to check.
     * @return @c true if the year is valid, @c false otherwise.
     */
    bool DateTimeUtils::isValidYear(int year) {
        return year >= consts::MIN_YEAR && year <= consts::MAX_YEAR;
    }
}
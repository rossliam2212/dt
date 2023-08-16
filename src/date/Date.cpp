/**
 * @file Date.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/date/Date.hpp"

namespace dt {
    const std::array<std::string, consts::DATE_PATTERNS> Date::datePatterns {
        "^\\d{4}-\\d{2}-\\d{2}$", // XXXX-XX-XX
        "^\\d{2}-\\d{2}-\\d{4}$", // XX-XX-XXXX
        "^\\d{4}/\\d{2}/\\d{2}$", // XXXX/XX/XX
        "^\\d{2}/\\d{2}/\\d{4}$", // XX/XX/XXXX
    };

    /**
     * @brief @c Date constructor.
     * @param d
     *          The day.
     * @param m
     *          The month.
     * @param y
     *          The year.
     */
    Date::Date(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
            leapYear = DateTimeUtils::isLeapYear(y);
        }
    }

    /**
     * @brief @c Date constructor.
     * @param date
     *          The string representation of a date to parse.
     */
    Date::Date(const std::string& date) {
        parse(date);
    }

    /**
     * @brief Parses a string representation of a date.
     *
     * Date formats:
     * <ul>
     *  <li>DD-MM-YYYY</li>
     *  <li>DD/MM/YYYY</li>
     *  <li>YYYY-MM-DD</li>
     *  <li>YYYY/MM/DD</li>
     *  <li>MM-DD-YYYY</li>
     *  <li>MM/DD/YYYY</li>
     * </ul>
     * @param date
     *          The string representation of a date to parse.
     * @throws DateParseException
     *          If the string representation of the date doesn't match a certain pattern.
     */
    void Date::parse(const std::string& date) {
        for (const auto& pattern : datePatterns) {
            std::regex regexPattern{pattern};
            if (std::regex_match(date, regexPattern)) {
                convertStrToDate(pattern, date);
                return;
            }
        }
        std::string message{"Error parsing date: '" + date + "'. Check formatting."};
        throw DateParseException(message);
    }

    /**
     * @brief Adds a specified number of days to the date.
     * @param days
     *          The number of days to add.
     */
    void Date::addDays(int days) {
        day += days;
        adjustDate();
    }

    /**
     * @brief Adds a specified number of months to the date.
     * @param months
     *          The number of months to add.
     */
    void Date::addMonths(int months) {
        month += months;
        adjustDate();
    }

    /**
     * @brief Adds a specified number of years to the date.
     * @param years
     *          The number of years to add.
     */
    void Date::addYears(int years) {
        year += years;
        adjustDate();
    }

    /**
     * @brief Sets the date to a new date.
     * @param d
     *          The day.
     * @param m
     *          The month.
     * @param y
     *          The year.
     * @throws InvalidDateException
     *          if the date is invalid.
     */
    void Date::setDate(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
            leapYear = DateTimeUtils::isLeapYear(y);
        } else {
            throw InvalidDateException("Invalid year set. Check formatting.");
        }
    }

    /**
     * @brief Gets the day.
     * @return The day.
     */
    int Date::getDay() const {
        return day;
    }

    /**
     * @brief Gets the month.
     * @return The month.
     */
    int Date::getMonth() const {
        return month;
    }

    /**
     * @brief Gets the year.
     * @return The year.
     */
    int Date::getYear() const {
        return year;
    }

    /**
     * @brief Gets the day of the week that the date corresponds to.
     * @return The day of the week.
     */
    std::string Date::getDayOfWeek() const {
        int q{day};
        int m{month};
        int Y{month < 3 ? year - 1 : year};

        if (m < 3) {
            m += 12;
        }

        int K{Y % 100};
        int J{Y / 100};

        int h{(q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7};

        return getDayOfWeek((h + 5) % 7);
    }

    /**
     * @brief Checks if the year is a leap year.
     * @return @c true if the year is a leap year, @c false otherwise.
     */
    bool Date::isLeapYear() const {
        return leapYear;
    }

    /**
     * @brief Converts the date to a string.
     * @return The date as a string.
     */
    std::string Date::toString() const {
        std::stringstream ss;

        ss << addLeadingZerosToDateComponent(day) << consts::DATE_SEPARATOR_DASH;
        ss << addLeadingZerosToDateComponent(month) << consts::DATE_SEPARATOR_DASH;
        ss << year;

        return ss.str();
    }

    /**
     * @brief Compares two date objects to determine if the current date is earlier than the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is earlier than the given date, @c false otherwise.
     */
    bool Date::operator<(const dt::Date& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }

    /**
     * @brief Compares two date objects to determine if the current date is later than the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is later than the given date, @c false otherwise.
     */
    bool Date::operator>(const dt::Date& other) const {
        return other < *this;
    }

    /**
     * @brief Compares two date objects to determine if the current date is less than or equal to the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is less than or equal to the given date, @c false otherwise.
     */
    bool Date::operator<=(const Date& other) const {
        return !(other < *this);
    }

    /**
     * @brief Compares two date objects to determine if the current date is greater than or equal to the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is greater than or equal to the given date, @c false otherwise.
     */
    bool Date::operator>=(const Date& other) const {
        return !(*this < other);
    }

    /**
     * @brief Compares two date objects to determine if they are equal.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the dates are equal, @c false otherwise.
     */
    bool Date::operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    /**
     * @brief Compares two date objects to determine if they are not equal.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the dates are not equal, @c false otherwise.
     */
    bool Date::operator!=(const Date& other) const {
        return !(*this == other);
    }

    /**
     * @brief Checks if the date passed is valid.
     * @param d
     *          The day.
     * @param m
     *          The month.
     * @param y
     *          The year.
     * @return @c true if the date is valid, @c false otherwise.
     */
    bool Date::isValidDate(int d, int m, int y) {
        return DateTimeUtils::isValidDate(d, m, y);
    }


    /**
     * @brief Adjusts the date to ensure that the day, month, and year components are valid and represent a valid date.
     */
    void Date::adjustDate() {
        if (month == consts::MONTHS_ADJUST_UPPER) {
            month = consts::MIN_NUMBER_OF_MONTHS;
            ++year;
        } else if (month > consts::MONTHS_ADJUST_UPPER) {
            month = consts::MIN_NUMBER_OF_MONTHS + (month - consts::MONTHS_ADJUST_UPPER);
            ++year;
        }

        if (month == consts::MONTHS_ADJUST_LOWER) {
            month = consts::MAX_NUMBER_OF_MONTHS;
            --year;
        } else {
            while (month < consts::MONTHS_ADJUST_LOWER) {
                month = consts::MAX_NUMBER_OF_MONTHS - (std::abs(month));
                --year;
            }
        }

        while (day > DateTimeUtils::daysInMonth(year, month)) {
            day -= DateTimeUtils::daysInMonth(year, month);
            ++month;
            if (month > consts::MAX_NUMBER_OF_MONTHS) {
                month = consts::MIN_NUMBER_OF_MONTHS;
                ++year;
            }
        }

        while (day < consts::MIN_NUMBER_OF_MONTHS) {
            --month;
            if (month < consts::MIN_NUMBER_OF_MONTHS) {
                month = consts::MAX_NUMBER_OF_MONTHS;
                --year;
            }
            day += DateTimeUtils::daysInMonth(year, month);
        }
    }

    /**
     * @brief Formats a date component by adding a leading '0' if the component is below 10.
     * @param component
     *          The date component to format, e.g. day, month.
     * @return The formatted component.
     */
    std::string Date::addLeadingZerosToDateComponent(int component) const {
        return (component < 10) ? consts::LEADING_ZERO + std::to_string(component) : std::to_string(component);
    }

    /**
     * @brief Extracts the date components from a valid string representation of a date. The day, month, year
     * components are set if the date is valid.
     * @param pattern
     *          The date pattern.
     * @param date
     *          The string representation of the date.
     * @throws InvalidDateException
     *          If the date is invalid.
     */
    void Date::convertStrToDate(std::string_view pattern, const std::string& date) {
        // XXXX-XX-XX
        if (pattern == datePatterns.at(0) || pattern == datePatterns.at(2)) {
            int y{std::stoi(date.substr(0, 4))}; // Start (Year)
            int tmp1{std::stoi(date.substr(5, 2))}; // Middle (Day/Month)
            int tmp2{std::stoi(date.substr(8, 2))}; // End (Day/Month)

            if (isValidDate(tmp1, tmp2, y)) {
                day = tmp1;
                month = tmp2;
                year = y;
                leapYear = DateTimeUtils::isLeapYear(y);
            } else if (isValidDate(tmp2, tmp1, y)) {
                day = tmp2;
                month = tmp1;
                year = y;
                leapYear = DateTimeUtils::isLeapYear(y);
            } else {
                std::string message{"Error parsing date: '" + date + "'. Date is invalid."};
                throw InvalidDateException(message);
            }
        }
        // XX-XX-XXXX
        else {
            int tmp1{std::stoi(date.substr(0, 2))}; // Start (Day/Month)
            int tmp2{std::stoi(date.substr(3, 2))}; // Middle (Day/Month)
            int y{std::stoi(date.substr(6, 4))}; // End (Year)

            if (isValidDate(tmp1, tmp2, y)) {
                day = tmp1;
                month = tmp2;
                year = y;
                leapYear = DateTimeUtils::isLeapYear(y);
            } else if (isValidDate(tmp2, tmp1, y)) {
                day = tmp2;
                month = tmp1;
                year = y;
                leapYear = DateTimeUtils::isLeapYear(y);
            } else {
                std::string message{"Error parsing date: '" + date + "'. Date is invalid."};
                throw InvalidDateException(message);
            }
        }
    }

    /**
     * @brief Gets the day of the week that the date corresponds to as a string.
     * @param d
     *          The day of the week integer representation.
     * @return The day of the way as a string.
     */
    std::string Date::getDayOfWeek(int d) const {
        switch (d) {
            default:
                return consts::MONDAY;
            case 1:
                return consts::TUESDAY;
            case 2:
                return consts::WEDNESDAY;
            case 3:
                return consts::THURSDAY;
            case 4:
                return consts::FRIDAY;
            case 5:
                return consts::SATURDAY;
            case 6:
                return consts::SUNDAY;
        }
    }

    /**
     * @brief Overloaded stream output operator.
     * @param os
     *          The output stream.
     * @param date
     *          The date object to output.
     * @return The output stream.
     */
    std::ostream& operator<<(std::ostream& os, const dt::Date& date) {
        os << date.toString();
        return os;
    }
}
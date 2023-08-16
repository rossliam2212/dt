/**
 * @file FormattedDate.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 02/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/date/FormattedDate.hpp"

namespace dt {
    /**
     * @brief @c FormattedDate constructor.
     * @param d
     *          The day.
     * @param m
     *          The month.
     * @param y
     *          The year.
     * @param format
     *          The date format.
     */
    FormattedDate::FormattedDate(int d, int m, int y, DateFormat format)
        : date{d, m, y},
          format{format} {
    }

    /**
     * @brief @c FormattedDate constructor.
     * @param date
     *          The string representation of a date to parse.
     * @param format
     *          The date format.
     */
    FormattedDate::FormattedDate(const std::string& date, DateFormat format)
        : date{date},
          format{format} {
    }

    /**
     * @brief @c FormattedDate constructor.
     * @param date
     *          The date.
     * @param format
     *          The date format.
     */
    FormattedDate::FormattedDate(const dt::Date& date, DateFormat format)
        : date{date},
          format{format} {
    }

    /**
     * @brief Adds a specified number of days to the date.
     * @param days
     *          The number of days to add.
     */
    void FormattedDate::addDays(int days) {
        date.addDays(days);
    }

    /**
     * @brief Adds a specified number of months to the date.
     * @param days
     *          The number of months to add.
     */
    void FormattedDate::addMonths(int months) {
        date.addMonths(months);
    }

    /**
     * @brief Adds a specified number of years to the date.
     * @param days
     *          The number of years to add.
     */
    void FormattedDate::addYears(int years) {
        date.addYears(years);
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
    void FormattedDate::setDate(int d, int m, int y) {
        date.setDate(d, m, y);
    }

    /**
     * @brief Gets the day.
     * @return The day.
     */
    int FormattedDate::getDay() const {
        return date.getDay();
    }

    /**
     * @brief Gets the month.
     * @return The month.
     */
    int FormattedDate::getMonth() const {
        return date.getMonth();
    }

    /**
     * @brief Gets the year.
     * @return The year.
     */
    int FormattedDate::getYear() const {
        return date.getYear();
    }

    /**
     * @brief Gets the day of the week that the date corresponds to.
     * @return The day of the week.
     */
    std::string FormattedDate::getDayOfWeek() {
        return date.getDayOfWeek();
    }

    /**
     * @brief Checks if the year is a leap year.
     * @return @c true if the year is a leap year, @c false otherwise.
     */
    bool FormattedDate::isLeapYear() const {
        return date.isLeapYear();
    }

    /**
     * @brief Converts the date to a string.
     * @return The date as a string.
     */
    std::string FormattedDate::toString() const {
        std::stringstream ss;
        switch (format) {
            case DateFormat::DD_MM_YYYY:
                ss << addLeadingZerosToDateComponent(date.getDay()) << consts::DATE_SEPARATOR_DASH;
                ss << addLeadingZerosToDateComponent(date.getMonth()) << consts::DATE_SEPARATOR_DASH;
                ss << date.getYear();
                break;
            case DateFormat::MM_DD_YYYY:
                ss << addLeadingZerosToDateComponent(date.getMonth()) << consts::DATE_SEPARATOR_DASH;
                ss << addLeadingZerosToDateComponent(date.getDay()) << consts::DATE_SEPARATOR_DASH;
                ss << date.getYear();
                break;
            case DateFormat::YYYY_MM_DD:
                ss << date.getYear() << consts::DATE_SEPARATOR_DASH;
                ss << addLeadingZerosToDateComponent(date.getMonth()) << consts::DATE_SEPARATOR_DASH;
                ss << addLeadingZerosToDateComponent(date.getDay());
                break;
            case DateFormat::YYYY_DD_MM:
                ss << date.getYear() << consts::DATE_SEPARATOR_DASH;
                ss << addLeadingZerosToDateComponent(date.getDay()) << consts::DATE_SEPARATOR_DASH;
                ss << addLeadingZerosToDateComponent(date.getMonth());
                break;
            case DateFormat::DD__MM__YYYY:
                ss << addLeadingZerosToDateComponent(date.getDay()) << consts::DATE_SEPARATOR_SLASH;
                ss << addLeadingZerosToDateComponent(date.getMonth()) << consts::DATE_SEPARATOR_SLASH;
                ss << date.getYear();
                break;
            case DateFormat::MM__DD__YYYY:
                ss << addLeadingZerosToDateComponent(date.getMonth()) << consts::DATE_SEPARATOR_SLASH;
                ss << addLeadingZerosToDateComponent(date.getDay()) << consts::DATE_SEPARATOR_SLASH;
                ss << date.getYear();
                break;
            case DateFormat::YYYY__MM__DD:
                ss << date.getYear() << consts::DATE_SEPARATOR_SLASH;
                ss << addLeadingZerosToDateComponent(date.getMonth()) << consts::DATE_SEPARATOR_SLASH;
                ss << addLeadingZerosToDateComponent(date.getDay());
                break;
            case DateFormat::YYYY__DD__MM:
                ss << date.getYear() << consts::DATE_SEPARATOR_SLASH;
                ss << addLeadingZerosToDateComponent(date.getDay()) << consts::DATE_SEPARATOR_SLASH;
                ss << addLeadingZerosToDateComponent(date.getMonth());
                break;
        }
        return ss.str();
    }

    /**
     * @brief Compares two date objects to determine if the current date is earlier than the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is earlier than the given date, @c false otherwise.
     */
    bool FormattedDate::operator<(const FormattedDate& other) const {
        return date < other.date;
    }

    /**
     * @brief Compares two date objects to determine if the current date is later than the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is later than the given date, @c false otherwise.
     */
    bool FormattedDate::operator>(const FormattedDate& other) const {
        return other < *this;
    }

    /**
     * @brief Compares two date objects to determine if the current date is less than or equal to the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is less than or equal to the given date, @c false otherwise.
     */
    bool FormattedDate::operator<=(const FormattedDate& other) const {
        return !(other < *this);
    }

    /**
     * @brief Compares two date objects to determine if the current date is greater than or equal to the given date.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the current date is greater than or equal to the given date, @c false otherwise.
     */
    bool FormattedDate::operator>=(const FormattedDate& other) const {
        return !(*this < other);
    }

    /**
     * @brief Compares two date objects to determine if they are equal.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the dates are equal, @c false otherwise.
     */
    bool FormattedDate::operator==(const FormattedDate& other) const {
        return date == other.date;
    }

    /**
     * @brief Compares two date objects to determine if they are not equal.
     *
     * @param other
     *          The date to compare against.
     * @return @c true if the dates are not equal, @c false otherwise.
     */
    bool FormattedDate::operator!=(const FormattedDate& other) const {
        return !(*this == other);
    }

    /**
     * @brief Formats a date component by adding a leading '0' if the component is below 10.
     * @param component
     *          The date component to format, e.g. day, month.
     * @return The formatted component.
     */
    std::string FormattedDate::addLeadingZerosToDateComponent(int component) const {
        return (component < 10) ? consts::LEADING_ZERO + std::to_string(component) : std::to_string(component);
    }

    /**
     * @brief Overloaded stream output operator.
     * @param os
     *          The output stream.
     * @param date
     *          The date object to output.
     * @return The output stream.
     */
    std::ostream& operator<<(std::ostream& os, const FormattedDate& date) {
        os << date.toString();
        return os;
    }
}